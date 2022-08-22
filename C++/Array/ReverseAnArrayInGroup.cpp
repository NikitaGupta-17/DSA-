#include<iostream>
using namespace std;

int main()
{
    int size,i;
    cout << "Enter the size of array: ";
    cin >> size;
    int k;
    int arr[size];

    cout << "Enter the elements of array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter the number of elements in group : "; 
    cin >> k;
    //reversing array
    /*
    0 1 2 3 4 5 6 7 8 9   k=4 0->3,4->7,
    1 2 3 4 5 6 7 8 9 10

    */
    int a=0;
    int y;
     
    while(a<size)
    {
        if(k+a > size)
        break;
        else{
            y=1;
            for(i=a; i<(k/2)+a ;i++)   //a a+1 ... (k/2)+a-2 (k/2)+a-1 .....k+a-2 k+a-1
            {
            int temp1 = k - y;
            int temp = arr[i];
            arr[i] = arr[temp1+a];
            arr[temp1+a] = temp;
            y++;
            }
            a=a+k;
        }
        
    }
    cout<< "Reverse Array : ";
    for(i=0; i <size ;i++)
    {
       cout << arr[i] << " ";
    }
    
    return 0;
}