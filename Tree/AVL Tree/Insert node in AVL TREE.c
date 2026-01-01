#include "stdio.h"
#include "stdlib.h"

struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
};

// Functions declarations
struct node *creatNode(int key);
int getHeight(struct node *n);
int getBalanceFactor(struct node *n);
int max(int a, int b);
struct node *leftRotate(struct node *x);
struct node *rightRotate(struct node *y);
struct node *insert(struct node *node, int key);
void preorderTraverse(struct node *root);

int main(void) {
  struct node *root = NULL;

  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);
  root = insert(root, 3);

  preorderTraverse(root);

  return 0;
}

// Function defination for creat a new node.
struct node *creatNode(int key) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

// Function defination for get height of a given node.
int getHeight(struct node *n) {
  if (n == NULL)
    return 0;
  return n->height;
}

// Function defination for get balance factor of a given node.
int getBalanceFactor(struct node *n) {
  if (n == NULL)
    return 0;
  return getHeight(n->left) - getHeight(n->right);
}

// Function defination for find max.
int max(int a, int b) { return (a > b) ? a : b; }

// Function defination for left rotation.
struct node *leftRotate(struct node *x) {
  struct node *y = x->right;
  struct node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  return y;
}

// Function defination for right rotation.
struct node *rightRotate(struct node *y) {
  struct node *x = y->left;
  struct node *T2 = x->right;

  x->right = y;
  y->left = T2;

  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  return x;
}

// Function defination for insert a new node in AVL Tree.
struct node *insert(struct node *node, int key) {
  if (node == NULL) {
    return creatNode(key);
  }

  if (key < node->key) {
    node->left = insert(node->left, key);
  } else if (key > node->key) {
    node->right = insert(node->right, key);
  }

  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

  int bf = getBalanceFactor(node);

  // Left Left case.
  if (bf > 1 && key < node->left->key) {
    return rightRotate(node);
  }

  // Right Right case.
  if (bf < -1 && key > node->right->key) {
    return leftRotate(node);
  }

  // Left Right case.
  if (bf > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left case.
  if (bf < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

// Preorder Traverse function.
void preorderTraverse(struct node *root) {

  if (!(root == NULL)) {
    printf("%d ", root->key);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
  }
}
