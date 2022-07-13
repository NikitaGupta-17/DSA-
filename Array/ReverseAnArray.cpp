#include<iostream>
using namespace std;

int main()
{
    int size,i;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];

    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    //0(n)->time complexity O(n)->Auxiliary space
    /*int reverse[size];

    for(i=0;i<size;i++){
        reverse[size-i-1] = arr[i];
    }
    
    cout<< "Reverse Array : ";
    for(i=0; i <size ;i++)
    {
       cout << reverse[i] << " ";
    }*/

    //O(n/2)=O(n)->Time Complexity O(1)->Auxiliary Space

    for(i=0;i<size/2;i++){
        int temp=arr[i];
        arr[i]=arr[size-i-1];
        arr[size-i-1]=temp;
    }
    cout<< "Reverse Array : ";
    for(i=0; i <size ;i++)
    {
       cout << arr[i] << " ";
    }
    
    return 0;
}