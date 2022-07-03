#include<stdio.h>

int main()
{
    int arr[10];
    int n,i,j,key;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter the elements of array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++)
    {
        key=arr[i];
        for(j=i-1;j>=0 && arr[j]>key ;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
    printf("Sorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}