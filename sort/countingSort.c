#include <stdio.h>
#include <limits.h>
#define SIZE 1000
#define MAX_NUM 10000

int a[SIZE]; 

void show(int *a, int size){
  printf("Sorted Data is : ");
  for (int i = 0; i < size; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(){
  int size, min, idx = 0;
  int accum[MAX_NUM]; //save number of data

  printf("Enter Number of data : ");
  scanf("%d", &size);
  printf("Enter %d numbers : ", size);
  for (int i = 0; i < size; i++){
    scanf("%d", &a[i]);
  }

  //intialize accum as 0
  for (int i = 0; i < size; i++){
    accum[i] = 0;
  } 

  //add 1 to accum[idx], which idx is value of a[i]
  for (int i = 0; i < size; i++){
    accum[a[i]]++;
  }

  //reallocate sorted value in a[]
  for (int i = 0; i < size; i++){
    while (accum[idx] == 0) idx++;
    a[i] = idx;
    accum[idx]--;
  }

  show(a, size);
  return 0;
}