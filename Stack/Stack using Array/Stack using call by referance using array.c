#include "stdio.h"
#include "stdlib.h"

struct Stack{
int size;
int top;
int *arr;
};


int main() { 
  struct Stack *s =  (struct Stack*)malloc(sizeof(struct Stack));
  s->size = 6;
  s->top = -1;
  s->arr = (int*)malloc(s->size*sizeof(int));

  return 0; 
}

