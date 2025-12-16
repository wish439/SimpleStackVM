//
// Created by Administrator on 2025/12/16.
//
#pragma once
#include "string.h"

#ifndef CMAKETEST_STRINGREADER_H
#define CMAKETEST_STRINGREADER_H


typedef struct stringReader
{
  String* string;
  int cursor;
}StringReader;

StringReader* createStringReader(String *str);
int canRead(const StringReader* reader);
void skip(StringReader* reader);
char peek(const StringReader* reader);
char read(StringReader* reader);
void freeStringReader(StringReader* reader);
#endif //CMAKETEST_STRINGREADER_H