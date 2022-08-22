#include<iostream>
using namespace std;

int main()
{
    int size,i,pos=0,neg=0,zero=0;
    cout << "Enter the size of array: ";
    cin >> size;
    
    int arr[size];

    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i]; 
        if(arr[i] ==0)
        zero++;
        else if(arr[i] > 0)
        pos++;
        else
        neg++;
    }
    cout << "Positive Numbers in given array :" << pos << endl;
    cout << "Negative Numbers in given array :" << neg << endl;
    cout << "Zero Numbers in given array :" << zero << endl;

    return 0;
}