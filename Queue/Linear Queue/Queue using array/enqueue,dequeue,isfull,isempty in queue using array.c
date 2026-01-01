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
void enqueue(struct Queue *q, int value);
int dequeue(struct Queue *q);

int main(void) {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));

  // Setting size of the queue.
  setSize(q, 100);

  printf("Before enqueue or dequeue\n");

  printf("queue is empty : %d\n", isEmpty(q));
  printf("queue is full: %d\n", isFull(q));

  printf("Enqueue 45 \n");
  enqueue(q, 45);

  printf("After enqueue \n");
  printf("queue is empty : %d\n", isEmpty(q));
  printf("queue is full: %d\n", isFull(q));

  printf("Dequeuing element : %d\n", dequeue(q));

  printf("After dequeue \n");
  printf("queue is empty : %d\n", isEmpty(q));
  printf("queue is full: %d\n", isFull(q));
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

// Function defination for enqueue.
void enqueue(struct Queue *q, int value) {
  if (isFull(q)) {
    printf("ERROR: queue is full.\n");
  } else {
    q->r++;
    q->arr[q->r] = value;
  }
}

// Function defination for dequeue.
int dequeue(struct Queue *q) {
  if (isEmpty(q)) {
    printf("ERROR: queue is empty.\n");
  } else {
    int a;
    q->f++;
    a = q->arr[q->f];
    return a;
  }
}
