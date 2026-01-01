//Use Raplit because ye compiler sahi answer nahi de raha hai.




#include "stdio.h"

// Function declarations.
void printArray(int *A, int size);
void mergeSort(int A[], int low, int high);
void merging(int A[], int mid, int low, int high);

int main(void) {
  int A[] = {2, 10, 8, 7, 9, 12, 16, 1, 15, 3};

  int size = 10;
  int low = 0;
  int high = size - 1;

  printf("\nPrinting array before sorting.\n");
  printArray(A, size);

  mergeSort(A, low, high);

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
void mergeSort(int A[], int low, int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    merging(A, mid, low, high);
  }
}

// Function for merging.
void merging(int A[], int mid, int low, int high) {
  int i, j, k, B[100];
  i = low;
  j = mid + 1;
  k = low;

  // Coping all the elements of A[] to B[] in sorted manner .
  while (i <= mid && j <= high) {
    if (A[i] > A[j]) {
      B[k] = A[i];
      i++;
      k++;
    } else {
      B[k] = A[j];
      j++;
      k++;
    }
  }

  while (i <= mid) {
    B[k] = A[i];
    i++;
    k++;
  }

  while (j <= high) {
    B[k] = A[j];
    j++;
    k++;
  }

  // Copy all the elements of B[] to A[].
  for (int i = 0; i <= high; i++) {
    A[i] = B[i];
  }
}

