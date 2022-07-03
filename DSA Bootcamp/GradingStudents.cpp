#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>37)
        {
            int num=arr[i]%10,temp;
            if(num>5)
            temp=10-num;
            else
            temp=5-num;
            if(temp<3)
            arr[i]=arr[i]+temp;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}