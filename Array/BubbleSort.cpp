#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size],i,counter=1,temp;
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
                temp = arr[i];
                arr[i]= arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter++;
    }
    for(i=0;i<size;i++)
    {
        cout << arr[i] <<" ";
    }

    return 0;
}