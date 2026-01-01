#include "stdio.h"
#include "stdlib.h"

struct circularQueue {
  int size;
  int f;
  int r;
  int *arr;
};

// Functions declarations.
void setSize(struct circularQueue *q, int size);
int isEmpty(struct circularQueue *q);
int isFull(struct circularQueue *q);
void enqueue(struct circularQueue *q, int value);
int dequeue(struct circularQueue *q);

int main(void) {
  struct circularQueue *q = (struct circularQueue *)malloc(sizeof(struct circularQueue));

  // Setting size of the queue.
  setSize(q, 4);

  
  enqueue(q, 45);
  enqueue(q, 35);
  enqueue(q, 25);

  printf("Dequeuing element : %d\n", dequeue(q));
  printf("Dequeuing element : %d\n", dequeue(q));
  printf("Dequeuing element : %d\n", dequeue(q));
  
  enqueue(q, 100);
  enqueue(q, 200);
  enqueue(q, 300);
  enqueue(q, 400);

  return 0;
}

// Function defination for set size of queue.
void setSize(struct circularQueue *q, int size) {
  q->size = size;
  q->f = q->r = 0;
  q->arr = (int *)malloc((q->size) * sizeof(int));
}

// Function defination for check empty or not.
int isEmpty(struct circularQueue *q) {
  if (q->f == q->r) {
    return 1;
  }
  return 0;
}

// Function defination for check full or not.
int isFull(struct circularQueue *q) {
  if ((q->r+1)%q->size == q->f) {
    return 1;
  }
  return 0;
}

// Function defination for enqueue.
void enqueue(struct circularQueue *q, int value) {
  if (isFull(q)) {
    printf("ERROR: queue is full.\n");
  } else {
    q->r = (q->r +1)%q->size;
    q->arr[q->r] = value;
    printf("Enqueued element %d\n",value);
  }
}

// Function defination for dequeue.
int dequeue(struct circularQueue *q) {
  if (isEmpty(q)) {
    printf("ERROR: queue is empty.\n");
  } else {
    int a;
    q->f =  (q->f +1)%q->size;
    a = q->arr[q->f];
    return a;
  }
}
