#ifndef UTILS
#define UTILS
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

typedef enum {
  Float = 0,
  Char = 1,
  Int = 2,
  Bool = 3,
} Types;

enum Operations {
  OP_AND,
  OP_OR,
  OP_L_EQUAL,
  OP_NOT,
  OP_DIF,
  OP_GT,
  OP_GE,
  OP_LT,
  OP_LE,
  OP_EQUAL,
  OP_MULT,
  OP_PLUS,
  OP_MINUS,
  OP_DIV,
  OP_VAR,
};

union Value {
  int intValue;
  double doubleValue;
  char charValue;
};

typedef struct {
  Types Type;
  union Value value;
  size_t index;
} Symbol;

struct Event {
  short isAtrib;
  char name[256];
  union Value value;
};

typedef struct {
  enum Operations op;
  float arg1;
  float arg2;
  char result[8];
  char name[64];
} TempSymb;

void printTempSymbTable(TempSymb *table, int max);
#endif // !UTILS
