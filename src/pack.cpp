#include <iostream>
#include <stdlib.h>
#include "include/data.h"
#include "include/error.h"

using namespace std;

int main(void) {
  cout << "Pack." << endl << endl;

  Data_t *data = newData();

  inputData(data);
  cout << endl;
  printData(data);

  unsigned short box = packData(data);

  printEncodedData(box);

  free(data);

  return 0;
}

