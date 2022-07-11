#include<iostream>
using namespace std;
void removeRepeated(int size,int a[]);

int main()
{
    int size,size1,i,j,temp=-1;
    cout<<"Enter the size of First Array : ";
    cin>> size;
    int arr[size];
    cout<<"Enter the Elements of First Array : ";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
       
    cout<<"Enter the size of Second Array : ";
    cin>> size1;
    int arr1[size1];
    cout<<"Enter the Elements of Second Array : ";
    for(i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }
   
    int u[size +size1];

    // Intersection of Arrays 

    cout<<"Intersection of Arrays : ";

    for(i=0;i<size;i++)
    {
        for(j=0;j<size1;j++)
        {
            if(arr[i]==arr1[j])
            {
                cout<<arr[i]<<" ";
                arr1[j] = temp;
                break;
            }
        }
    }

    //Union of Arrays 
    j=0;

    cout<<endl<<"Union of Arrays : ";

    for(i=0;i<size;i++)
    {
        u[j] = arr[i];
        j++;
    }
    for(i=0;i<size1;i++)
    {
        u[j]=arr1[i];
        j++;
    }
    removeRepeated(j,u);
    return 0;
}


 void removeRepeated(int size , int a[])
 {
    int i,j,k;
    for(i=0; i< size ; i++)
    {
        for(j=i+1;j<(size) ;)
        {
            if(a[i] == a[j])
            {
                for(k=j;k < size ;k++)
	            a[k]=a[k+1];
                size--;
            }
            else
            j++;
        }
    }
    for(i=0;i<size-1;i++)
    {
        cout<<a[i]<<" ";
    }
}