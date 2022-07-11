#include<iostream>
using namespace std;

int main()
{
    int size,size1,next=0,a=0;
    int i=0,j;
    cout<<"Enter the size of First Array : ";
    cin>> size;
    int arr[size];
    cout<<"Enter the Elements of First Array : ";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
       
    cout<<"Enter the size of Second Array : ";
    cin>> size1;
    int arr1[size1];
    cout<<"Enter the Elements of Second Array : ";
    for(i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }
    
    for(j=0;j<size;j++)
    {
    	for(i=0;i<size1;i++)
    	{
            if(arr1[i] == arr[j])
            {
                next++;
            }
        }
    }
    
    if(size>size1 && (next == size1))
	{
		cout<<"Second array is subset of first array.";
	}
    else if(size1>size && (next == size))
    {
    	cout<<"First array is subset of second array.";
	}
    else if((size1 == size) && (next ==size))
    {
        cout<<"Both array are equal";
    }
    else
    cout<<"Neither 1 nor 2 is subset of another";

    return 0;
}    

