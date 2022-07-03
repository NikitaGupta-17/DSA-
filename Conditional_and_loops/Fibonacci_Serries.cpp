#include<iostream>
using namespace std;
int main()
{
	int i,n,next,fist=0,second=1;
	cout<<"Enter a number upto which you want fibonacci series : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		if(i<=1)
		next=i;
		else
		{
			next=fist+second;
			fist=second;
			second=next;
		}
		cout<<next<<"\t";
	}
    return 0;
}