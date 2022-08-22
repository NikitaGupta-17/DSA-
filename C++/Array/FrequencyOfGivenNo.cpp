#include<iostream>
using namespace std;

int main()
{
    int size,i,num,count=0;
    cout << "Enter the size of array: ";
    cin >> size;
    cout<<"Enter a number : ";
    cin >> num;
    int arr[size];

    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i]; 
        if(num == arr[i])
        count++;
    }
    cout<< count;
    
    return 0;
}