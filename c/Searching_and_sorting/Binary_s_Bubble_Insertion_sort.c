#include<stdio.h>

int* insertion_sort(int *arr,int size){
    int i,j,key;
    for(i=1;i<size;i++){
        key=arr[i];
        for(j=i-1;j>=0 && arr[j]>key;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
    printf("Sorted array : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return arr;
}

int* bubble_sort(int *arr,int size){
    int i,j,temp;
    for(i=1;i<size;i++){
        for(j=0;j<size-i;j++){
            if(arr[j]>arr[j+1]){
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
            }
        }
    }
    printf("Sorted array : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return arr;
}

int main(){
    int l,h,m,i=0;
    int size,element;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int *arr=(int*)malloc(size*sizeof(int));
    l=0;
    h=size-1;
    m=(l+h)/2;
    printf("Enter the array : ");
    while(i<size){
        scanf("%d",&arr[i]);
        i++;
    }
    arr=insertion_sort(arr,size);
    printf("\nEnter the element to be search : ");
    scanf("%d",&element);
    while(l<=h){
        if(arr[m]>element){
            h=m-1;
        }
        else if(arr[m]<element){
            l=m+1;
        }
        else{
            printf("Element found at index %d\n",m);
            break;
        }
        m=(l+h)/2;
    }
    if(l>h){
        printf("Element not found\n");
    }
    return 0;
}