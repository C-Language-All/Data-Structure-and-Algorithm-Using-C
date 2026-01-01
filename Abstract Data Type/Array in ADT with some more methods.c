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




void setvalbyIndex(struct myArray *ma,int i, int val) {
  ma->ptr[i] = val;
  }

  
  
void getvalbyIndex(struct myArray *ma,int i) {
  printf("%d",ma->ptr[i]);
  }
  
  
void freememory(struct myArray *ma) {
  free(ma->ptr);
  }


int main(void) {
  struct myArray marks;
  
  printf("Setting the size of array\n");
  setsize(&marks, 5, 2);
  
  printf("Taking the values in array\n");
  setVal(&marks);
  
  printf("Printing the values of array\n");
  showVal(&marks);
  
  printf("Set value 245 at index 0\n");
  setvalbyIndex(&marks,0,245);
  
  printf("Printing the new values\n");
  showVal(&marks);
  
  printf("Printing the value at index 1\n");
  getvalbyIndex(&marks,1);
  

  printf("\nFreeing memory\n");
  freememory(&marks);
  printf("Memory freed\n");

  return 0;
}
