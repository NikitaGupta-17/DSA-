#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size],i,j;
    cout<<"Enter the elements of 1st array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    int arr1[size];
    cout<<"Enter the elements of 2nd array :";
    for(i=0;i<size;i++)
    {
        cin >> arr1[i];
    }
    int difference ;
    i=0;
    j=0;
    cout << "Difference of Two arrays : ";
    while(i<size && j<size)
    {
        difference=0;
        difference = arr[i++] - arr1[j++];
        cout << difference <<" ";
    }
    return 0;
}