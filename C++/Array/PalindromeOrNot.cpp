//Reverse Array

#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size],i,counter=0;
    cout<<"Enter the elements of array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    for(i=0;i<(size/2);i++)
    {
        if(arr[i] == arr[size-i-1])
        counter++;
    }
    if(counter == i)
    cout<<"Array is palindrome";
    else
    cout<<"Array is not palindrome";
    return 0;
}