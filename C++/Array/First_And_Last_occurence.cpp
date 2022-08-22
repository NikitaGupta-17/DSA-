#include<iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size],i,j,key,first=-1,last=-1;
    cout << "Enter the key : ";
    cin >> key;
    cout << "Enter the elements of array : ";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    i=0;
    j=size-1;
    while(i<=j)
    {
        int mid = (i+j)/2;
        if(arr[mid]<key){
            i=mid+1;
        }
        else if(arr[mid]>key)
        {
            j=mid-1;
        }
        else{
            if(first==-1)
            first=mid;
            last=mid;
            i=mid+1;//Move forward
        }
    }
    i=0;
    j=first;
    while(i<=j)
    {
        int mid = (i+j)/2;
        if(arr[mid]<key){
            i=mid+1;
        }
        else if(arr[mid]>key)
        {
            j=mid-1;
        }
        else{
            if(first==-1)
            first=mid;
            last=mid;
            ij=mid+1;//Move backward
        }
    }
    cout << "First Occurence : "<< first << endl << "Last Occurence : " << last << endl;
    return 0;
}