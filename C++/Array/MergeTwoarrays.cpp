#include<iostream>
using namespace std;
int main()
{
    int size,size1;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size],i,j;
    cout<<"Enter the elements of 1st array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter The size of 2nd array : ";
    cin >> size1;
    int arr1[size1];
    cout<<"Enter the elements of 2nd array :";
    for(j=0;j<size1;j++)
    {
        cin >> arr1[j];
    }
    int merge[size+size1],k=0;
    i=0;
    j=0;
    while(i<size && j<size1)
    {
        if(arr[i]>arr1[j])
        {
            merge[k] = arr1[j];
            k++;
            j++;
        }
        else if(arr[i]<arr1[j])
        {
            merge[k] = arr[i];
            k++;
            i++;
        }
        else{
            merge[k]=arr[i];
            i++;
            k++;
            merge[k]=arr1[j];
            j++;
            k++;
        }
    }
    while(i < size)
    {
        merge[k] = arr[i];
        k++;
        i++;
    }
    while(j < size1)
    {
        merge[k] = arr1[j];
        j++;
        k++;
    }
    cout << "Merge Array : ";
    for(i=0;i<k;i++)
    cout << merge[i] <<" ";
    
    return 0;
}