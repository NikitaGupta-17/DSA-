#include<iostream>
using namespace std;

int main()
{
    int size,i,a,temp=-1;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size],frequency[size];
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    for(i=0;i<size;i++)
    {
        a=1;
        for(int j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j])
            {
                a++;
                frequency[j]=temp;
            }
        }  
        if(frequency[i]!=temp)
        frequency[i] = a;
    }
    cout<<"Elemnets : Frequency"<<endl;
    for(i=0;i<size;i++)
    {
        if(frequency[i] != temp)
        {
            cout<< arr[i] <<" : " << frequency[i] << endl;
        }
    }
    return 0;
}