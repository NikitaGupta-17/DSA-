#include<stdio.h>
#include<stdlib.h>

//quick sort
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

//merge sort

void merge(int array[],int low,int mid,int high){
    int i,j,k;
    int lsize=mid-low+1;
    int rsize=high-mid;
    int arr[lsize],arr1[rsize];
    for(i=0;i<lsize;i++){
        arr[i]=array[low+i];
    }
    for(j=0;j<rsize;j++){
        arr1[j]=array[mid+1+j];
    }
    i=0;
    j=0;
    k=low;
    while(i<lsize && j<rsize){
        if(arr[i]<=arr1[j]){
            array[k]=arr[i];
            i++;
        }
        else {
            array[k]=arr1[j];
            j++;
        }
        k++;
    }
    while(i<lsize){
        array[k]=arr[i];
        i++;
        k++;
    }
    while(j<rsize){
        array[k]=arr1[j];
        j++;
        k++;
    }
}

void mergesort(int array[],int low,int high){
    if(low<high){
        int m=low +(high-low)/2;
        mergesort(array,low,m);
        mergesort(array,m+1,high);
        merge(array,low,m,high);
    }
}

int main(){
    int size,i,j,temp,min_index,key;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=(int*)malloc(size*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    //Bubble sort
    for(i=1;i<size;i++){
        for(j=0;j<size-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
    //Selection sort
    for(i=0;i<size-1;i++){
        min_index=i;
        for(j=i+1;j<size;j++){
            if(arr[min_index]>arr[j]){
                min_index=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
    
    //Insertion sort
    for(i=0;i<size;i++){
        key=arr[i];
        for(j=i-1;j>=0 && arr[j]>key;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
    //quickSort(arr,0,size-1); ->quick sort calling 

    //mergesort(arr,0,size-1); ->merge sort calling
    
    printf("Sorted array : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}