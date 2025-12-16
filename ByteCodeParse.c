//
// Created by Administrator on 2025/12/17.
//

#include "ByteCodeParse.h"

#include "StringReader.h"
#include "OpCodes.h"

inline ParseResult* createParseResult(const unsigned int operation, void** args)
{
  ParseResult *result = malloc(sizeof(ParseResult));
  result->operation = operation;
  result->args = args;
  return result;
}

ParseResult* parse(String *str)
{
  StringReader *sr = createStringReader(str);
  const String* command = readToCantRead(sr);
  int op = getInstruction(command->value);
  int i = 0;
  while (!shouldStop(sr))
  {

  }
}

void freeParseResult(ParseResult* res)
{
  for (int i = 0;res->args[i] != NULL; i++)
  {
    free(res->args[i]);
  }
  free(res->args);
  free(res);
  res = NULL;
}

