CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
SOURCES:= s21_grep.c
OBJECTS:=$(SOURCES:.c=.o)

all: s21_grep

.c.o:
	$(CC) $(CFLAGS) $< -o $@ 

lint:
	cp ../../materials/linters/CPPLINT.cfg ./
	python3 ../../materials/linters/cpplint.py --extensions=c *.h $(SOURCES)
	rm CPPLINT.cfg

s21_grep: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

leaks:
	leaks -atExit -- ./s21_grep -n -c -l a bytes.txt

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

rebuild: clean all

clean:
	rm s21_grep
	rm -rf *.o
	rm -rf a.*
	rm s21_grep.txt
	rm grep.txt
	rm testing.txt
	rm -rf s21_grep.dSYM

.PHONY: all clean rebuild lint s21_grep
