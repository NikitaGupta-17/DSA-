#include<iostream>
using namespace std;

int main()
{
    int size,i,j,rotation,temp;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout<<"Enter the value of by which array to be rotated :";
    cin>>rotation;
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    while(rotation != 0)
    {
         for(i=0;i<size;i++)
        {
            if(i==0)
            temp =arr[i];

            if(i<size-1)
            arr[i]=arr[i+1];
            
            if(i==size-1)
            arr[i]=temp;
        }
        rotation--;
    }
    for(i=0;i<size;i++)
    cout<<arr[i]<<" ";
    return 0;
}