#include "main.h"

void flags(int argc, char **argv, fl *res) {
  int rez = 0;
  opterr = 0;

  const char *short_options = "+benstvET";

  const struct option long_options[] = {
      {"number-nonblank", no_argument, 0, 'b'},
      {"e", no_argument, 0, 'e'},
      {"number", no_argument, 0, 'n'},
      {"squeeze-blank)", no_argument, 0, 's'},
      {"t", no_argument, 0, 't'},
      {"v", no_argument, 0, 'v'},
      {"E", no_argument, 0, 'E'},
      {"T", no_argument, 0, 'T'},
      {NULL, 0, NULL, 0}};

  while ((rez = getopt_long(argc, argv, short_options, long_options, NULL)) !=
         -1) {
    opterr = 0;
    switch (rez) {
      case 'b':
        res->b = 1;
        break;
      case 'e':
        res->e = 1;
        break;
      case 'n':
        res->n = 1;
        break;
      case 's':
        res->s = 1;
        break;
      case 't':
        res->t = 1;
        break;
      case 'v':
        res->v = 1;
        break;
      case 'E':
        res->E = 1;
        break;
      case 'T':
        res->T = 1;
        break;
      case '?':
        break;
    }
  }
}