#include "main.h"

int main(int argc, char **argv) {
  fl res = {0};
  flags(argc, argv, &res);
  printer(argc, argv, &res);
  return 0;
}
