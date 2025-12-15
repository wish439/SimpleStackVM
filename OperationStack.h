#include <stdio.h>
#include <stdlib.h>

#ifndef OPERATIONSTACK_H
#define OPERATIONSTACK_H

typedef struct operationStack {
  void **data;
  int size;
}OperationStack;

OperationStack* createOperationStack(int size);
void pushOperation(OperationStack* stack, void* operation);
void* popOperation(OperationStack* stack);
void* peekOperation(OperationStack* stack);
int isOperationStackEmpty(OperationStack* stack);
void freeOperationStack(OperationStack* stack);
#endif // OPERATIONSTACK_H