//it is used to find how far the array is being from sorted ->ex 8 4 2 1 ->6 {(8,4) (8,2) (8,1) (4,2) (4,1) (2,1) }

#include<iostream>
using namespace std;

int main()
{
    int size,i,count=0,j;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    
    for(i=0 ; i<size ; i++)
    {
        for(j=i+1 ; j<size ; j++)
        {
            if(arr[i]>arr[j])
            count++;
        }
    }
    cout<<count;
    return 0;
}