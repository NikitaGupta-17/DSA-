#include<iostream>
using namespace std;

int main()
{
    int size,i,a;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    int index;
    cout << "Enter the index at which element is to be deleted : ";
    cin >> index;
    for(i=index;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    for(i=0;i<size;i++)
    cout<<arr[i]<<" ";
    return 0;
}