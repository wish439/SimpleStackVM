//
// Created by Administrator on 2025/12/16.
//

#include "OpCodes.h"
#include <string.h>

unsigned int getInstruction(const char *name) {
  for (int i = 0; instruction_table[i].name != NULL; i++) {
    if (strcmp(instruction_table[i].name, name) == 0) {
      return instruction_table[i].value;
    }
  }
  return 0;
}