#include<iostream>
#include<algorithm>
using namespace std;
void sumTarget(int arr[],int n,int sum)
{
    int F = 0;
    int L = n-1;
    int temp=0;
    while(F!=L)
    {
        if(arr[F] + arr[L] > sum)
        {
            L--;
        }
        if(arr[F] + arr[L] < sum)
        {
            F++;
        }
        if(arr[F]+arr[L] == sum){
            temp=1;
            break;
        }
    }
    if(temp==1)
    cout<<"true";
    else
    cout<<"false";
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
    sort(arr,arr+size);
    sumTarget(arr,size,sum);
}
