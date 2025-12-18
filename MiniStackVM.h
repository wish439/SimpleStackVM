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

void freeMiniStackVM(MiniStackVM **vm);

void executeByteCode(MiniStackVM* vm, const unsigned int OpCodeTag, const int count , ...);

void executeByteCodeA(MiniStackVM* vm, const unsigned int OpCodeTag,int count, char* args[]);

void executeBC(MiniStackVM *vm, char *str);

int parseInt(const char * __restrict__ Str);

void executeFile(MiniStackVM *vm, const char* filename);
#endif // MINISTACKVM_H
