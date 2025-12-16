//
// Created by Administrator on 2025/12/16.
//

#ifndef CMAKETEST_STRING_H
#define CMAKETEST_STRING_H
#include <stdlib.h>

typedef struct string
{
  char *value;
  size_t len;
}String;

String* createString(char *str);

void freeString(String *str);

#endif //CMAKETEST_STRING_H