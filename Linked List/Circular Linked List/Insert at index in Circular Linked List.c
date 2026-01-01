#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data;          // For store data
  struct Node *next; // For store address
};

// Functions declaration
void displayCLL(struct Node *head);
struct Node *insertAtIndex(struct Node *head, int val,int index);

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

  printf("\nPrinting elements before insertion.\n");
  // calling display function.
  displayCLL(head);

  printf("\nInsert 100 at index 1\n");
  head = insertAtIndex(head, 100,1);

  printf("\nPrinting elements after insertion.\n");
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

// Creat function for insert node at index in circular linked list.
struct Node *insertAtIndex(struct Node *head, int val,int index) {
  // new node creat and set data.
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = val;

  struct Node *p = head;
 int i = 0;
  while (i < index-1) {
    p = p->next;
    i++;
  } 

  ptr->next = p->next; 
  p->next = ptr;


  return head;
}
