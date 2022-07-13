#include<iostream>
using namespace std;

int main()
{
    int size,i,a;
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
        a=0;
        for(int j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j])
            a++;
        }  
        if(a == 0)
        cout<<arr[i] <<" "; 
    }
    return 0;
}