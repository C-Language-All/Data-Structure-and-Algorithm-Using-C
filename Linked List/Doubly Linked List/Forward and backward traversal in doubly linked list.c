#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data;              // For store data
  struct Node *next;     // For store next node's address.
  struct Node *previous; // For store previous node's address.
};

// Function declaration.
void displaylinkedlist(struct Node *head, struct Node *tail);

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

  // Set data and address of next and previous node.
  head->data = 34;
  head->previous = NULL;
  head->next = second;

  second->data = 55;
  second->previous = head;
  second->next = third;

  third->data = 66;
  third->previous = second;
  third->next = fourth;

  fourth->data = 99;
  fourth->previous = third;
  fourth->next = NULL;

  // calling display function.
  displaylinkedlist(head, fourth);

  return 0;
}

// Creating display function.
void displaylinkedlist(struct Node *head, struct Node *tail) {
  struct Node *ptr;

  // Forword traversal
  printf("Forward traversal:-\n");
  ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }

  printf("\n\n");

  // Backword traversal
  printf("Backward traversal:-\n");
  ptr = tail;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->previous;
  }
}
