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
  int size, max = 0, idx = 0, exp = 1;
  int bucket[10];

  printf("Enter Number of data : ");
  scanf("%d", &size);
  printf("Enter %d numbers : ", size);
  for (int i = 0; i < size; i++){
    scanf("%d", &a[i]);
  }
  


  for (int i = 0; i < size; i++){
    if (max < a[i]) max = a[i];
  } //find maximum

  int temp = max;
  while (temp / 10 > 0){
    exp++;
    temp /= 10;
  }//get digit

  for (int i = 0; i < exp; i++){
    int new_a[SIZE];
      
    for (int i = 0; i < 10; i++){
      bucket[i] = 0;
    } //initialize bucket as 0;

    for (int j = 0; j < size; j++){
      int bucket_idx = (int)(a[j] / pow(10, i)) % 10;
      bucket[bucket_idx]++;
    }
    
    for (int j = 0; j < 9; j++){
      bucket[j + 1] += bucket[j];
    }//accumulate bucket
    

    for (int j = size - 1; j >= 0; j--){
      int bucket_idx = (int)(a[j] / pow(10, i)) % 10;
      int new_idx = --bucket[bucket_idx];
      new_a[new_idx] = a[j];
    }

    for (int j = 0; j < size; j++){
      a[j] = new_a[j];
    }
  }

  show(a, size);
  return 0;
}