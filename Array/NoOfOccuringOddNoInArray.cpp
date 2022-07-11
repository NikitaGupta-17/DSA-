#include<iostream>
using namespace std;

int main()
{
    int size,i,count=0;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
        if(arr[i] % 2 != 0)
        count++;
    }

    cout<<"No. of Odd Elements in input array = "<<count;
    
    return 0;
}