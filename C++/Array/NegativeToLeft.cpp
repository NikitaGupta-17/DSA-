//Shifting all negative elements in an array to left 

#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size],i;
    cout<<"Enter the elements of array :";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }

    //O(n)->time Complexity O(1)->Auxiliary space
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
    
    for(i=0;i<size;i++)
    {
        cout << arr[i] <<" ";
    }

    /*
    O(n)->time Complexity O(n)->Auxiliary Space
    int arr1[size],counter =size-1,counter1=0;
    for(i=0;i<size;i++)
    {
        if(!(arr[i] < 0))
        {
            arr1[counter]=arr[i];                                      
            counter--;
        }
        else
        {
            arr1[counter1] = arr[i];
            counter1++;
        }
    }
    for(i=0;i<size;i++)
    {
        cout << arr1[i] <<" ";
    }


    O(n^2)->time Complexity O(1)->Auxiliary space
    for(int i=size-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if(arr[i]>0){
                break;
            }
            else{
                if(arr[j]>0){
                    int temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                    break;
                }
            }
        }
    }

    for(i=0;i<size;i++)
    {
        cout << arr[i] <<" ";
    }

    */
    return 0;
}