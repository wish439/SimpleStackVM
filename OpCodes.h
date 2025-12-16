#pragma once

#define IPUSH 0x01
#define IPOP 0x02
#define IADD 0x03
#define ISUB 0x04
#define PRINT 0x05
#define ISTORE 0x06
#define ILOAD 0x07

#define ICONST_0 101
#define ICONST_1 102
#define ICONST_2 103
#define ICONST_3 104
#define ICONST_4 105

struct Instruction {
  const char *name;
  unsigned int value;
};

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

unsigned int getInstruction(const char *name);
