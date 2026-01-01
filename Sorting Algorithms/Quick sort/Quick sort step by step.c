#include "stdio.h"

int size = 10;
int low = 0;
int high = 9;

// Function declarations.
void printArray(int *A, int size);
void quickSort(int A[], int low, int high);
int partition(int A[], int low, int high);

int main(void) {
  int A[] = {2, 10, 8, 7, 9, 12, 16, 1, 15, 3};

  printf("\nPrinting array before sorting.\n");
  printArray(A, size);

  quickSort(A, low, high);

  printf("\nPrinting array after sorting.\n");
  printArray(A, size);

  return 0;
}

// Print Array defination.
void printArray(int *A, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

// Quick sort
void quickSort(int A[], int low, int high) {
  int partition_index;
  printArray(A, size); // Step by step print array.

  if (low < high) {
    partition_index = partition(A, low, high); // returns partition index.

    quickSort(A, low, partition_index - 1); // sort left subarray

    quickSort(A, partition_index + 1, high); // sort right sub array
  }
}

// Function for partition.
int partition(int A[], int low, int high) {
  int pivot = A[low];
  int i = low + 1;
  int j = high;
  int temp;

  do {
    while (A[i] <= pivot) {
      i++;
    }

    while (A[j] > pivot) {
      j--;
    }
    if (i < j) {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  } while (i < j);

  // Swap A[i] and A[j]
  temp = A[low];
  A[low] = A[j];
  A[j] = temp;
  return j;
}
