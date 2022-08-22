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
    int j=0;
    while(j<size)
    {
        cout << arr[j] <<" ";
        j= j+2;
    }
    
    return 0;
}