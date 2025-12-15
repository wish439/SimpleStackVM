#include <stdio.h>

int main() 
{

  size_t a = sizeof(void*);
  size_t b = sizeof(int*);
  printf("Size of void*: %zu\n", a);
  printf("Size of int*: %zu\n", b);
  return 0;
}