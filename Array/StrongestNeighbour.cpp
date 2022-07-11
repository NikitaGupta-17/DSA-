#include<iostream>
#include<algorithm>
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
    for(i=1;i<size;i++)
    {
        cout << max(arr[i],arr[i-1]) << " ";
    }
    return 0;
}