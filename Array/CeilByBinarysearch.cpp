#include<iostream>
using namespace std;

int main()
{
    int size,i,count=0,j,key;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout<<"Enter the value of key: ";
    cin>>key;
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    int low=0,high=size-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==key)
        {
            cout << arr[mid];
            break;
        }
        else if(mid == 0 && arr[mid]>key || arr[mid]>key && key>arr[mid+1])
        {
            cout << arr[mid];
            break;
        } 
        else if(arr[mid]<key){
            low =mid+1;
        }
        else if(arr[mid]> key){
            high = mid-1;
        }
    }

    return 0;
}