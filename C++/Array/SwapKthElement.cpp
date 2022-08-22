#include<iostream>
using namespace std;

int main()
{
    int size,i,position;
    cout << "Enter the size of array: ";
    cin >> size;
    
    int arr[size];

    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i]; 
    }
    cout<<"Enter the position :";
    cin >> position;
    int temp;
    temp = arr[position-1];
    arr[position-1] = arr[size-position];
    arr[size-position] = temp;

    for(i=0;i<size;i++)
    cout << arr[i] <<" ";
    return 0;
}