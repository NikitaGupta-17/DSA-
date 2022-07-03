#include<stdio.h>
#include<stdlib.h>

int main(){
    int size,i,*arr;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    arr=(int*)calloc(size,sizeof(int));
    printf("Enter the elements of array : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size;i++){
        if(arr[i] % 15 == 0 ){
            printf("%d - fizz buzz\n",arr[i]);
        }
        else if(arr[i] % 3 == 0){
            printf("%d - fizz\n",arr[i]);
        }
        else if(arr[i] % 5 == 0){
            printf("%d - buzz\n",arr[i]);
        }
        else{
            printf("%d\n",arr[i]);
        }
    }
}