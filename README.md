# SimpleBashUtilits

## Introduction

- Simple implementation of utilities "cat" and "grep" on language C.

- In this project I have developed basic Bash utilities for working with C programming language texts. These utilities (cat and grep) are often used in the Linux terminal. The project was developed of C11 standard using gcc compiler and for version BSD 2.5.

## Description of the implemented utilities

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines |
| 2 | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  |
| 3 | -n (GNU: --number) | number all output lines |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines |
| 5 | -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  |

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -e | pattern |
| 2 | -i | Ignore uppercase vs. lowercase.  |
| 3 | -v | Invert match. |
| 4 | -c | Output count of matching lines only. |
| 5 | -l | Output matching files only.  |
| 6 | -n | Precede each matching line with a line number. |


## Information about implemented utilities

- The utilities developed in C language of C11 standard using gcc compiler. 
- The utilities built with Makefile with appropriate targets: s21_cat, s21_grep
- The utilities are executable files with command line arguments
- The utilities developed according to the principles of structured programming
- Integration tests cover all flag variants and input values, based on a comparison with the behavior of real Bash utilities

All code is the property of Anton Tuzov.
