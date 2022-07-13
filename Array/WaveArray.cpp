#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size],i,j,temp;
    cout<<"Enter the elements of array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    for(i=0;i<size && i+1 <size;)
    {
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        i=i+2;
    }
    cout << "wave array : ";
    for(i=0;i<size;i++)
    cout << arr[i] << " ";
    return 0;
}