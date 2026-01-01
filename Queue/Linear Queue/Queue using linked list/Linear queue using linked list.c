#include "stdio.h"
#include "stdlib.h"
	
//Global.
struct QueueNode *f = NULL;
struct QueueNode *r = NULL;

struct QueueNode {
  int data;
  struct QueueNode *next;
};

// Function declarations.
int isEmpty(struct QueueNode *q);
int isFull(struct QueueNode *q);
void enqueue(int value);
int dequeue();
void displaylinkedlist(struct QueueNode *ptr);

int main(void) {

  printf("isEmpty = %d\n", isEmpty(f));
  printf("isFull = %d\n", isFull(r));

  enqueue(3);
  enqueue(55);
  enqueue(77);

  printf("isEmpty = %d\n", isEmpty(f));
  printf("isFull = %d\n", isFull(r));

  printf("Traversing linked list\n");
  displaylinkedlist(f);

  printf("\nDequeuing element %d\n", dequeue());
  printf("\nDequeuing element %d\n", dequeue());

  printf("\nTraversing linked list\n");
  displaylinkedlist(f);

  printf("\nDequeuing element %d\n", dequeue());
  printf("\nDequeuing element %d\n", dequeue());

  return 0;
}

// Function for isEmpty.
int isEmpty(struct QueueNode *ptr) {
  if (ptr == NULL) {
    return 1;
  }
  return 0;
}

// Function for isFull.
int isFull(struct QueueNode *ptr) {
  struct QueueNode *n = (struct QueueNode *)malloc(sizeof(struct QueueNode));
  if (n == NULL) {
    return 1;
  }
  return 0;
}

// Function for enqueue.
void enqueue(int value) {
  struct QueueNode *n = (struct QueueNode *)malloc(sizeof(struct QueueNode));
  if (isFull(n)) {
    printf("Queue is full\n");
  } else {
    n->data = value;
    n->next = NULL;
    if (f == NULL) {
      f = r = n;
    } else {
      r->next = n;
      r = n;
    }
  }
}

// Fucntion for dequeue.
int dequeue() {
  int value = -1;
  if (f == NULL){
    printf("Queue is empty.\n");
  } else {
    struct QueueNode *ptr = f;
    f = f->next;
     value = ptr->data;
    free(ptr);
    }
    return value;
}

// Creating display function.
void displaylinkedlist(struct QueueNode *ptr) {
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}
