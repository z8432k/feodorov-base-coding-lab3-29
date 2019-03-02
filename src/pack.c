#include <stdio.h>
#include  <stdlib.h>
#include "include/data.h"
#include "include/error.h"

int main(const int argc, const char **argv) {
  printf("Pack.\n\n");

  if (argc < 4) {
    eprintf("Too few CLI arguments. Need three args with int numbers.");
  }

  Data_t *data = newData();

  fillData(data, argv);
  printData(data);

  /* encode */
  unsigned short box = packData(data);

  printEncodedData(box);

  free(data);

  return 0;
}

