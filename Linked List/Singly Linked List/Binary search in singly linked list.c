#include "stdio.h"
#include "stdlib.h"

// Creating a node.
struct Node {
  int data; // For store data
  struct Node *next; // For store address
};

// Functions Delcarations
void displaylinkedlist(struct Node *ptr);
void binarySearch(struct Node *head, int val);
struct Node *middleElement(struct Node *start, struct Node *last);

int main(void) {
  // Creating object of each node for(which is pointer) for request heap memory and set values and address of next node.
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

  printf("\nPrinting elements of linked list\n");
   displaylinkedlist(head);

  
  printf("\nSearching 99,34 and 100 in linked list : \n");
  binarySearch(head, 99);
  binarySearch(head, 34);
  binarySearch(head, 100);
  return 0;
}

// Creating display function.
void displaylinkedlist(struct Node *ptr) {
  while (ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

// Creating binary search function.
void binarySearch(struct Node *head, int val) {
  struct Node *start = head;
  struct Node *last = NULL;
  if (start->data == val) {
      printf("%d is present \n", val);
      return;
  }
  do {
    struct Node *mid = middleElement(start, last);
    if (mid->data == val) {
      printf("%d is present \n", val);
      return;
    } else if (mid->data < val) {
      start = mid->next;
    } else if (mid->data > val) {
      last = mid;
    }

  } while (start != last);
  printf("%d is not present \n", val);
}

// Creating function for find middle element of list.
struct Node *middleElement(struct Node *start, struct Node *last) {
  struct Node *slow = start;
  struct Node *fast = start->next;
  while (fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  return slow;
}
