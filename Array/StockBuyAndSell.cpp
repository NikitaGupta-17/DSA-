#include<iostream>
using namespace std;

int main()
{
    int size,i;
    cout << "Enter the size Of array : ";
    cin >> size;
    int arr[size];
    cout <<"Enter the arrray elements : ";
    for(i=0; i<size ; i++)
    {
        cin >> arr[i];
    }
    int buy ,sell,j,temp=0;
    for(i=0;i<size;)
    {
        buy=arr[i];
        for(j=i+1;j<size;j++)
        {
            if(arr[j]>arr[i] && arr[j]>arr[j+1])
            {
                sell = arr[j];
                cout<<"Buy at "<<i<<" and sell at "<<j<<endl;
                i=j+1;
                temp++;
                break;
            }
        }
    }
    if (temp == 0)
    cout << "0";
    return 0;
}