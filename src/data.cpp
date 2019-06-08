#include <iostream>
#include <limits>
#include <cstdlib>
#include <stdlib.h>
#include "include/data.h"
#include "include/error.h"

#define BIN_STR_DIGITS 16

using namespace std;

static const char *genericInputErr = "Wrong value. Try again:";

static char* boxToBinString(unsigned short box) {
  char *binStr = (char *) calloc((BIN_STR_DIGITS + 1), sizeof(char));
  char *binStrStart = binStr;

  binStr += BIN_STR_DIGITS;

  while (binStr > binStrStart) {
    binStr--;

    if (box & 1) {
      *binStr = '1';
    }
    else {
      *binStr = '0';
    }

    box >>= 1;
  }

  return binStr;
}

Data_t* newData(void) {
  return (Data_t *) malloc(sizeof(Data_t));
}

void inputData(Data_t *data) {
  unsigned short taskIdent;
  unsigned short activityFlag;
  unsigned short segmentLength;

  cout << "Input task ident:";
  inputValue(&taskIdent, genericInputErr);

  if (taskIdent > 31) {
    bang("Task identifier must be in [0; 31].");
  }

  cout << "Input activity flag:";
  inputValue(&activityFlag, genericInputErr);

  if (activityFlag > 1) {
    bang("Activity flag must be in [0; 1].");
  }

  cout << "Input segment lengths:";
  inputValue(&segmentLength, genericInputErr);

  if (segmentLength > 255) {
    bang("Segment length must be in [0; 255].");
  }

  data->taskIdent = taskIdent;
  data->activityFlag = activityFlag;
  data->segmentLength = segmentLength;
}

unsigned short packData(const Data_t *data) {
  unsigned short box = 0;

  box = data->taskIdent;
  box = (box << (1 + ACTIVITY_FLAG_SIZE)) | data->activityFlag;
  box = (box << (1 + SEGMENT_LENGTH_SIZE)) | data->segmentLength;

  return box;
}



Data_t* unpackData(const unsigned short box) {
  Data_t *data = newData();

  data->segmentLength = box & SEGMENT_LENGTH_MASK;
  data->activityFlag = (box >> (SEGMENT_LENGTH_SIZE + 1)) & ACTIVITY_FLAG_MASK;
  data->taskIdent = (box >> (SEGMENT_LENGTH_SIZE + 1 + ACTIVITY_FLAG_SIZE + 1)) & TASK_IDENT_MASK;

  return data;
}

void printData(const Data_t* data) {
  cout << "Task identifier\t:" << dec << data->taskIdent << endl;
  cout << "Activity flag\t:" << dec << data->activityFlag << endl;
  cout << "Segment length\t:" << dec << data->segmentLength << endl << endl;
}

void printEncodedData(const unsigned short box) {
  cout << "Encoded data HEX\t:" << hex << box << endl;

  char *binStr = boxToBinString(box);
  cout << "Encoded data BIN\t:" << binStr << endl << endl;

  free(binStr);
}

unsigned short inputBox() {
  unsigned short data;
  string inputHexStr;

  cout << "Input encoded data:";
  inputValue(&inputHexStr, genericInputErr);

  data = stoul(inputHexStr, nullptr, 16);

  return data;
}

template <typename T>
static void inputValue(T *value, const char* errStr) {
  cin >> *value;

  while (!cin.good()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << errStr;
    cin >> *value;
  }
}
