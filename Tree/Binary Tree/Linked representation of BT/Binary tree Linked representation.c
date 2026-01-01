#include "malloc.h"
#include "stdio.h"
// You can use "stdlib.h" as well.

// Creating node.
struct node {
  int data;
  struct node *left;
  struct node *right;
};

int main(void) {

  // Creating root node.
  struct node *p;
  p = (struct node *)malloc(sizeof(struct node));
  p->data = 36;

  // Creating left child.
  struct node *p1;
  p1 = (struct node *)malloc(sizeof(struct node));
  p1->data = 45;

  // Creating right child.
  struct node *p2;
  p2 = (struct node *)malloc(sizeof(struct node));
  p2->data = 97;

  // Linking root node with left and right child.
  p->left = p1;
  p->right = p2;

  return 0;
}
