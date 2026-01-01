#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data;          // For store data
  struct Node *next; // For store address
};

//Fubctions definations.
void displaylinkedlist(struct Node *ptr);
struct Node *insertAtEnd(struct Node *head, int data);


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

  printf("Printing elements before insertion at end \n");
  // calling display function.
  displaylinkedlist(head);

  printf("\nInsert 30 at the end\n");
  head = insertAtEnd(head, 100);

  printf("\nPrinting elements after insertion at the end \n");
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

// Creating a function for insert node at the end and returns head node.
struct Node *insertAtEnd(struct Node *head, int data) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;

  struct Node *p = head;

  while (p->next != NULL) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
  return head;
}
