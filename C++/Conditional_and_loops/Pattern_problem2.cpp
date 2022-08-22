#include<iostream>
using namespace std;

int main(){
    int rows;
    cout<<"Enter no. of rows : ";
    cin>>rows;
    int arr[rows*rows],k=0,j,i=2;
    while(k!=(rows*rows)){
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }
        }
        if(j==i || i==2){
            arr[k]=i;
            k++;
        }
        i++;
    }
    k=0;
    for(int i=1;i<=rows;i++){
        for(j=1;j<i;j++){
            cout<<"  ";
        }
        for(j=1;j<=2*(rows-i)+1;j++){
            cout<<arr[k]<<"*";
            k++;
        }
        cout<<endl;
    }
    return 0;
}