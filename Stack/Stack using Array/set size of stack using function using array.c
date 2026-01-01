#include "stdio.h"
#include "stdlib.h"

struct Stack {
  int size;
  int top;
  int *arr;
};

// Function declaration.
void setStackSize(struct Stack *s, int n);

int main() {
  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));

  setStackSize(s, 6);
  return 0;
}

//Set size function defination.
void setStackSize(struct Stack *s, int n) {
  s->size = n;
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));
}
