#include <stdio.h>

void indDelete(int arr[], int used_size, int index) {

  arr[index] = arr[used_size - 1];

  printf("Deletion completed !\n");
}

void display(int arr[], int used_size) {
  for (int i = 0; i <= used_size - 1; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {

  int arr[100] = {9, 7, 8, 4, 2};
  
  int used_size = 5;
  printf("printing array before deletion \n");
  display(arr, used_size);

  printf("\nDeleting 8 from index 2\n");
  int index = 2;
  indDelete(arr, used_size, index);
  used_size = used_size - 1;//used_size -= 1;

  printf("Printing array after Deletion\n");
  display(arr, used_size);

  return 0;
}
