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
void inorderTraverse(struct node *root);
struct node *deleteNode(struct node *root,int value);
struct node *inorderPredecessor(struct node *root);


int main(void) {

  // Creating root node.
  struct node *p = creatNode(11);

  //Other nodes.
  struct node *p1 = creatNode(8);
  struct node *p2 = creatNode(15);
  struct node *p3 = creatNode(5);
  struct node *p4 = creatNode(9);

  
  // Linking all nodes with each other.
  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

  /* Finally tree looks like this
              11
            /   \
           8     15
          / \    
         5   9
    */

  //Traversing this binary tree.
  inorderTraverse(p);
  printf("\n");
  deleteNode(p,8);
  inorderTraverse(p);
  
  //Node's new data after deletion.
  printf("\n%d",p->data);
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


//Inorder Traverse function.Inorder traversal of BST always gives sorted array or sorted sequence.
void inorderTraverse(struct node *root){

  if(!(root == NULL)){
    inorderTraverse(root->left);
    printf("%d ",root->data);
    inorderTraverse(root->right);
    
  }
}


//Function for delete node in BST. It works on preInorder deletion technique.
struct node *deleteNode(struct node *root,int value){
  struct node *inPre;
  
  if(root == NULL){
    printf("Error : element is not present in this BST.");
    return NULL;
  }

  if(root->left == NULL && root->right == NULL){
    free(root);
    return NULL;
  }


  //Searching for the node to be deleted.
  if(value < root->data){
    root->left = deleteNode(root->left,value);
  }
  else if(value > root->data){
    root->right = deleteNode(root->right,value);
  }
    
    //Strategy for delete the node.Copy the data of Inorder predecessor node in our main node and finally in uppar if statment we delete that leaf node which is Inorder predecessor node of our main node.
  else {
    inPre = inorderPredecessor (root);
    root->data = inPre->data;
    root->left = deleteNode(root->left,inPre->data);
    }


  return root;
}


//Function for find predecessor of node to be deleted.
struct node *inorderPredecessor(struct node *root){
  root = root->left;
  while(root->right != NULL){
    root = root->right;
  }
  return root;
}
