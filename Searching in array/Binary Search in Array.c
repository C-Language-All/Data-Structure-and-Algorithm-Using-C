#include <stdio.h>

void binarysearch(int arr[], int used_size, int value) {
  int low = 0;
  int high = used_size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == value) {
      printf("%d found at index %d\n", value, mid);
      return;
    } else if (arr[mid] > value) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  printf("%d element is not present in array\n", value);
}

void display(int arr[], int used_size) {
  for (int i = 0; i <= used_size - 1; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  // Array should be sorted for binary search
  int arr[] = {7, 9, 10, 40, 200};

  int used_size = sizeof(arr) / sizeof(int);

  printf("Printing array : \n");
  display(arr, used_size);

  printf("\nSearching 40 in this array\n");
  int value = 40;
  binarysearch(arr, used_size, value);

  return 0;
}
