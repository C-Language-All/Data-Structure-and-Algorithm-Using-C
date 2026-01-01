#include <stdio.h>
#include <stdlib.h>

struct myArray {
  int total_lenght;
  int used_lenght;
  int *ptr;
};

void setsize(struct myArray *ma, int total, int used) {
  /* (*ma).total_lenght = total;
   (*ma).used_lenght = used;
   (*ma).ptr = (int *)malloc((*ma).total_lenght * sizeof(int));
   above and below both are same code
   for our conviniant we used this pointer 👇🏻👇🏻👇🏻
   (*ma).ptr = ma->ptr*/

  ma->total_lenght = total;
  ma->used_lenght = used;
  ma->ptr = (int *)malloc(ma->total_lenght * sizeof(int));
}

void setVal(struct myArray *ma) {

  for (int i = 0; i < ma->used_lenght; i++) {

    printf("Enter the %d num : ", i);
    scanf("%d", &(ma->ptr[i]));
  }
}

void showVal(struct myArray *ma) {
  int n;
  for (int i = 0; i < ma->used_lenght; i++) {
    n = ma->ptr[i];
    printf("%d\n", n);
  }
}

int main(void) {
  struct myArray marks;
  printf("Setting the size of array\n");
  setsize(&marks, 5, 2);
  printf("Taking the values\n");
  setVal(&marks);
  printf("Printing the values\n");
  showVal(&marks);

  return 0;
}
