#include "malloc.h"
#include "stdio.h"
// You can use "stdlib.h" as well.

// Creating node.
struct node {
  int data;
  struct node *left;
  struct node *right;
};

//Functions declarations.
struct node *creatNode(int data);
void postorderTraverse(struct node *root);


int main(void) {

  // Creating root node.
  struct node *p = creatNode(4);

  //Other nodes.
  struct node *p1 = creatNode(1);
  struct node *p2 = creatNode(6);
  struct node *p3 = creatNode(5);
  struct node *p4 = creatNode(2);

  
  // Linking all nodes with each other.
  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

  /* Finally tree looks like this
              4
            /   \
           1     6
          / \    
         5   2
    */

  //Traversing this binary tree.
  postorderTraverse(p);
  return 0;
}


//Creat node function.
struct node *creatNode(int data) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}


//Post order Traverse function.
void postorderTraverse(struct node *root){

  if(!(root == NULL)){
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    printf("%d ",root->data);
  }
}
