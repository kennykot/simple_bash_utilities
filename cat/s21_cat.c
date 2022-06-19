//  Copyright 2022 jewfishc
#include "s21_cat.h"

int main(int argc, const char* argv[]) {
    int number = 0;
    char name_of_file[256] = {0};
    flags f = {0};
    get_flags(argc, argv, &f);
    for (int files = 1; files < argc; files++) {
        memset(name_of_file, 0, 255);
        if (argv[files][0] != '-') {
            memcpy(name_of_file, argv[files], strlen(argv[files]));
            open_file(f, name_of_file, &number);
        }
    }
    return 0;
}

void get_flags(int argc, const char* argv[], flags* f) {
    char b_flag[20];
    char e_flag[20];
    char n_flag[20];
    char s_flag[20];
    char t_flag[20];
    char v_flag[20];
    memset(b_flag, 0, 20);
    memset(e_flag, 0, 20);
    memset(n_flag, 0, 20);
    memset(s_flag, 0, 20);
    memset(t_flag, 0, 20);
    memset(v_flag, 0, 20);
    #if defined(__GNU__)
        memcpy(b_flag, "--number-nonblank", 17);
        memcpy(e_flag, "-E", 2);
        memcpy(n_flag, "--number", 8);
        memcpy(s_flag, "--squeeze-blank", 15);
        memcpy(t_flag, "-T", 2);
    #else
        memcpy(b_flag, "-b", 2);
        memcpy(e_flag, "-e", 2);
        memcpy(n_flag, "-n", 2);
        memcpy(s_flag, "-s", 2);
        memcpy(t_flag, "-t", 2);
        memcpy(v_flag, "-v", 2);
    #endif
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], b_flag) == 0) {
            f->set_nums = 1;
        } else if (strcmp(argv[i], e_flag) == 0) {
            f->change_ends = 1;
        } else if (strcmp(argv[i], n_flag) == 0) {
            f->set_empty_nums = 1;
        } else if (strcmp(argv[i], s_flag) == 0) {
            f->compress_str = 1;
        } else if (strcmp(argv[i], t_flag) == 0) {
            f->change_tabs = 1;
        } else if (strcmp(argv[i], v_flag) == 0) {
            f->change_all = 1;
        }
    }
}

void open_file(flags f, char* name, int* number) {
    FILE *stream = fopen(name, "r+");
    if (stream) {
        cat_file(f, stream, number);
        fclose(stream);
    } else {
        printf("File %s does not exist.\n", name);
    }
}

void cat_file(flags f, FILE* stream, int* number) {
    char sym;
    int find_NL = 0;
    sym = fgetc(stream);
    while (!feof(stream)) {
        if (f.set_nums == 1 && sym  != '\n') {
            printf("%6d\t", ++*number);
        } else if (f.set_empty_nums == 1 && f.set_nums == 0) {
            printf("%6d\t", ++*number);
        }
        while (sym != '\n' && !feof(stream)) {
            if (f.change_tabs == 1 && sym == 9) {
                printf("^I");
            } else if ((f.change_tabs == 1 || f.change_ends == 1 || f.change_all == 1) && ((sym >= 1
                && sym <= 8) || (sym >= 10 && sym <= 31) || sym == 127)) {
                if (sym == 127) {
                    printf("^?");
                } else {
                    printf("^%c", sym + 64);
                }
            } else {
                printf("%c", sym);
            }
            sym = fgetc(stream);
        }
        if (!feof(stream) && ((f.compress_str == 1 && find_NL <= 1) ||
            (f.change_ends != 1 && f.compress_str != 1) ||
            (f.compress_str != 1 && f.change_ends == 1 && sym == '\n'))) {
            if (f.change_ends == 1 && sym == '\n') {
                printf("$");
            }
            printf("%c", sym);
        }
        if (!feof(stream) && (f.change_ends != 1 || sym == '\n')) {
            sym = fgetc(stream);
        }
        if (!feof(stream) && f.compress_str == 1 && sym != '\n') {
            find_NL = 0;
        } else if (!feof(stream) && f.compress_str == 1) {
            find_NL++;
        }
    }
}
