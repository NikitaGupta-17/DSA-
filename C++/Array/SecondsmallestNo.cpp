#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int size,i,smallest,second_smallest;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    smallest = INT_MAX;
    second_smallest = INT_MAX;
    for(i=0 ; i<size ; i++)
    {
        if(smallest > arr[i])
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]<second_smallest && arr[i]>smallest)
        second_smallest = arr[i];
    }
    cout<<"second smallest element of input array : "<< second_smallest;
    return 0;
}