#include "stdio.h"
#include "stdlib.h"

// Global
struct Node *top = NULL;

struct Node {
  int data;
  struct Node *next;
};

// Function declarations.
int isEmpty(struct Node *top);
int isFull(struct Node *top);
struct Node *push(struct Node *top, int x);
int pop(struct Node *top);
void traversal(struct Node *ptr);
int peek(struct Node *top, int position);
int stackTop(struct Node *tp);
int stackBottom(struct Node *tp);

int main(void) {

  top = push(top, 34);
  top = push(top, 55);
  top = push(top, 66);
  top = push(top, 99);

  traversal(top);

  for (int i = 1; i <= 4; i++) {
    printf("Element at %d position is : %d\n", i, peek(top, i));
  }

  printf("Element at top is : %d\n", stackTop(top));

  printf("Element at bottom is : %d\n", stackBottom(top));

  return 0;
}

// Function for check empty.
int isEmpty(struct Node *top) {
  if (top == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// Function for check full.
int isFull(struct Node *top) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (n == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// Function for push.
struct Node *push(struct Node *top, int x) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (isFull(top)) {
    printf("STACK OVERFLOW\n");
  } else {
    n->data = x;
    n->next = top;
    top = n;
    return top;
  }
}

// Function for pop.
int pop(struct Node *tp) {

  if (isEmpty(tp)) {
    printf("STACK UNDERFLOW\n");

  } else {
    struct Node *n = tp;
    top = tp->next;
    int x = n->data;
    free(n);
    return x;
  }
}

// Creating display function.
void traversal(struct Node *ptr) {
  while (ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

// Function for peek.
int peek(struct Node *top, int position) {
  struct Node *ptr = top;
  for (int i = 1; (i <= position - 1 && ptr != NULL); i++) {
    ptr = ptr->next;
  }

  if (ptr != NULL) {
    return ptr->data;
  } else {
    return -1;
  }
}

// Function for return top most element.
int stackTop(struct Node *tp) { return tp->data; }

// Function for return bottom most element.
int stackBottom(struct Node *tp) {
  struct Node *ptr = tp;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  return ptr->data;
}
