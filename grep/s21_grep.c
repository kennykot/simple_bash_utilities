//  Copyright 2022 <Anton Tuzov>
#include "s21_grep.h"

int main(int argc, char *argv[]) {
    flags f = {0};
    get_flags(argc, argv, &f);
    int templates_size = 0;
    char **templates = NULL;
    templates = get_templates(&templates_size, argv, argc, f);
    int file_names_size = 0;
    char **file_names = NULL;
    file_names = get_file_names(&file_names_size, argv, argc, f, templates);
    s21_grep(file_names, file_names_size, templates, templates_size, f);
    free(templates);
    free(file_names);
    return 0;
}

void s21_grep(char **file_names, int file_names_size, char **templates, int templates_size, flags f) {
    regex_t *regex = calloc(templates_size, sizeof(regex_t));
    int reti;
    reti = get_reg_exp(regex, templates, templates_size, f);
    if (reti == templates_size) {
        for (int i = 0; i < file_names_size; i++) {
            FILE *fp = fopen(file_names[i], "r+");
            if (!feof(fp)) {
                char file_str[256];
                char* tmp_1 = NULL;
                int line_counter = 0;
                int str_num = 1;
                tmp_1 = fgets(file_str, BUZZ_SIZE, fp);
                while (tmp_1 != NULL) {
                    int reg_exec_count = 0;
                    for (int j = 0; j < reti; j++) {
                        reg_exec_count += regexec(&regex[j], file_str, 0, NULL, 0);
                    }
                    if (reg_exec_count < reti && f.reverse_search == 0) {
                        line_counter++;
                        if (f.file_name_only == 1) {
                            if (f.line_count_only == 1) {
                                if (file_names_size > 1) printf("%s:", file_names[i]);
                                printf("%d\n", line_counter);
                            }
                            printf("%s\n", file_names[i]);
                            tmp_1 = NULL;
                            continue;
                        }
                        if (f.line_count_only == 0) {
                            if (file_names_size > 1) printf("%s:", file_names[i]);
                            if (f.prin_str_num == 1) printf("%d:", str_num);
                            if (file_str[strlen(file_str) - 1] != '\n') {
                                printf("%s\n", file_str);
                            } else {
                                printf("%s", file_str);
                            }
                        }
                    }
                    if (reg_exec_count == reti && f.reverse_search == 1) {
                        line_counter++;
                        if (f.file_name_only == 1) {
                            if (f.line_count_only == 1) {
                                if (file_names_size > 1) printf("%s:", file_names[i]);
                                printf("%d\n", line_counter);
                            }
                            printf("%s\n", file_names[i]);
                            tmp_1 = NULL;
                            continue;
                        }
                        if (f.line_count_only == 0) {
                            if (file_names_size > 1) printf("%s:", file_names[i]);
                            if (f.prin_str_num == 1) printf("%d:", str_num);
                            if (file_str[strlen(file_str) - 1] != '\n') {
                                printf("%s\n", file_str);
                            } else {
                                printf("%s", file_str);
                            }
                        }
                    }
                    str_num++;
                    tmp_1 = fgets(file_str, BUZZ_SIZE, fp);
                }
                if (f.line_count_only == 1 && f.file_name_only == 0) {
                    if (file_names_size > 1) printf("%s:", file_names[i]);
                    printf("%d\n", line_counter);
                }
                fclose(fp);
            } else {
                printf("file %s does not exist\n", file_names[i]);
            }
        }
    }
    for (int r = 0; r < reti; r++) regfree(&regex[r]);
    free(regex);
}

int get_reg_exp(regex_t *regex, char **templates, int templates_size, flags f) {
    int success_compiled = 0;
    int flag = 0;
    if (f.ignore_reg == 1) flag = REG_ICASE;
    for (int i = 0; i < templates_size; i++) {
        int reti = regcomp(&regex[i], templates[i], flag);
        if (!reti) {
            success_compiled++;
        } else {
            break;
        }
    }
    return success_compiled;
}

char** get_templates(int *templates_size, char *argv[], int argc, flags f) {
    char** new_templates = calloc(argc - 2, sizeof(char*));
    for (int files = 1; files < argc; files++) {
        if (f.templ == 1 && strcmp(argv[files - 1], "-e") == 0) {
            new_templates[*templates_size] = argv[files];
            *templates_size += 1;
        } else if (f.templ == 0 && *templates_size == 0 && argv[files][0] != '-') {
            new_templates[*templates_size] = argv[files];
            *templates_size += 1;
        }
    }
    return new_templates;
}

char** get_file_names(int *file_names_size, char *argv[], int argc, flags f, char **templates) {
    char** new_file_names = calloc(argc - 2, sizeof(char*));
    int cnt = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' && strcmp(argv[i - 1], "-e") != 0) {
            if (cnt == 0 && f.templ == 0 && strcmp(argv[i], templates[0]) == 0) {
                cnt++;
                continue;
            }
            new_file_names[*file_names_size] = argv[i];
            *file_names_size += 1;
        }
    }
    return new_file_names;
}

void get_flags(int argc, char *argv[], flags *f) {
    char e_flag[3] = "-e";
    char i_flag[3] = "-i";
    char v_flag[3] = "-v";
    char l_flag[3] = "-l";
    char n_flag[3] = "-n";
    char c_flag[3] = "-c";
    for (int i = 1; i < argc - 1; i++) {
        if (strcmp(argv[i], e_flag) == 0) {
            f->templ = 1;
        } else if (strcmp(argv[i], i_flag) == 0) {
            f->ignore_reg = 1;
        } else if (strcmp(argv[i], v_flag) == 0) {
            f->reverse_search = 1;
        } else if (strcmp(argv[i], l_flag) == 0) {
            f->file_name_only = 1;
        } else if (strcmp(argv[i], n_flag) == 0) {
            f->prin_str_num = 1;
        } else if (strcmp(argv[i], c_flag) == 0) {
            f->line_count_only = 1;
        }
    }
}
