#include <stdio.h>
#include <limits.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;

  return 0;
}

void show(int *a, int size){
  printf("Sorted Data is : ");
  for (int i = 0; i < size; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(){
  int size, min, idx;
  printf("Enter Number of data : ");
  scanf("%d", &size);
  printf("Enter %d numbers : ", size);
  for (int i = 0; i < size; i++){
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < size - 1; i++){
    int j = i;
    while(j >= 0 && a[j] > a[j+1]){
      swap(&a[j], &a[j+1]);
      j--;
    }
  }

  show(a, size);
  return 0;
}