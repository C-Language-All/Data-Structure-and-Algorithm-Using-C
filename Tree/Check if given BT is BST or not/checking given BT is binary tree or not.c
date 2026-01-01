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
int isBST(struct node *root);



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
if(isBST(p)){
	printf("\nThe BT is BST.\n");
	}
else{
	printf("\nThe BT is not BST.\n");
	}
	
  }
  
  
  
//Creat node function.
struct node *creatNode(int data) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}


//Check given binary tree is BST?. Inorder traversal of BST always gives ascending sorted array.So we check if current node's data is greater than previos node's data or not in inorder traversal.
int isBST(struct node *root){
  static struct node *prev= NULL;
  if(!(root == NULL)){
      if(!isBST(root->left)){
        return 0;
      }
    if(prev != NULL && root->data <= prev->data){
      return 0;
    }
    prev = root;
    return isBST(root->right);
    
  }
  else{
    return 1;
  }
}


