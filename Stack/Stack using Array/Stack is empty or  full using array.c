#include "stdio.h"
#include "stdlib.h"

struct Stack {
  int size;
  int top;
  int *arr;
};

// Function declaration.
void setStackSize(struct Stack *s, int n);
void isEmpty(struct Stack *s);
void isFull(struct Stack *s);

int main() {
  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));

  setStackSize(s, 6);
  isEmpty(s);
  isFull(s);
  return 0;
}

// Set size function defination.
void setStackSize(struct Stack *s, int n) {
  s->size = n;
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));
}

// Function for check stack is empty or not.
void isEmpty(struct Stack *s) {
  if (s->top == -1) {
    printf("Stack is empty !\n");
  } else {
    printf("Stack is not empty !\n");
  }
}

// Function for check stack is full or not.
void isFull(struct Stack *s) {
  if (s->top == s->size - 1) {
    printf("Stack is full !\n");
  } else {
    printf("Stack is not full!\n");
  }
}
