#include<stdio.h>

int main()
{
    int arr[10];
    int n,low,high,mid,element,i,temp=0;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter the elements in ascending order : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be search : ");
    scanf("%d",&element);
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high)
    {
        if(arr[mid]>element)
        {
            high=mid-1;
            mid=(low+high)/2;
        }
        else if(arr[mid]<element)
        {
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            printf("Element is found\n");
            temp++;
            break;
        }
    }
    if(temp==0)
    {
        printf("Element is not found\n");
    }
    return 0;
}