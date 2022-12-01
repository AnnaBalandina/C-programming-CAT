#include "main.h"

void printer(int argc, char **argv, fl *res) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      continue;
    } else {
      FILE *fp;
      if ((fp = fopen(argv[i], "r")) == NULL) {
        fprintf(stderr, "%s%s", argv[i], ": No such file or directory\n");
      } else {
        char c;
        int flag_n = 0;
        int flag = 1;     //на то что сейчас идет \n
        int num_str = 0;  //счетчик строк
        int count_n = 0;  //счетчик  \n
        int last_sym = 0;  // cчетчик введенных простых чаров

        while ((c = getc(fp)) != EOF) {
          if (c == '\n') {
            count_n++;
            flag = 1;
          }
          if (res->n && res->b) {
            flag_n = 1;
          }

          if (res->s && c == '\n' && count_n > 2) {
            continue;
          }

          if (res->n && c != '\n' && flag == 1 && flag_n == 0) {
            flag = 0;
            count_n = 0;
            last_sym = 1;
            printf("%6d\t", ++num_str);
          }

          if (res->n && c == '\n' && last_sym == 0 && flag_n == 0) {
            printf("%6d\t", ++num_str);
          }

          if (((res->E || res->e) && c == '\n')) {
            printf("$");
          }

          if (res->b && c != '\n' && (flag == 1 || count_n > 0)) {
            count_n = 0;
            flag = 0;
            printf("%6d\t", ++num_str);
          }
          if (res->b && c == '\n' && flag == 1) {
            printf("%c", c);
            continue;
          }

          if (((res->T || res->t) && c == '\t')) {
            printf("^I");
            continue;
          }

          if (res->n && c == '\n' && last_sym == 1 && flag_n == 0) {
            last_sym = 0;
          }
          if (res->s && c != '\n' && (flag == 1 || count_n > 0)) {
            count_n = 0;
            flag = 0;
          }
          if ((res->v || res->t || res->e) && (c <= 31) && (c != '\t') &&
              (c != '\n')) {
            printf("%c%c", '^', c + 64);
            continue;
          }
          if ((res->v || res->t || res->e) && (c == 127)) {
            printf("^?");
            continue;
          }
          printf("%c", c);
        }
        fclose(fp);
      }
    }
  }
}