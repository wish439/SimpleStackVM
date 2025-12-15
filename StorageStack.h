#include <stdio.h>
#include <stdlib.h>

#ifndef STORAGESTACK_H
#define STORAGESTACK_H

typedef struct {
  void *data;
  size_t elementSize;
} StorageStack;

void pushToStorageStack(StorageStack *stack, const void *element, int tag);
void* popFromStorageStack(StorageStack *stack, int tag);
StorageStack* createStorageStack(size_t elementSize);
void freeStorageStack(StorageStack *stack);
int isStorageStackEmpty(StorageStack *stack);
#endif // STORAGESTACK_H