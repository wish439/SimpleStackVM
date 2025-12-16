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



unsigned int getInstruction(const char *name);
