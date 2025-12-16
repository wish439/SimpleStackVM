#pragma once
#include <stdio.h>

#include "StorageStack.h"
#include "OperationStack.h"

#ifndef MINISTACKVM_H
#define MINISTACKVM_H

typedef struct
{
  StorageStack *stack;
  OperationStack *opStack;
} MiniStackVM;

MiniStackVM *createMiniStackVM(size_t elementSize);

void freeMiniStackVM(MiniStackVM *vm);

void executeByteCode(MiniStackVM *vm, unsigned int OpCodeTag);

void executeBC(MiniStackVM *vm, const char *str);

#endif // MINISTACKVM_H
