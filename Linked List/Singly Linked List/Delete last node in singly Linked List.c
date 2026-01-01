#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data; // For store data
  struct Node *next; // For store address
};

//Fubctions definations.
void displaylinkedlist(struct Node *ptr);
struct Node *deleteAtLast(struct Node *head);


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

  printf("Printing elements before delete last node. \n");
  // calling display function.
  displaylinkedlist(head);

  printf("\n Deleting the last node.\n");
  head = deleteAtLast(head);

  printf("\nPrinting elements after deletion .\n");
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

// Creating a function for delete last node and returns head node.
struct Node *deleteAtLast(struct Node *head) {
  struct Node *p = head;
  struct Node *q = head->next;
  while(q->next != NULL){
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
  return head;
}
