#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data; // For store data
  struct Node *next; // For store next node's address
};

// Functions declarations
void displaylinkedlist(struct Node *ptr);
struct Node *deleteValue(struct Node *head,int value);

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

  printf("Printing elements before deletion.\n");
  // calling display function.
  displaylinkedlist(head);

  printf("\nDelete 55 from the linked list. \n");
  head = deleteValue(head,55);

  printf("\nPrinting elements after deletion. \n");
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

// Creating a function for delete given value's first occurence and returns head node.
struct Node *deleteValue(struct Node *head,int value) {
  struct Node *p = head;
  struct Node *q = head->next;

  if (p->data == value) {
   
      head = head->next;
      free(p);
      return head;
    

  } else {
    while (q->data != value && q->next != NULL) {
      p = p->next;
      q = q->next;
    }
    if (q->data == value) {
      p->next = q->next;
      free(q);
      return head;
    }
  }

  return head;
}
