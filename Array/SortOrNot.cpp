#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size],i,counter=1,temp=0;
    cout<<"Enter the elements of array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    while(counter < size)
    {
        for(i=0;i<size-counter;i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp++;
                break;
            }
        }
        if(temp != 0)
        break;
        counter++;
    }
    if(temp == 0)
    cout << "Given array is sorted.";
    else
    cout << "The input array is not sorted.";
    return 0;
}