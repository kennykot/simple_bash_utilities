CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
SOURCES:= s21_cat.c
OBJECTS:=$(SOURCES:.c=.o)

all: s21_cat

.c.o:
	$(CC) $(CFLAGS) $< -o $@ 

lint:
	cp ../../materials/linters/CPPLINT.cfg ./
	python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h
	rm CPPLINT.cfg

s21_cat: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

leaks:
	leaks -atExit -- ./s21_cat -b -e -n -s -t -v bytes.txt

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

rebuild: clean all

clean:
	rm s21_cat
	rm -rf *.o
	rm -rf a.*
	rm s21_cat.txt
	rm testing.txt

.PHONY: all clean rebuild lint s21_cat
