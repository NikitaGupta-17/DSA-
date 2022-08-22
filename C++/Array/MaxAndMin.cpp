#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int size,i,max,min;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    max = INT_MIN;
    min = INT_MAX;
    for(i=0;i<size;i++)
    {
        if(arr[i] > max)
        max = arr[i];
        else if(arr[i] < min)
        min = arr[i];
    }
    cout << "Maximum value of array elements : " << max << endl;
    cout << "Minimum value of array elements : " << min << endl;
    return 0;
}