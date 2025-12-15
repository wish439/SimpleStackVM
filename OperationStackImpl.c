#include "OperationStack.h"

OperationStack* createOperationStack(int size) {
    OperationStack* stack = (OperationStack*)malloc(sizeof(OperationStack));
    stack->data = malloc(size * sizeof(void*));
    stack->size = 0;
    return stack;
}

//int* 8 bytes void* 8 bytes
void pushOperation(OperationStack* stack, void* operation) {
  stack->data = realloc(stack->data, (stack->size + 1) * sizeof(void*));
  (stack->data)[stack->size] = operation;
  stack->size++;
}

void* popOperation(OperationStack* stack) {
  if (isOperationStackEmpty(stack)) {
    printf("Operation stack is empty, cannot pop.\n");
    return NULL;
  }

  stack->size--;
  void* operation = (stack->data)[stack->size];
  int* a = (int*)operation;
  printf("Popped value: %d\n", *a);
  stack->data = realloc(stack->data, stack->size * sizeof(void*));
  return operation;
}

void* peekOperation(OperationStack* stack) {
  if (isOperationStackEmpty(stack)) {
    return NULL;
  }
  return ((void**)stack->data)[stack->size - 1];
}

int isOperationStackEmpty(OperationStack* stack) {
  return stack->size <= 0;
}

void freeOperationStack(OperationStack* stack) {
  for (size_t i = 0; i < stack->size; i++)
  {
    free(stack->data[i]);
  }
  free(stack);
  stack = NULL;
}