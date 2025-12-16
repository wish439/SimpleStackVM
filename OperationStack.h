#include <stdio.h>
#include <stdlib.h>

#ifndef OPERATIONSTACK_H
#define OPERATIONSTACK_H

typedef struct operationStack {
  void **data;
  int size;
  int currentSize;
}OperationStack;

OperationStack* createOperationStack(int maxSize);
void pushOperation(OperationStack* stack, void* operation);
void* popOperation(OperationStack* stack);
void* peekOperation(const OperationStack* stack);
int isOperationStackEmpty(const OperationStack* stack);
void freeOperationStack(OperationStack* stack);
int isOperationFull(const OperationStack* stack);
#endif // OPERATIONSTACK_H