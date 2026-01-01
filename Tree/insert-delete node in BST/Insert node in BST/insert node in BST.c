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
void insertInBST(struct node *root,int key);


int main(void) {

  // Creating root node.
  struct node *p = creatNode(11);

  //Other nodes.
  struct node *p1 = creatNode(5);
  struct node *p2 = creatNode(12);
  struct node *p3 = creatNode(2);
  struct node *p4 = creatNode(6);

  
  // Linking all nodes with each other.
  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

  /* Finally tree looks like this
              11
            /   \
           5     12
          / \    
         2   6
    */

  insertInBST(p,34);
  printf("%d",p->right->right->data);
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


//inorder search function.
void insertInBST(struct node *root,int key){
  struct node *prev = NULL;
  
  while(root != NULL){
    prev = root;
    
    if(key == root->data){
      printf("Error : Key already in this BST.");
      return;
    }
    else if(key < root->data){
      root = root->left;
    }
    else {
      root = root->right;
    }
  }

 struct node *new = creatNode(key);
  if(key < prev->data){
    prev->left = new;
  }
  else{
    prev->right = new;
  }
   }
  
