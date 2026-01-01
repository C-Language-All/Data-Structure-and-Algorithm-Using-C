#include "stdio.h"

// Function declarations.
void printArray(int *A, int size);
void insertionSort(int *A, int size);

int main(void) {
  int A[] = {1, 3, 2, 4, 6, 100, 9};
  int size = sizeof(A) / sizeof(int);

  printf("Printing array before sorting\n");
  printArray(A, size);

  insertionSort(A, size);
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

// Insertion Sort algorithm.
void insertionSort(int *A, int size) {

  // 1st for loop for no. of passes. size-1.
  for (int i = 1; i <= size - 1; i++) {
    int key = A[i];
    int j = i - 1;

    while (j > 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j+1] = key;
  }
}
