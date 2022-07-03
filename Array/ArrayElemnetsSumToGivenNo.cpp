#include<iostream>
using namespace std;

int main()
{
    int size,i,x,j,temp=0;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout<<"Enter the value of x :";
    cin>> x;
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if((arr[i] + arr[j]) == x)
            {
                cout<<"x can be expressed as of array elements i.e. "<<arr[i]<<"+"<<arr[j]<<"="<<x<<endl;
                temp++;
                break;
            }
        }        
    }
    if(temp == 0)
    cout<<"x can't be expressed as sum of array elements";
    return 0;
}