#include<iostream>
#include <algorithm>
using namespace std;
void sumTarget(int arr[],int n,int sum)
{
    sort(arr,arr+n);
    int temp=0;
    for(int i=0;i<n;i++)
    {
        int F = arr[i+1];
        int L = arr[n-1];
        int x= arr[i];
        while(F!=L)
        {
            if(F + L + x > sum)
            {
               L--;
            }
            if(F + L +x < sum)
            {
               F++;
            }
            if(F+L+x == sum)
            {
                cout<<F <<"+"<<L<<"+"<<x<<"="<<sum;
                temp++;
                break;
            }
        }
        if(temp)
        break;

    }
}

int main()
{
    int size;
    cout<<"Enter size of array :";
    cin>>size;
    int arr[size],sum;
    cin>>sum;
    for(int i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    sumTarget(arr,size,sum);
}