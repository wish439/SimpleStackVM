#pragma once
#include <stdlib.h>

#ifndef STORAGESTACK_H
#define STORAGESTACK_H

typedef struct {
  void **data;
  size_t maxSize;
  size_t currentSize;
} StorageStack;

void pushToStorageStack(StorageStack *stack, void *element, int tag);
void* getFromStorageStack(const StorageStack *stack, int tag);
StorageStack* createStorageStack(size_t maxSize);
void freeStorageStack(StorageStack *stack);
int isStorageStackEmpty(const StorageStack *stack);
int isStorageStackFull(const StorageStack *stack);
#endif // STORAGESTACK_H