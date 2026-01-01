#include "stdio.h"
#include "stdlib.h"


// Creating a node.
struct Node {
  int data; // For store data
  struct Node *next; // For store address of next node.
};


//Functions declarations.
void displaylinkedlist(struct Node *ptr);
struct Node *insertindex(struct Node *head, int data, int index);


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

  printf("Printing elements before insertion at index \n");
  // calling display function.
  displaylinkedlist(head);

  printf("\nInsert 30 at index 1\n");
  head = insertindex(head, 30, 1);

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



// Creating a function for insert node at given index which returns head node.
struct Node *insertindex(struct Node *head, int data, int index) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
  
  struct Node *p = head;
  int i = 0;
  while (i != index - 1) {
    p = p->next;
    i++;
  }
  ptr->next = p->next;
  p->next = ptr;
  
  return head;
}


