#include "stdio.h"
#include "stdlib.h"

//Creating structure for stack
struct Stack{
int size;
int top;
int *arr;
};


int main() { 
  struct Stack s;
  s.size = 6;
  s.top = -1;
  s.arr = (int*)malloc(s.size*sizeof(int));

  return 0; 
}
