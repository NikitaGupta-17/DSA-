#include<iostream>
using namespace std;

int main()
{
    int size,i;
    cout << "Enter the size Of array : ";
    cin >> size;
    int arr[size+1];
    arr[size]=0;
    cout <<"Enter the arrray elemnts : ";
    for(i=0; i<size ; i++)
    {
        cin >> arr[i];
    }
    int add_element,index,temp;
    cout << "Enter the element to be added and index at which it is to be added : ";
    cin >> add_element >> index;
    if(index>=size)
    cout << "Adding element is not possible";
    else
    {
        for(i=size;i>index;i--)
        {
            temp = arr[i-1];
            arr[i] = temp;
        }
        arr[index] = add_element;
    
        for(i=0;i<=size;i++)
        cout << arr[i] << " ";
    }
    return 0;
}