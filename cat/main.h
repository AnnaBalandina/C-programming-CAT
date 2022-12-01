#if !defined(MAIN_H)
#define MAIN_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct all_flugs {
  int b, e, n, s, t, v, E, T;
} fl;

void printer(int argc, char **argv, fl *res);
void flags(int argc, char **argv, fl *res);

#endif  // MAIN_H
