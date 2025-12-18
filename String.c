//
// Created by Administrator on 2025/12/16.
//

#include "String.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

String* createString(char *str)
{
  String* string = malloc(sizeof(String));
  string->len = strlen(str);
  string->capacity = (int)string->len + 1;
  string->currentCursor = (int)string->len - 1;
  string->value = malloc(string->capacity);
  if (!string->value) {
    free(string);
    return NULL;
  }
  strcpy(string->value, str);
  return string;
}

void appendToString(String *string, const char ch)
{
  if (!string) return;
  if (string->len + 1 > string->capacity)
  {
    string->capacity = string->capacity * 2;
    char* b = realloc(string->value, string->capacity);
    if (!b)
    {
      free(b);
      return;
    }
    string->value = b;
  }
  string->currentCursor++;
  string->len++;
  string->value[string->currentCursor] = ch;
  string->value[string->len] = '\0';
}

void clearString(String* str)
{
  if (!str) return;
  str->value = NULL;
  str->value = malloc(str->capacity);
  if (!str->value) {
    free(str);
    return;
  }
  strcpy(str->value, "");
  str->currentCursor = 0;
  str->len = 0;
}

void freeString(String **str)
{
  if (!str) return;
  free((*str)->value);
  free(*str);
  *str = NULL;
}