#include <stdio.h>

void linearsearch(int arr[], int used_size, int value) {
  for (int i = 0; i < used_size - 1; i++) {
    if (arr[i] == value) {
      printf("%d present in array at index %d\n", value, i);
      return;
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

  int arr[100] = {9, 7, 8, 4, 2};
  
  int used_size = 5;

  printf("Printing array : \n");
  display(arr, used_size);

  printf("\nSearching 4 in this array\n");
  int value = 4;
  linearsearch(arr, used_size, value);

  return 0;
}
