#include<stdio.h>
#include<stdlib.h>

int main(){
    int size,i,j,min_index,temp1;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int *arr=(int*)malloc(size*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size-1;i++){
        min_index=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        temp1=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp1;
    }
    printf("Sorted Array : ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}