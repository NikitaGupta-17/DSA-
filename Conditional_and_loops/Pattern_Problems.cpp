#include<iostream>
using namespace std;

int main(){
    int rows;
    cout<<"Enter no. of rows : ";
    cin>>rows;
    char c;
    for(int i=1;i<=rows;i++){
        c='A';
        for(int j=1;j<i;j++){
            cout<<" ";
        }
        for(int j=1;j<=2*(rows-i)+1;j++){
            if(j%2==0){
                cout<<"*";
            }
            else{
                cout<<c;
                c++;
            }
        }
        cout<<endl;
    }
    return 0;
}