#include <stdio.h>
#include <stdlib.h>
#include "include/error.h"
#include "include/data.h"

static unsigned short passBox(const char **argv);

int main(const int argc, const char **argv) {
  printf("Unpack.\n\n");

  if (argc < 2) {
    eprintf("Too few CLI arguments. Need one args with hex number.");
  }

  unsigned short box = passBox(argv);

  printEncodedData(box);

  /* read */
  Data_t *data = unpackData(box);

  printData(data);

  free(data);

  return 0;
}

static unsigned short passBox(const char **argv) {
  return (unsigned short) strtol(argv[1], NULL, 16);
}
