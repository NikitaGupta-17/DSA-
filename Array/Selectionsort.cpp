#include<iostream>
using namespace std;
int main()
{
    int size,i,temp,j,min;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    for(i=0;i<size;i++)
    {
        min = i;
        for(j=i+1;j<size;j++)
        {
            if(arr[min] > arr[j])
            {
               min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    cout << "Sorted Array : ";
    for(i=0;i<size;i++)
    cout << arr[i] << " ";
    return 0;
}
