#include <stdio.h>
#include <stdlib.h>
#include "StorageStack.h"
#include "OperationStack.h"
#include "OpCodes.h"

#ifndef MINISTACKVM_H
#define MINISTACKVM_H

typedef struct
{
  StorageStack *stack;
  OperationStack *opStack;
} MiniStackVM;

MiniStackVM *createMiniStackVM(size_t elementSize)
{
  MiniStackVM *vm = (MiniStackVM *)malloc(sizeof(MiniStackVM));
  if (!vm)
  {
    return NULL;
  }
  vm->stack = createStorageStack(elementSize);
  vm->opStack = createOperationStack(elementSize);
  if (!vm->stack || !vm->opStack)
  {
    free(vm->stack);
    free(vm->opStack);
    free(vm);
    return NULL;
  }
  return vm;
}

void freeMiniStackVM(MiniStackVM *vm)
{
  if (vm)
  {
    freeStorageStack(vm->stack);
    freeOperationStack(vm->opStack);
    free(vm);
    vm = NULL;
  }
}

void executebyteCode(MiniStackVM *vm, const unsigned int OpCodeTag)
{
  if (!vm)
  {
    return;
  }

  if (OpCodeTag >= ICONST_0 && OpCodeTag <= ICONST_4)
  {
    int* value = malloc(sizeof(int));
    *value = OpCodeTag - 101;
    //push to operation stack
    pushOperation(vm->opStack, value);
    return;
  }
  

  switch (OpCodeTag)
  {
  case 0x02: // IPOP
    void* a = popOperation(vm->opStack);
    free(a);
    a = NULL;
    break;
  case 0x03: // IADD
    //top add second top
    printf("Executing IADDing\n");
    int* value1 = (int*)popOperation(vm->opStack);
    int* value2 = (int*)popOperation(vm->opStack);
    int* result = malloc(sizeof(int));
    *result = *value1 + *value2;
    free(value1);
    free(value2);
    pushOperation(vm->opStack, result);
    break;
  case 0x04: // ISUB
    //top sub second top
    int* value3 = (int*)popOperation(vm->opStack);
    int* value4 = (int*)popOperation(vm->opStack);
    int* result2 = malloc(sizeof(int));
    *result2 = *value3 - *value4;
    free(value3);
    free(value4);
    pushOperation(vm->opStack, result2);
    break;
  case 0x05: // PRINT
    //print operation stack top and pop
    int* topValue = (int*)popOperation(vm->opStack);
    printf("PRINT: %d\n", *topValue);
    break;
  default:
    printf("Unknown opcode: %02x\n", OpCodeTag);
    return;
  }
}

void executeByteCodes(MiniStackVM *vm, const unsigned int *byteCodes, size_t length)
{
  if (!vm || !byteCodes || length == 0)
  {
    return;
  }

  for (size_t i = 0; i < length; i++)
  {
    executebyteCode(vm, byteCodes[i]);
  }
}
#endif // MINISTACKVM_H
