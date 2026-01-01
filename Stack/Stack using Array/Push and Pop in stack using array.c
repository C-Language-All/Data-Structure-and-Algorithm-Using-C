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

int main() {
  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));

  // setting size of stack 6.
  setStackSize(s, 6);

  // checking stack full or empty.
  if (isEmpty(s)) {
    printf("its empty\n");
  } else {
    printf("not empty \n");
  }
  if (isFull(s)) {
    printf("its full\n");
  } else {
    printf("not full\n ");
  }

  // push 3 in stack
  push(s, 3);

  // again checking its empty or not.
  if (isEmpty(s)) {
    printf("its empty\n");
  } else {
    printf("not empty \n");
  }

  // pushing 5 more elements.
  push(s, 3);
  push(s, 10);
  push(s, 12);
  push(s, 13);
  push(s, 15);

  // Now again checking stack full or empty.
  if (isEmpty(s)) {
    printf("its empty\n");
  } else {
    printf("not empty \n");
  }
  if (isFull(s)) {
    printf("its full\n");
  } else {
    printf("not full\n ");
  }

  // stack is already full but we push a item.
  push(s, 35);	//Stack Overflow

 
  printf("Printing popped element: %d\n",pop(s));
  

  // Checking now it is full or not.
  if (isEmpty(s)) {
    printf("Empty \n");
  } else {
    printf("Not empty \n");
  }
  if (isFull(s)) {
    printf("Its full\n");
  } else {
    printf("Not full\n ");
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
    printf("STACK OVERFLOW : can't push %d \n ",value);
    return;
  } else {
    s->top++;
    s->arr[s->top] = value;
    return;
  }
}

// Function for pop a element from the stack.
int pop(struct Stack *s) {
	
  if (isEmpty(s)) {
    printf("STACK UNDERFLOW \n");
    return 1;

  } else {
  	int val = s->arr[s->top];

    // free(&s->arr[s->top]); it's optional due to push operation mai vo vaise bhi overrite karega hi to iska koi sens nahi hoga.
    s->top--;
    return val;
  }
}
