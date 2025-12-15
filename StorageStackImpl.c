#include "StorageStack.h"

StorageStack* createStorageStack(size_t elementSize) 
{
  StorageStack *stack = (StorageStack *)malloc(sizeof(StorageStack));
  if (!stack) {
      return NULL;
  }
  stack->data = NULL; // Initialize data to NULL or appropriate structure
  stack->elementSize = elementSize;
  return stack;
}

void pushToStorageStack(StorageStack *stack, const void *element, int tag) 
{
  if (stack->data == NULL)
  {
    stack->data = malloc(sizeof(void*));
  }

  //push

  stack->data = realloc(stack->data, stack->elementSize * sizeof(void*));
  ((void**)stack->data)[stack->elementSize - 1] = malloc(stack->elementSize * sizeof(void*));
  stack->elementSize += 1;
}

void* popFromStorageStack(StorageStack *stack, int tag) 
{

  if (stack->data == NULL)
  {
    return NULL;
  }

  if (isStorageStackEmpty(stack))
  {
    return NULL;
  }

  stack->data = realloc(stack->data, (stack->elementSize - 1) * sizeof(void*));
  void *element = ((void**)stack->data)[stack->elementSize - 1];
  stack->elementSize -= 1;
  return element;
}

void freeStorageStack(StorageStack *stack)
{
  if (stack) 
  {
      free(stack->data);
      free(stack);
      stack = NULL;
  }
}

int isStorageStackEmpty(StorageStack *stack) 
{
  return stack->elementSize <= 0;
}
