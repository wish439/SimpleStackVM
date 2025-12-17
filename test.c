#include <stdio.h>

int main() 
{

  int b = 10;
  int* a = &b;
  int** c = &a;
  printf("b:%da:%pc:%p", b, a, c);
  scanf("a");
  return 0;
}