#include <iostream>
#include <stdlib.h>
#include "include/error.h"

using namespace std;

void bang(const char* msg) {
  cerr << msg << endl;
  exit(1);
}
