CFLAGS = gcc -Wall -Werror -Wextra

ALL: clean s21_cat

s21_cat:
	$(CFLAGS) main.c flags.c printer.c -o s21_cat

clean:
	rm -rf s21_cat
	rm -rf ../.clang-format

test_func:ALL
	sh test_func_cat.sh

test_leak:ALL
	sh test_leak_cat.sh

style:
	cp ../../materials/linters/.clang-format ../../src
	clang-format -n main.c
	clang-format -n flags.c
	clang-format -n main.h
	clang-format -n printer.c

