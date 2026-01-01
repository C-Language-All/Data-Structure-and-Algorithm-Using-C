#include "stdio.h"

// Function declarations.
void printArray(int *A, int size);
void bubbleSort(int *A, int size);

int main(void) {
  int A[] = {3, 5, 2, 9, 200, 100};
  int size = sizeof(A) / sizeof(int);

  printf("Printing array before sorting\n");
  printArray(A, size);

  bubbleSort(A, size);
  printf("\nPrinting array after sorting\n");
  printArray(A, size);

  return 0;
}

// Print Array defination.
void printArray(int *A, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", A[i]);
  }
}

// Bubble Sort algorithm.
void bubbleSort(int *A, int size) {

  // 1st for loop for no. of passes. size-1.
  for (int i = 0; i < size - 1; i++) {

    // 2nd for loop for no. of comparisons.
    for (int j = 0; j < size - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        int temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
  }
}
