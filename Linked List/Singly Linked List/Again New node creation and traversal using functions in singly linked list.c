#include "stdio.h"
#include "stdlib.h"

struct Node {
  int data;
  struct Node *next;
};

// Function declaration.
struct Node *newnode(int data);
void traverse(struct Node *head);


int main(void) {
  struct Node *head;
  head = newnode(34);
  head->next = newnode(55);
  head->next->next = newnode(66);
  head->next->next->next = newnode(99);
  
  traverse(head);
  return 0;
}

// Function for new node.
struct Node *newnode(int data) {
 struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
 ptr->next = NULL;
  return ptr;
}

// Function for traverse and print the linked list.
void traverse(struct Node *current) {
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
}
