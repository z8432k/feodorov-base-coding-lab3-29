#define TASK_IDENT_SIZE 5
#define ACTIVITY_FLAG_SIZE 1
#define SEGMENT_LENGTH_SIZE 8

#define TASK_IDENT_MASK 0x1F
#define ACTIVITY_FLAG_MASK 0x1
#define SEGMENT_LENGTH_MASK 0xFF

typedef struct Data {
  unsigned short taskIdent;
  unsigned short activityFlag;
  unsigned short segmentLength;
} Data_t;

Data_t* newData(void);
void inputData(Data_t *data);
unsigned short packData(const Data_t* data);
Data_t* unpackData(const unsigned short);
void printData(const Data_t* data);
void printEncodedData(const unsigned short box);
unsigned short inputBox();

template <typename T>
static void inputValue(T *value, const char *errStr);
