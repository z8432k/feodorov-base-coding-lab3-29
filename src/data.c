#include <stdio.h>
#include <stdlib.h>
#include "include/data.h"
#include "include/error.h"

#define BIN_STR_DIGITS 16

static char* boxToBinString(const unsigned short box) {
  char *binStr = (char *) calloc((BIN_STR_DIGITS + 1), sizeof(char));

  unsigned short n = box;

  short i = BIN_STR_DIGITS - 1;
  binStr += BIN_STR_DIGITS;

  while (i >= 0 && n) {
    binStr--;

    if (n & 1) {
      *binStr = '1';
    }
    else {
      *binStr = '0';
    }

    n >>= 1;
    i--;
  }

  return binStr;
}

Data_t* newData(void) {
  return (Data_t *) malloc(sizeof(Data_t));
}

void fillData(Data_t *data, const char **argv) {
  unsigned short taskIdent = (unsigned short) atoi(argv[1]);
  unsigned short activityFlag = (unsigned short) atoi(argv[2]);
  unsigned short segmentLength = (unsigned short) atoi(argv[3]);

  if (taskIdent > 31) {
    eprintf("Task identifier must be in [0; 31].");
  }

  if (activityFlag > 1) {
    eprintf("Activity flag must be in [0; 1].");
  }

  if (segmentLength > 255) {
    eprintf("Segment length must be in [0; 255].");
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
  printf("Task identifier\t:%u\n", data->taskIdent);
  printf("Activity flag\t:%u\n", data->activityFlag);
  printf("Segment length\t:%u\n\n", data->segmentLength);
}

void printEncodedData(const unsigned short box) {
  printf("Encoded data HEX\t:%X\n", box);

  char *binStr = boxToBinString(box);
  printf("Encoded data BIN\t:%s\n", binStr);

  free(binStr);
}
