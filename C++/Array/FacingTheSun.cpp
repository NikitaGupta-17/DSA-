#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size],i,max,counter=1;
    cout<<"Enter the elements of array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    max = arr[0];
    for(i=1;i<size;i++)
    {
        if(arr[i] > max)
        {
            counter++;
            max = arr[i];
        }
    }
    cout<< counter;
    return 0;
}