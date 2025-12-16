//
// Created by Administrator on 2025/12/16.
//

#include "String.h"
#include <string.h>

String* createString(char *str)
{
  String* string = malloc(sizeof(String));
  string->value = str;
  string->len = strlen(str);
  string->currentCursor = (int)string->len - 1;
  return string;
}

void appendToString(String *string, const char ch)
{
  if (!string) return;
  string->currentCursor++;
  string->value[string->currentCursor] = ch;
}

void freeString(String *str)
{
  if (!str) return;
  free(str->value);
  free(str);
  str = NULL;
}