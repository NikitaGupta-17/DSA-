//leaders in an array are the elements whose value is greater than from all of its rightmost elements
//last element is always leader

#include<iostream>
using namespace std;

int main()
{
    int size,i,count,j;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    //Input Array
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    
    /*O(n^2)
    for(i=0 ; i<size ; i++)
    {
        count=0;
        for(j=i+1 ; j<size ; j++)
        {
            if(arr[i] > arr[j])
            count++;
        }
        if(count == (size-i-1))
        cout << arr[i] << " ";
    }*/
    
    //O(n)
    int max=arr[size-1];
    for(i=size-1;i>=0;i--){
        if(i==size-1){
            cout<< arr[i] <<" ";
        }
        else if(max<arr[i]){
            cout<< arr[i] << " ";
            max=arr[i];
        }
    }

    
    return 0;
}