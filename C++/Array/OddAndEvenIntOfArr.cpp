#include<iostream>
using namespace std;

int main()
{
    int size,i,j=0;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }

    //O(n)->time Complexity O(2n)=O(n)->Auxiliary Space

    /*int odd[size],even[size];
    for(i=0;i<size;i++)
    {
        if(arr[i] % 2 == 0)
        {
            even[j]=arr[i];
            j++;
        }       
    }

    int k=0;

    for(i=0;i<size;i++)
    {
        if(arr[i] % 2 != 0)
        {
            odd[k]=arr[i];
            k++;
        }       
    }
    
    for(i=0;i<j;i++)
    cout<<even[i]<<" ";

    cout<<endl;

    for(i=0;i<k;i++)
    cout<<odd[i]<<" ";

    */

    //O(n)->time Complexity O(1)->auxiliary Space
    cout<<"Even Numbers : "<<endl;
    for(i=0;i<size;i++)
    {
        if(arr[i] % 2 == 0)
        {
            cout<<arr[i]<<" ";
        }       
    }

    cout<<endl<<"Odd Numbers : "<<endl;
    for(i=0;i<size;i++)
    {
        if(arr[i] % 2 != 0)
        {
            cout<<arr[i]<<" ";
        }       
    }


    return 0;
}