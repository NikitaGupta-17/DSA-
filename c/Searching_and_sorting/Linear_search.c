#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int* LinearSearch(int arr[],int size,int element){
    int i,j=0;
    int*a=(int*)calloc(size,sizeof(int));
    for(i=0;i<size;i++){
        a[i]=INT_MAX;
    }
    for(i=0;i<size;i++){
        if(arr[i]==element){
            a[j]=i;
            j++;
        }
    }
    return a;
}

int main(){
    int i,j,size,element;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=(int*)calloc(size,sizeof(int));
    printf("Enter the elements of array : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be search : ");
    scanf("%d",&element);
    int *a=LinearSearch(arr,size,element);
    for(i=0;i<size;i++){
        if(a[i]==INT_MAX){
            break;
        }
        else{
            printf("Element is found at index %d\n",a[i]);
        }
    }
    return 0;
}