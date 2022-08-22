#include<iostream>
using namespace std;

int main()
{
    int size,i,a;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size],sum=0;
    float median;
    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }

    //Median Of Array elements

    if(size % 2 == 0){
        median = (arr[size/2] + arr[(size/2)-1])/2.0;    
        cout << "Median of array :" << median << endl;
    }
    else
    cout << "Median of array :" << arr[(size/2)] << endl;

    //Mean Of array elements

    for(i=0;i<size;i++)
    {
        sum= sum +arr[i];
    }
    cout << "Mean of array : "<< sum/size;
    return 0;
}