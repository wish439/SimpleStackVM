#include <stdio.h>
#include <string.h>

#include "StorageStack.h"

StorageStack* createStorageStack(const size_t maxSize)
{
  StorageStack* stack = malloc(sizeof(StorageStack));
  if (!stack)
  {
    return NULL;
  }
  stack->data = malloc(maxSize * sizeof(void*));
  //init to 0;
  stack->maxSize = maxSize;
  stack->currentSize = 0;
  return stack;
}

void pushToStorageStack(StorageStack* stack, void* element, const int tag)
{
  if (stack->data == NULL)
  {
    printf("stack is empty");
    return;
  }

  if (isStorageStackFull(stack))
  {
    printf("StorageStack is full");
    return;
  }

  //push

  stack->data[tag] = element;
  stack->currentSize++;
}

void* getFromStorageStack(const StorageStack* stack, const int tag)
{
  if (stack->data == NULL)
  {
    printf("data is empty pop failed.");
    return NULL;
  }

  if (isStorageStackEmpty(stack))
  {
    return NULL;
  }

  const void* element = stack->data[tag];
  //copy element
  void* clone = malloc(sizeof(element));
  memcpy(clone, element, sizeof(element));
  //return clone
  return clone;
}

void freeStorageStack(StorageStack* stack)
{
  if (!stack) return;
  for (int i = 0; i < stack->currentSize; i++)
  {
    free(stack->data[i]);
  }
  free(stack->data);
  stack->currentSize = 0;
  free(stack);
  stack = NULL;
}

int isStorageStackEmpty(const StorageStack* stack)
{
  return stack->currentSize <= 0;
}

int isStorageStackFull(const StorageStack *stack)
{
  return stack->currentSize >= stack->maxSize;
}