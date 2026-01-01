#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data; // For store data
  struct Node *next; // For store next node's address
};

// Functions declarations
void displaylinkedlist(struct Node *ptr);
struct Node *insertBeg(struct Node *head, int data);

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

  printf("Printing elements before insertion at beginning \n");
  // calling display function.
  displaylinkedlist(head);

  printf("\nInsert 30 at the beginning\n");
  head = insertBeg(head, 30);

  printf("\nPrinting elements after insertion. \n");
  displaylinkedlist(head);

  return 0;
}

// Creating display function.
void displaylinkedlist(struct Node *ptr) {
  while (ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

// Creating a function for insertion node at the beginning which returns head.
// node.
struct Node *insertBeg(struct Node *head, int data) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
  
  ptr->next = head;
  
  return ptr;
}
