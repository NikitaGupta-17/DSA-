//To find min distance between two array elements

#include<iostream>
#include <climits>
using namespace std;

int min_distance(int arr[],int size,int num1,int num2)
{
    int i,j;
    int min = INT_MAX;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if((num1 == arr[i] && num2 == arr[j] || num1 == arr[j] && num2 == arr[i]) && min >abs(i-j))
            min = abs(i-j);
        }
    }
    if(min > size)
    return -1;
    return min ;
}

int main()
{
    int size;
    cout<<"Enter the size of array : ";
    cin >> size;
    int arr[size],num1,num2,i;
    cout << "Enter the array elements : ";
    for(i=0 ; i<size ; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter two numbers : ";
    cin >> num1 >> num2;
    cout << "Minimum Distance Between "<<num1 <<" and "<<num2 <<" is "<<min_distance(arr,size,num1,num2);
    return 0;
}