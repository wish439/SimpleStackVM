//
// Created by Administrator on 2025/12/16.
//

#include "StringReader.h"

#include <stdio.h>

StringReader* createStringReader(String* str)
{
  StringReader* sr = malloc(sizeof(StringReader));
  sr->string = str;
  sr->cursor = 0;
  return sr;
}

int shouldStop(const StringReader *reader)
{
  return peek(reader) == '\0';
}

String* readToCantRead(StringReader* sr)
{
  skipCantRead(sr);
  String* string = createString("");
  while (canRead(sr))
  {
    const char c = read(sr);
    appendToString(string, c);
  }
//  printf("%s\n", string->value);
  return string;
}

void skipCantRead(StringReader* sr)
{
  while (!canRead(sr))
  {
    skip(sr);
  }
}

int canRead(const StringReader* reader)
{
  const char ch = peek(reader);
  if (ch == '\0') return 0;
  if (ch == '\r') return 0;
  if (ch == ' ') return 0;
  return 1;
}

void skip(StringReader* reader)
{
  reader->cursor++;
}

char peek(const StringReader* reader)
{
  return reader->string->value[reader->cursor];
}

char read(StringReader* reader)
{
  return reader->string->value[reader->cursor++];
}

void freeStringReader(StringReader** reader)
{
  if (!reader || !*reader) return;
  freeString(&(*reader)->string);
  free(*reader);
  *reader = NULL;
}
