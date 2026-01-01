#include "stdio.h"
#include "stdlib.h"

struct Node {
  int data;
  struct Node *next;
};

// Function declaration.
struct Node *newnode(struct Node *ptr, int data);
void traverse(struct Node *head);


int main(void) {
  struct Node *head = newnode(head, 34);
  struct Node *second = newnode(second, 55);
  struct Node *third = newnode(third, 66);
  struct Node *fourth = newnode(fourth, 99);

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = NULL;

  traverse(head);
  return 0;
}

// Function for new node.
struct Node *newnode(struct Node *ptr, int data) {
  ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
  return ptr;
}

// Function for traverse and print the linked list.
void traverse(struct Node *current) {
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
}
