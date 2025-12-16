//
// Created by Administrator on 2025/12/16.
//


#include "MiniStackVM.h"
#include "OpCodes.h"

MiniStackVM* createMiniStackVM(const size_t elementSize)
{
  MiniStackVM* vm = malloc(sizeof(MiniStackVM));
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

void freeMiniStackVM(MiniStackVM* vm)
{
  if (vm)
  {
    freeStorageStack(vm->stack);
    freeOperationStack(vm->opStack);
    free(vm);
    vm = NULL;
  }
}

void executeByteCode(MiniStackVM* vm, const unsigned int OpCodeTag, void* args[])
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
    int* value1 = popOperation(vm->opStack);
    int* value2 = popOperation(vm->opStack);
    int* result = malloc(sizeof(int));
    *result = *value1 + *value2;
    free(value1);
    free(value2);
    pushOperation(vm->opStack, result);
    break;
  case 0x04: // ISUB
    //top sub second top
    int* value3 = popOperation(vm->opStack);
    int* value4 = popOperation(vm->opStack);
    int* result2 = malloc(sizeof(int));
    *result2 = *value3 - *value4;
    free(value3);
    free(value4);
    pushOperation(vm->opStack, result2);
    break;
  case 0x05: // PRINT
    //print operation stack top and pop
    const int* topValue = popOperation(vm->opStack);
    printf("PRINT: %d\n", *topValue);
    break;
  case 0x06: //ISTORE
    if (args[0] == NULL)
    {
      printf("arg Error!!!");
      break;
    }
    const char* str = args[0];
    const int tag = parseInt(str);
    if (tag == -1)
    {
      printf("arg Error!!!");
      break;
    }
    int* popV = popOperation(vm->opStack);
    pushToStorageStack(vm->stack, popV, tag);
    break;
  case 0x07: //ILOAD
    if (args[0] == NULL)
    {
      printf("arg Error!!!");
      break;
    }
    const char* str1 = args[0];
    const int tag1 = parseInt(str1);
    if (tag1 == -1)
    {
      printf("arg Error!!!");
      break;
    }
    int* pushV = getFromStorageStack(vm->stack, tag1);
    pushOperation(vm->opStack, pushV);
    break;
  default:
    printf("Unknown opcode: %02x\n", OpCodeTag);
    return;
  }
}

int parseInt(const char * __restrict__ Str)
{
  char* endptr;
  const int i = strtol(Str, &endptr, 10);
  if (endptr == Str)
  {
    printf("Invalid integer input\n");
    return -1;
  }
  if (*endptr != '\0') {
    printf("包含额外字符\n");
  }
  return i;
}

void executeBC(MiniStackVM* vm, const char* str, void* args[])
{
  if (!str) return;
  executeByteCode(vm, getInstruction(str), args);
}
