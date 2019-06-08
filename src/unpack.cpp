#include <iostream>
#include <stdlib.h>
#include "include/error.h"
#include "include/data.h"

using namespace std;

int main(void) {
  cout << "Unpack." << endl << endl;

  unsigned short box = inputBox();

  printEncodedData(box);

  Data_t *data = unpackData(box);

  printData(data);

  free(data);

  return 0;
}
