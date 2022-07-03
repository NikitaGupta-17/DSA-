#include<stdio.h>

int main()
{
    int key,arr[10],l,h,m,i,n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter array elments (in ascending order): ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    l=0;
    h=n-1;
    m=(l+h)/2;
    printf("Enter the value you need to search : ");
    scanf("%d",&key);
    while(l<=h)
    {
        if(arr[m]>key)
        {
            h=m-1;
        }
        else if(arr[m]<key)
        {
            l=m+1;
        }
        else
        {
            printf("Element is found at index %d",m);
            break;
        }
        m=(l+h)/2;
    }
    if(l>h)
    {
        printf("Element is not found \n");
    }
    return 0;
}
