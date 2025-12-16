//
// Created by Administrator on 2025/12/16.
//

#include "StringReader.h"

StringReader* createStringReader(String* str)
{
  StringReader* sr = malloc(sizeof(StringReader));
  sr->string = str;
  sr->cursor = 0;
  return sr;
}

int canRead(const StringReader* reader)
{
  const String* s = reader->string;
  const char ch = s->value[reader->cursor];
  if (ch == '\0') return 0;
  if (ch == '\n') return 0;
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

void freeStringReader(StringReader* reader)
{
  if (!reader) return;
  freeString(reader->string);
  free(reader);
  reader = NULL;
}
