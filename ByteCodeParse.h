//
// Created by Administrator on 2025/12/17.
//
#pragma once

#include "string.h"

#ifndef CMAKETEST_BYTECODEPASER_H
#define CMAKETEST_BYTECODEPASER_H

typedef struct
{
  unsigned int operation;
  char** args;
  int argc;
}ParseResult;

ParseResult* createParseResult(unsigned int operation, char** args, int argc);
ParseResult* parse(String *str);
void freeParseResult(ParseResult** res);

#endif //CMAKETEST_BYTECODEPASER_H