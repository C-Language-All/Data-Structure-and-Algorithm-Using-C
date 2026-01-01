#include "stdio.h"
#include "stdlib.h"

struct Stack {
  int size;
  int top;
  int *arr;
};

// Function declaration.
void setStackSize(struct Stack *s, int n);
int isEmpty(struct Stack *s);
int isFull(struct Stack *s);
void push(struct Stack *s, int value);
int pop(struct Stack *s);
int peekByIndex(struct Stack *s, int index);
int peekByPosition(struct Stack *s, int position);

int main() {
  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));

  // setting size of stack 10.
  setStackSize(s, 10);

  push(s, 3);
  push(s, 56);
  push(s, 12);
  push(s, 13);
  push(s, 15);
  push(s, 37);
  push(s, 10);
  push(s, 62);
  push(s, 8);
  push(s, 55);

  pop(s);
  push(s, 59);
  push(s, 60); // Overflow

  for (int i = 1; i <= s->top + 1; i++) {
    printf("Value at %d position is : %d\n", i, peekByPosition(s, i));
  }

  for (int j = 0; j <= s->top; j++) {
    printf("Value at %d index is : %d\n", j, peekByIndex(s, j));
  }

  return 0;
}

// Set size function defination.
void setStackSize(struct Stack *s, int n) {
  s->size = n;
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));
}

// Function for check stack is empty or not.
int isEmpty(struct Stack *s) {
  if (s->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

// Function for check stack is full or not.
int isFull(struct Stack *s) {
  if (s->top == s->size - 1) {
    return 1;
  } else {
    return 0;
  }
}

// Function for push a element in stack.
void push(struct Stack *s, int value) {
  if (isFull(s)) {
    printf("STACK OVERFLOW : can't push %d \n ", value);
    return;
  } else {
    s->top++;
    s->arr[s->top] = value;
  }
}

// Function for pop a element from the stack.
int pop(struct Stack *s) {

  if (isEmpty(s)) {
    printf("STACK UNDERFLOW \n");
    return -1;

  } else {
    int val = s->arr[s->top];
    s->top--;
    return val;
  }
}

// Function for peek by position in stack.
int peekByPosition(struct Stack *s, int position) {
  int arrindex = (s->top - position + 1); // position to index conversion.

  if (arrindex < 0) {
    return -1;
  } else {
    return s->arr[arrindex];
  }
}

// Function for peek by index in stack.
int peekByIndex(struct Stack *s, int index) {
  if (index < 0) {
    return -1;
  } else {
    return s->arr[index];
  }
}
