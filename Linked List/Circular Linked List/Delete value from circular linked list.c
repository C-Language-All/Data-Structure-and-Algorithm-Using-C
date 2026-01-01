#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data;          // For store data
  struct Node *next; // For store address
};

// Functions declaration
void displayCLL(struct Node *head);
struct Node *deleteValue(struct Node *head, int value);

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

  printf("\nDeleting 66 from circular linked list: \n");
  head = deleteValue(head, 66);

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

// Creat function for delete value from circular linked list.
struct Node *deleteValue(struct Node *head, int value) {
  struct Node *p = head;
  struct Node *q = head->next;

  if (p->data == value) {
    while (q->next != head) {
      q = q->next;
    }
      head = head->next;
      q->next = head;
      free(p);
      return head;
    

  } else {
    while (q->data != value && q->next != head) {
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
