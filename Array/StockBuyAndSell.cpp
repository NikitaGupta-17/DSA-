#include<iostream>
using namespace std;

int main()
{
    int size,i;
    cout << "Enter the size Of array : ";
    cin >> size;
    int arr[size];
    cout <<"Enter the array elements : ";
    for(i=0; i<size ; i++)
    {
        cin >> arr[i];
    }
    int temp=0;
    i=0;
    while (i < size - 1) {
        while ((i < size - 1) && (arr[i + 1] <= arr[i]))
            i++;
        if (i == size - 1)
            break;
        int buy = i++;
        while ((i < size) && (arr[i] >= arr[i - 1]))
            i++;
        int sell = i - 1;
        cout << "Buy on day: " << buy<< "\t Sell on day: " << sell << endl;
        temp++;
    }
    if (temp==0)
    cout << "0";
    return 0;
}
