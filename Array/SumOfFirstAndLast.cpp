#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"enter the size of array :";
    cin>>size;
    int arr[size],i,sum=0;
    cout<<"enter the elements of array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    for(i=0;i<(size/2);i++)
    {
        sum = arr[i] + arr[size-i-1];
        cout << sum <<endl;
    }
    if(size % 2 != 0)
    cout << arr[i];
    
    return 0;
}