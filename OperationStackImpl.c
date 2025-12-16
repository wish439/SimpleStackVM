#include "OperationStack.h"

OperationStack* createOperationStack(const int maxSize)
{
  OperationStack* stack = malloc(sizeof(OperationStack));
  stack->data = malloc(maxSize * sizeof(void*));
  stack->currentSize = 0;
  stack->size = maxSize;
  return stack;
}

//int* 8 bytes void* 8 bytes
void pushOperation(OperationStack* stack, void* operation)
{
  if (isOperationFull(stack))
  {
    printf("OperationStack is full, cannot push.\n");
    return;
  }

  stack->data[stack->currentSize] = operation;
  stack->currentSize++;
}

void* popOperation(OperationStack* stack)
{
  if (isOperationStackEmpty(stack))
  {
    printf("Operation stack is empty, cannot pop.\n");
    return NULL;
  }

  stack->currentSize--;
  void* operation = stack->data[stack->currentSize];
  const int* a = operation;
  printf("Popped value: %d\n", *a);
  return operation;
}

void* peekOperation(const OperationStack* stack)
{
  if (isOperationStackEmpty(stack))
  {
    return NULL;
  }
  return stack->data[stack->currentSize - 1];
}

int isOperationStackEmpty(const OperationStack* stack)
{
  return stack->currentSize <= 0;
}

void freeOperationStack(OperationStack* stack)
{
  for (size_t i = 0; i < stack->currentSize; i++)
  {
    free(stack->data[i]);
  }
  free(stack);
  stack = NULL;
}

int isOperationFull(const OperationStack* stack)
{
  return stack->currentSize >= stack->size;
}
