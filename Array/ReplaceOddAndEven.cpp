//Replace all even by 1 and odd by 0

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
        if(arr[i] % 2 ==0)
        arr[i] = 1;
        else
        arr[i] = 0;
    }

    for(i=0;i<size;i++)
    cout << arr[i] << " ";
    return 0;
}