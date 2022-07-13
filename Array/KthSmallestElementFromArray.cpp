//To find k th smallest element in an unsorted array

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
    int k,temp1;
    cout << "Enter the value of k : ";
    cin >> k;
    for(i=0; i<size; i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]> arr[j])
            {
                temp1 = arr[i];
                arr[i]=arr[j];
                arr[j] = temp1;
            }
        }
    }
    cout << "Kth smallest element : " << arr[k-1];
    return 0;
}