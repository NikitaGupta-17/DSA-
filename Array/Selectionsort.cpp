#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size],i,temp,j;
    cout<<"Enter the elements of array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] =temp;
            }
        }
    }
    cout << "Sorted Array : ";
    for(i=0;i<size;i++)
    cout << arr[i] << " ";
    return 0;
}