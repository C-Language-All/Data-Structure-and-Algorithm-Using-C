#include "stdio.h"

// Function declarations.
void printArray(int *A, int size);
void selectionSort(int *A, int size);

int main(void) {
  int A[] = {1, 3, 2, 4, 6, 100, 9};
  int size = sizeof(A) / sizeof(int);

  printf("Printing array before sorting\n");
  printArray(A, size);

  selectionSort(A, size);

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

// Selection Sort algorithm.
void selectionSort(int *A, int size) {

  // 1st for loop for no. of passes. size-1.
  for (int i = 0; i < size; i++) {
    int indexOfMin = i;
    for (int j = i + 1; j <= size - 1; j++) {
      if (A[j] < A[indexOfMin]) {
        indexOfMin = j;
      }
    }
    int temp = A[i];
    A[i] = A[indexOfMin];
    A[indexOfMin] = temp;
  }
}
