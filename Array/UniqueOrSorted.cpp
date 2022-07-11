#include<iostream>
using namespace std;

int main()
{
    int size,i,a=0,count=0;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    for(i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j])
            {
                a++;
                break;
            }
            else if(arr[i] > arr[j])
            {
                count++;
                break;
            }
        }
        if(a == 1)
        {
            cout<<"Array doesn't contain ony unique elements."<<endl;
            a++;
        }
        if(count == 1)
        {
            cout<<"Array is not sorted."<<endl;
            count++;
        }    
    }
    if(a == 0)
    cout<<"Array contain ony unique elements"<<endl;
    else if(count == 0)
    {
        cout<<"Array is sorted"<<endl;
    }
    return 0;
}