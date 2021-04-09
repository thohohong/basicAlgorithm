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

void quickSort(int start, int end){
  int pivot = start;
  int left = start + 1, right = end;

  if (start >= end) return;
  while (left <= right){
    while(left <= end && a[left] <= a[pivot]) left++;
    while(right > start && a[right] >= a[pivot]) right--;
    if (left > right) {
      swap(&a[right], &a[pivot]);
    }
    else {
      swap(&a[left], &a[right]);
    }
  }
  quickSort(start, right - 1);
  quickSort(right + 1, end);
}

int main(){
  int size, min, idx;
  printf("Enter Number of data : ");
  scanf("%d", &size);
  printf("Enter %d numbers : ", size);
  for (int i = 0; i < size; i++){
    scanf("%d", &a[i]);
  }

  quickSort(0, size-1);
  show(a, size);
  return 0;
}