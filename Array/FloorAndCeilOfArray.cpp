//floor->the (largest) smallest value less than x ->ex 1 2 5 3 7 8 10 ->floor for 7 is 5
//ceil ->the (smallest) largest value than x ->ex 1 2 5 3 7 8 10 ->floor for 7 is 8


#include<iostream>
using namespace std;

int main()
{
    int size,i,count=0,x,ceil=INT8_MAX,floor=INT8_MIN;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout<<"Enter the value of x: ";
    cin>>x;
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    
    for(i=0 ; i<size ; i++)
    {
        if(arr[i]>=x && arr[i]<ceil)
        {
            ceil=arr[i];
            count++;
        }
    }
    if(count == 0)
    cout<<"Ceil doesn't exist in array for x = "<<x<<endl;
    else
    cout<<"Ceil : "<<ceil<<endl;

    count=0;

    for(i=0 ; i<size ; i++)
    {
        if(arr[i]<=x && floor<arr[i])
        {
            floor=arr[i];
            count++;
        }
    }

    if(count == 0)
    cout<<"Floor doesn't exist in array for x = "<<x;
    else
    cout<<"Floor : "<<floor<<endl;

    return 0;
}