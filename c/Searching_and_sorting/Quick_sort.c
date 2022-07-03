#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  
  int pivot = array[high];
  
  int j,i = (low - 1);

  for (j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  
  swap(&array[i +1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int size,i;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int *arr=(int*)malloc(size*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Unsorted Array\n");
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printf("Sorted array in ascending order: \n");
    printArray(arr, size);
}