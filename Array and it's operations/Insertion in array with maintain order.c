#include <stdio.h>

void indInsert(int arr[], int total_size, int used_size, int value, int index) {
  if (index > total_size) {
    printf("Insertion not possible : Index out of range !\n");
  }

  else {
    for (int i = used_size - 1; i >= index; i--) {
      arr[i + 1] = arr[i];
    }
    arr[index] = value;

    printf("Insertion completed !\n");
  }
}

void display(int arr[], int used_size) {
  for (int i = 0; i <= used_size - 1; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {

  int arr[100] = {9, 7, 8, 4, 2};
  int total_size = 100;
  int used_size = 5;
  printf("printing array before insertion \n");
  display(arr, used_size);

  printf("\nInserting 45 at index 2\n");
  int value = 45;
  int index = 2;
  indInsert(arr, total_size, used_size, value, index);
  used_size = used_size + 1;//used_size += 1;
  printf("Printing array after Insertion\n");
  display(arr, used_size);

  return 0;
}
