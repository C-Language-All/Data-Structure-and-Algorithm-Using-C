#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data; // For store data.
  struct Node *next; // For store address of next node.
};

int main(void) {
  // Creating object of each node for(which is pointer) for request heap memory
  // and set values and address of next node.
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;

  // Heap memory allocation and points to first element of heap memory.
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));

  // Set data and address of next node.
  head->data = 34;
  head->next = second;
  second->data = 55;
  second->next = third;
  third->data = 66;
  third->next = fourth;
  fourth->data = 99;
  fourth->next = NULL;

  return 0;
}
