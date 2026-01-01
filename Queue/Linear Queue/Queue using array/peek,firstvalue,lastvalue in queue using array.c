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
int firstVal(struct Queue *q);
int lastVal(struct Queue *q);
int peek(struct Queue *q, int position);

int main(void) {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));

  // Setting size of the queue.
  setSize(q, 100);

  printf("Before enqueue or dequeue\n");

  printf("queue is empty : %d\n", isEmpty(q));
  printf("queue is full: %d\n", isFull(q));

  printf("Enqueue 45 ,90 and 55\n");
  enqueue(q, 45);
  enqueue(q, 90);
  enqueue(q, 55);

  printf("After enqueue \n");
  printf("queue is empty : %d\n", isEmpty(q));
  printf("queue is full: %d\n", isFull(q));

  printf("First value is : %d\n", firstVal(q));

  printf("Dequeuing element : %d\n", dequeue(q));

  printf("After dequeue \n");
  printf("queue is empty : %d\n", isEmpty(q));
  printf("queue is full: %d\n", isFull(q));

  printf("First value is : %d\n", firstVal(q));

  printf("Dequeuing element : %d\n", dequeue(q));

  printf("First value is : %d\n", firstVal(q));

  printf("Last value is : %d\n", lastVal(q));

  printf("Enqueue 100 ,200 and 300\n");
  enqueue(q, 100);
  enqueue(q, 200);
  enqueue(q, 300);

  printf("First value is : %d\n", firstVal(q));

  printf("Last value is : %d\n", lastVal(q));

  printf("Element at position 1 is : %d\n", peek(q, 1));
  printf("Element at position 2 is : %d\n", peek(q, 2));
  printf("Element at position 3 is : %d\n", peek(q, 3));
  printf("Element at position 4 is : %d\n", peek(q, 4));

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

// Function for return first value.
int firstVal(struct Queue *q) {
  int a = q->f;
  a++;
  int b = q->arr[a++];
  return b;
}

// Function for return last value.
int lastVal(struct Queue *q) {
  int a = q->r;
  int b = q->arr[a];
  return b;
}

// Function for peek threw position.
int peek(struct Queue *q, int position) {
  int a = (q->f) + position;
  int b = q->arr[a];
  return b;
}
