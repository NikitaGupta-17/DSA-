#include<stdio.h>

int main()
{
    int arr[10];
    int n,i,j,temp;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter the elements of array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
