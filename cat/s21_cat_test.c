//  Copyright 2022 jewfishc
#include "./s21_cat.h"

int main(void) {
    fclose(fopen("./_cat_test_s21.txt", "r+"));
    fclose(fopen("./_cat_test_orig.txt", "r+"));
    fclose(fopen("./_cat_test_result.txt", "r+"));

    system(
        "echo \"\nNO FLAGS\" | tee -a _cat_test_s21.txt && "
        "./s21_cat bytes.txt >> _cat_test_s21.txt && "
        "echo \"\nNO FLAGS\" | tee -a _cat_test_orig.txt && "
        "cat bytes.txt >> _cat_test_orig.txt && "
        "echo \"\nNO FLAGS\" | tee -a _cat_test_result.txt && "
        "diff -s _cat_test_s21.txt _cat_test_orig.txt >> "
        "_cat_test_result.txt");

    system(
        "echo \"\nFLAG B\" | tee -a _cat_test_s21.txt && "
        "./s21_cat -b bytes.txt >> _cat_test_s21.txt && "
        "echo \"\nFLAG B\" | tee -a _cat_test_orig.txt && "
        "cat -b bytes.txt >> _cat_test_orig.txt && "
        "echo \"\nFLAG B\" | tee -a _cat_test_result.txt && "
        "diff -s _cat_test_s21.txt _cat_test_orig.txt >> "
        "_cat_test_result.txt");

    system(
        "echo \"\nFLAG E\" | tee -a _cat_test_s21.txt && "
        "./s21_cat -b bytes.txt >> _cat_test_s21.txt && "
        "echo \"\nFLAG E\" | tee -a _cat_test_orig.txt && "
        "cat -b bytes.txt >> _cat_test_orig.txt && "
        "echo \"\nFLAG E\" | tee -a _cat_test_result.txt && "
        "diff -s _cat_test_s21.txt _cat_test_orig.txt >> "
        "_cat_test_result.txt");

    system(
        "echo \"\nFLAG N\" | tee -a _cat_test_s21.txt && "
        "./s21_cat -b bytes.txt >> _cat_test_s21.txt && "
        "echo \"\nFLAG N\" | tee -a _cat_test_orig.txt && "
        "cat -b bytes.txt >> _cat_test_orig.txt && "
        "echo \"\nFLAG N\" | tee -a _cat_test_result.txt && "
        "diff -s _cat_test_s21.txt _cat_test_orig.txt >> "
        "_cat_test_result.txt");

    system(
        "echo \"\nFLAG T\" | tee -a _cat_test_s21.txt && "
        "./s21_cat -b bytes.txt >> _cat_test_s21.txt && "
        "echo \"\nFLAG T\" | tee -a _cat_test_orig.txt && "
        "cat -b bytes.txt >> _cat_test_orig.txt && "
        "echo \"\nFLAG T\" | tee -a _cat_test_result.txt && "
        "diff -s _cat_test_s21.txt _cat_test_orig.txt >> "
        "_cat_test_result.txt");

#ifndef __UNIX__
    system(
        "echo \"\nGNU FLAG number-nonblank\" | tee -a _cat_test_s21.txt "
        "&& "
        "./s21_cat --number-nonblank bytes.txt >> _cat_test_s21.txt "
        "&& "
        "echo \"\nGNU FLAG number-nonblank\" | tee -a _cat_test_orig.txt "
        "&& "
        "cat -b bytes.txt >> _cat_test_orig.txt && "
        "echo \"\nGNU FLAG number-nonblank\" | tee -a _cat_test_result.txt && "
        "diff _cat_test_s21.txt _cat_test_orig.txt >> "
        "_cat_test_result.txt");

    system(
        "echo \"\nGNU FLAG number\" | tee -a _cat_test_s21.txt && "
        "./s21_cat --number bytes.txt >> _cat_test_s21.txt && "
        "echo \"\nGNU FLAG number\" | tee -a _cat_test_orig.txt && "
        "cat -n bytes.txt >> _cat_test_orig.txt && "
        "echo \"\nGNU FLAG number\" | tee -a _cat_test_result.txt && "
        "diff _cat_test_s21.txt _cat_test_orig.txt >> "
        "_cat_test_result.txt");

    system(
        "echo \"\nGNU FLAG squeeze-blank\" | tee -a _cat_test_s21.txt && "
        "./s21_cat --squeeze-blank bytes.txt >> _cat_test_s21.txt && "
        "echo \"\nGNU FLAG squeeze-blank\" | tee -a _cat_test_orig.txt && "
        "cat -s bytes.txt >> _cat_test_orig.txt && "
        "echo \"\nGNU FLAG squeeze-blank\" | tee -a _cat_test_result.txt && "
        "diff _cat_test_s21.txt _cat_test_orig.txt >> "
        "_cat_test_result.txt");

#endif
    return 0;
}
