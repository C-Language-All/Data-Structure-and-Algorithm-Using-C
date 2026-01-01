#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data;          // For store data
  struct Node *next; // For store address
};

// Functions declaration
void displayCLL(struct Node *head);
struct Node *deleteFirst(struct Node *head);

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
  fourth->next = head;

  printf("\nPrinting elements before deletion.\n");
  // calling display function.
  displayCLL(head);

  printf("\nDeleting first node: \n");
  head = deleteFirst(head);

  printf("\nPrinting elements after deletion.\n");
  displayCLL(head);
  return 0;
}

// Creating display function.
void displayCLL(struct Node *head) {
  struct Node *ptr = head;
  do {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  } while (ptr != head);
}

// Creat function for delete first node from beginning in circular linked list.
struct Node *deleteFirst(struct Node *head) {
  /*
  struct Node *p = head;
  head = head->next;
  free(p);
  return head;
  ye jo code comment mai likha hua hai vo work kar raha hai bina free(p) ke.
  */
  struct Node *p = head;
  struct Node *q = head->next;

  while (q->next != head){
  	q = q->next;
  	}
    
    head = head->next;
    q->next = head;
    free(p);
    return head;
  
  
}
