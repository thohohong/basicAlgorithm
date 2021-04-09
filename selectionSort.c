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
}

int main(){
  int size, min, idx;
  printf("Enter Number of data : ");
  scanf("%d", &size);
  printf("Enter %d numbers : ", size);
  for (int i = 0; i < size; i++){
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < size; i++){
    min = INT_MAX;
    for (int j = i; j < size; j++){
      if (min > a[j]){
        min = a[j];
        idx = j;
      }
    }
    swap(&a[i], &a[idx]);
  }

  show(a, size);
  return 0;
}