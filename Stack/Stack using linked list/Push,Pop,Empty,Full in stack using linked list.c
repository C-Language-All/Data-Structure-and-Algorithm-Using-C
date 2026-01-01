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
int pop(struct Node *tp);
void traversal(struct Node *ptr);

int main(void) {

  top = push(top, 34);
  top = push(top, 55);
  top = push(top, 66);
  top = push(top, 99);
  printf("Traverse before pop\n");
  traversal(top);
  printf("Popped element is %d\n", pop(top));
  printf("Popped element is %d\n", pop(top));
  printf("Traverse after pop\n");
  traversal(top);
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
