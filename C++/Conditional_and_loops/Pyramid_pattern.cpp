#include<iostream>
using namespace std;
int main()
{
	int i,j,rows,space;
	cout<<"Enter the number of rows : ";
	cin>>rows;
	for(i=1;i<=rows;i++)
	{
	for(space=1;space<=rows-i;space++)
	{
		cout<<" ";
	}
	for(j=0;j!=2*i-1;j++)
	{
		cout<<"*";
	}
	cout<<endl;
	}
    return 0;
}