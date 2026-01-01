#include "limits.h"
#include "stdio.h"
#include "stdlib.h"

// Function declarations.
void printArray(int *A, int size);
void countSort(int *A, int size);
int maximum(int *A, int size);

int main(void) {
  int A[] = {2, 10, 8, 2, 9, 12, 16, 1, 15, 3};

  int size = 10;

  printf("\nPrinting array before sorting.\n");
  printArray(A, size);

  countSort(A, size);

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

// Count Sort
void countSort(int *A, int size) {
  int i, j;

  // Finding maximum element of given array.
  int max = maximum(A, size);

  // Making dynamic array of size (max+1) the name of array is count.
  int *count = (int *)malloc((max + 1) * sizeof(int));

  // Initialize all index of count to 0.
  for (i = 0; i < max + 1; i++) {
    count[i] = 0;
  }

  // Given array ki index par jo value hai , count ki usi index (value) mai 1
  // increment karna hai.
  for (i = 0; i < size; i++) {
    count[A[i]] = count[A[i]] + 1;
  }

  i = 0; // Counter for count array.
  j = 0; // Counter for given array.

  // Copy indexes which are not zero in count array to given array.
  while (i <= max) {
    if (count[i] > 0) {
      A[j] = i;
      count[i] = count[i] - 1;
      j++;
    } else {
      i++;
    }
  }
}

// Function for find maximum element in given array.
int maximum(int *A, int size) {
  int max = INT_MIN;

  for (int i = 0; i < size; i++) {
    if (A[i] > max) {
      max = A[i];
    }
  }
  return max;
}
