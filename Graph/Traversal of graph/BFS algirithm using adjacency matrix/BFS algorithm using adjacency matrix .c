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

  // Adjacency Matrix representation of our graph.
  int graph[7][7] = {
  // 0 1 2 3 4 5 6
    {0,1,1,1,0,0,0}, // 0
    {1,0,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,0}, // 2
    {1,0,1,0,1,0,0}, // 3
    {0,0,1,1,0,1,1}, // 4
    {0,0,0,0,1,0,0}, // 5
    {0,0,0,0,1,0,0}  // 6
};

int visited[7] = {0, 0, 0, 0, 0, 0, 0};//Array for storing visited nodes and initialized with 0 for all nodes are unvisited.

int sNode = 0;//Source Node

visited[sNode] = 1; //Now source node is visited.
printf("%d", sNode);

enqueue(q, sNode);//Put this souce node into our exploration queue.

while (!isEmpty(q)) {
  int node = dequeue(q);
  for (int j = 0; j < 7; j++) {
    if (graph[node][j] == 1 && visited[j] == 0) {
      visited[j] = 1;
      printf("%d", j);
      enqueue(q, j);
    }
  }
}

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
