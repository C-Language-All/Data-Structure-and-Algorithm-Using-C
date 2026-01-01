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
struct node *searchInBST(struct node *root,int value);


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

  //Searching elements in BST.
  if(searchInBST(p,65) != NULL){
    printf("%d element found!\n",(searchInBST(p,65))->data);
  }
  else{
    printf("Element not found!\n");
  }

  
struct node *n = searchInBST(p,2);
  if(n != NULL){
    printf("%d element found!\n",n->data);
  }
  else{
    printf("Element not found!\n");
  }


  
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
struct node *searchInBST(struct node *root,int value){
	
  while(root != NULL){
  if(value == root->data ){
      return root;
    }
  else if(value < root->data){
      root = root->left;
    }
    else {
     root = root->right;
    }
    }
    return NULL;
   }
  
