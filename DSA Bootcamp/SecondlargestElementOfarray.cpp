#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int size,i,largest,second_largest;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    largest = INT_MIN;
    second_largest = INT_MIN;
    for(i=0 ; i<size ; i++)
    {
        if(largest < arr[i])
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i]>second_largest && arr[i]<largest)
        second_largest = arr[i];
    }
    cout<<"second largest element of input array : "<< second_largest;
    return 0;
}