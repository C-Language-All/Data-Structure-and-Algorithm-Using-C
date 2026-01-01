#include "stdio.h"
#include "stdlib.h"

struct Queue {
  int size;
  int f;
  int r;
  int *arr;
};

// Functions declarations.
void setSize(struct Queue *q, int size);
int isEmpty(struct Queue *q);
int isFull(struct Queue *q);
void enqueueR(struct Queue *q, int value);
void enqueueF(struct Queue *q, int value);
int dequeueF(struct Queue *q);
int dequeueR(struct Queue *q);
void traverse(struct Queue *q);

int main(void) {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));

  // Setting size of the queue.
  setSize(q, 100);
  printf("\nEnqueue elements 45,67,78 and 34 at rear.\n");
  enqueueR(q, 45);
  enqueueR(q, 67);
  enqueueR(q, 78);
  enqueueR(q, 34);

  printf("\nPrinting the elements \n");
  traverse(q);

  printf("\n\nDequeue %d elment from front\n", dequeueF(q));
  printf("\nPrinting the elements \n");
  traverse(q);

  printf("\n\nEnqueue element 45 at front.\n");
  enqueueF(q, 45);
  printf("\nPrinting the elements \n");
  traverse(q);

  printf("\n\nDequeue element %d from rear.\n", dequeueR(q));

  printf("\nPrinting the elements \n");
  traverse(q);

  return 0;
}

// Function defination for set size of queue.
void setSize(struct Queue *q, int size) {
  q->size = size;
  q->f = q->r = -1;
  q->arr = (int *)malloc((q->size) * sizeof(int));
}

// Function defination for check empty or not.
int isEmpty(struct Queue *q) {
  if (q->f == q->r) {
    return 1;
  }
  return 0;
}

// Function defination for check full or not.
int isFull(struct Queue *q) {
  if (q->r == q->size - 1) {
    return 1;
  }
  return 0;
}

// Function defination for enqueue at rear.
void enqueueR(struct Queue *q, int value) {
  if (isFull(q)) {
    printf("ERROR: queue is full.\n");
  } else {
    q->r++;
    q->arr[q->r] = value;
  }
}

// Function defination for enqueue at front.
void enqueueF(struct Queue *q, int value) {
  if (isFull(q)) {
    printf("ERROR: queue is full.\n");
  } else {
    if (q->f == -1) {
      printf("ERROR: front is -1.\n");
    }
    q->arr[q->f] = value;
    q->f--;
  }
}

// Function defination for dequeue at front.
int dequeueF(struct Queue *q) {
  if (isEmpty(q)) {
    printf("ERROR: queue is empty.\n");
  } else {
    int a;
    q->f++;
    a = q->arr[q->f];
    return a;
  }
}

// Function defination for dequeue at rear.
int dequeueR(struct Queue *q) {
  if (isEmpty(q)) {
    printf("ERROR: queue is empty.\n");
  } else {
    int a;
    a = q->arr[q->r];
    q->r--;
    return a;
  }
}

// Function defination for queue traversal.
void traverse(struct Queue *q) {
  int a = q->f + 1;
  int b = q->r;
  for (int i = a; i <= b; i++) {
    printf("%d ", q->arr[i]);
  }
}
