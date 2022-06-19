//  Copyright 2022 <Anton Tuzov>
#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int set_nums;            //  -b
    int change_ends;         //  -e
    int set_empty_nums;      //  -n
    int compress_str;        //  -s
    int change_tabs;         //  -t
    int change_all;          //  -v
} flags;

void get_flags(int argc, const char* argv[], flags* f);
void open_file(flags f, char* name, int* i);
void cat_file(flags f, FILE* stream, int* i);

#endif  //  SRC_CAT_S21_CAT_H_
