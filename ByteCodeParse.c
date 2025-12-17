//
// Created by Administrator on 2025/12/17.
//

#include "ByteCodeParse.h"

#include "StringReader.h"
#include "OpCodes.h"
#include <stdio.h>

ParseResult* createParseResult(const unsigned int operation, char** args, int argc)
{
  ParseResult* result = malloc(sizeof(ParseResult));
  result->operation = operation;
  result->args = args;
  result->argc = argc;
  return result;
}

ParseResult* parse(String* str)
{
  StringReader* sr = createStringReader(str);
  const String* command = readToCantRead(sr);
  const unsigned int op = getInstruction(command->value);
  int i = 0;
  char** args = malloc(sizeof(void*));
  while (!shouldStop(sr))
  {
    const String* arg = readToCantRead(sr);
    char** temp = realloc(args, sizeof(char*) * (i + 1));
    if (!temp)
    {
      ParseResult* b = createParseResult(op, args, i);
      freeParseResult(&b);
      freeStringReader(&sr);
      return NULL;
    }
    args = temp;
    args[i] = arg->value;
    i++;
  }

  char** temp = realloc(args, sizeof(char*) * (i + 1));
  if (!temp)
  {
    ParseResult* b = createParseResult(op, args, i);
    freeParseResult(&b);
    freeStringReader(&sr);
    return NULL;
  }
  args = temp;
  args[i + 1] = NULL;

  return createParseResult(op, args, i);
}

void freeParseResult(ParseResult** res)
{
  for (int i = 0; i < (*res)->argc; i++)
  {
    free((*res)->args[i]);
  }
  free((*res)->args);
  free(*res);
  *res = NULL;
}
