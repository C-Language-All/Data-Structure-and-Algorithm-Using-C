#include "malloc.h"
#include "stdio.h"
// You can use "stdlib.h" as well.

// Creating node.
struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *creatNode(int data) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

int main(void) {

  // Creating root node.
  struct node *p = creatNode(35);

  // Creating left child.
  struct node *p1 = creatNode(66);

  // Creating right child.
  struct node *p2 = creatNode(87);

  // Linking root node with left and right child.
  p->left = p1;
  p->right = p2;

  return 0;
}
