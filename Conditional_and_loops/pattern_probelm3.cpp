#include<iostream>
using namespace std;

int main(){
    int rows,temp=1;
    char c='A';
    cout<<"Enter number of rows : ";
    cin>>rows;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<i;j++){
            cout<<" ";
        }
        for(int j=1;j<=2*(rows-i)+1;j++){
            if(j%2!=0){
                cout<<temp<<" ";
                temp++;
            }
            else{
                cout<<c<<" ";
                c++;
            }
        }
        cout<<endl;
    }
    return 0;
}