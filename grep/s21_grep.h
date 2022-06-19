#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#define BUZZ_SIZE 256
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>

typedef struct {
    int templ;              //  -e
    int ignore_reg;         //  -i
    int reverse_search;     //  -v
    int line_count_only;    //  -c
    int file_name_only;     //  -l
    int prin_str_num;       //  -n
} flags;

void get_flags(int argc, char *argv[], flags *f);
char** get_templates(int *templates_size, char *argv[], int argc, flags f);
char** get_file_names(int *files_size, char *argv[], int argc, flags f, char **templates);
void s21_grep(char **file_names, int file_names_size, char **templates, int templates_size, flags f);
int get_reg_exp(regex_t *regex, char **templates, int templates_size, flags f);

#endif  //  SRC_GREP_S21_GREP_H_
