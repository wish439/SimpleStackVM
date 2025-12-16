//
// Created by Administrator on 2025/12/16.
//

#include <stdio.h>

#include "OpCodes.h"
#include <string.h>

#ifndef Instruction
struct Instruction {
  const char *name;
  unsigned int value;
};
#endif
#ifndef instruction_table
struct Instruction instruction_table[] = {
  {"IPUSH", IPUSH},
  {"IPOP", IPOP},
  {"IADD", IADD},
  {"ISUB", ISUB},
  {"PRINT", PRINT},
  {"ISTORE", ISTORE},
  {"ILOAD", ILOAD},
  {"ICONST_0", ICONST_0},
  {"ICONST_1", ICONST_1},
  {"ICONST_2", ICONST_2},
  {"ICONST_3", ICONST_3},
  {"ICONST_4", ICONST_4},
  {NULL, -1}
};

#endif

unsigned int getInstruction(const char *name) {
  for (int i = 0; instruction_table[i].name != NULL; i++) {
    if (strcmp(instruction_table[i].name, name) == 0) {
      return instruction_table[i].value;
    }
  }
  return 0;
}