#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cout<<"Enter Three Numbers : ";
    cin>>a>>b>>c;
    if(a>b && a>c)
    cout<<"Maximum among three is "<<a;
    else if(b>a && b>c)
    cout<<"Maximum among three is "<<b;
    else
    cout<<"Maximum among three is "<<c;
    return 0;
}