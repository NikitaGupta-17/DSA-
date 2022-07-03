#include<iostream>
using namespace std;

int main()
{
    int count=1;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s.at(i)>=65 &&s.at(i)<=90)
        count++;
    }
    cout<<count;
    return 0;
}