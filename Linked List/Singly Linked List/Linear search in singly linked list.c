#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data; // For store data
  struct Node *next; // For store address
};

void displaylinkedlist(struct Node *ptr);
void linearSearch(struct Node *head,int val);

int main(void) {
  // Creating object of each node for(which is pointer) for request heap memory
  // and set values and address of next node.
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;

  // Heap memory allocation and points to first element of heap memory.
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));

  // Set data and address of next node.
  head->data = 34;
  head->next = second;
  second->data = 55;
  second->next = third;
  third->data = 66;
  third->next = fourth;
  fourth->data = 99;
  fourth->next = NULL;

  //calling display function.
  printf("\nPrinting all elements\n");
  displaylinkedlist(head);
  
  
  printf("\nSearching 99 in linked list :\n ");
  linearSearch(head,99);

  return 0;
}


//Creating display function.
void displaylinkedlist(struct Node *ptr) {
  while (ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}


//Creating linear search function.
void linearSearch(struct Node *head, int val) {
  struct Node *ptr = head;
  int i = 0;
  while(ptr->data!=val && ptr->next!= NULL)
  {
  	ptr=ptr->next;
  	i++;
  }
  if(ptr->data == val){
    printf("%d is present at %d index\n",val,i);
  }
  else{
    printf("\nItem is not present \n");
  }
}
