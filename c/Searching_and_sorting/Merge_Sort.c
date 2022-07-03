#include <stdio.h>
#include <stdlib.h>

int* merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int Left[n1], Right[n2];//Left and right subarray
  
    for (i = 0; i < n1; i++)
        Left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
    return arr;
}

int* mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = left + (right - left) / 2;
  
        arr=mergeSort(arr,left, m);//Sort 1st half
        arr=mergeSort(arr, m + 1, right);//Sort 2nd half
  
        arr=merge(arr,left,m,right);
    }
    return arr;
}
  
void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}


int main()
{
    int size,i;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=(int*)calloc(size,sizeof(int));
    printf("Enter the elements of array : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Input array : ");
    printArray(arr,size);
    arr=mergeSort(arr,0,size - 1);
    printf("Sorted array : ");
    printArray(arr,size);
    return 0;
}