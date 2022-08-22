#include<iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size],i,j,key,first=-1,last=-1;
    cout << "Enter the key : ";
    cin >> key;
    cout << "Enter the elements of array : ";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    i=0;
    j=size-1;
    while(i<=j)
    {
        if(arr[i]==key && first==-1){
            first=i;
        }
        if(arr[j]==key && last==-1){
            last=j;
        }
        if(first!=-1 && last!=-1){
            break;
        }
        i++;
        j--;
    }
    cout << "First Occurence : "<< first << endl << "Last Occurence : " << last << endl;
    return 0;
}