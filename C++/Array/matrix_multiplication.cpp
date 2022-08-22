#include<iostream>
using namespace std;
int main()
{
	int i,j,k,sum=0,m,n,n1,m1;
	cout<<"Enter no. of rows for 1 matrix :";
	cin>>m;
	cout<<"Enter no. of columns for 1 matrix :";
	cin>>n;
	int a[m][n];
	cout<<"Enter elements of 1 matrix :\n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"Enter element ["<<i<<"]["<<j<<"] :";
			cin>>a[i][j];
		}
	}
	cout<<"Enter no. of rows for 2 matrix :";
	cin>>n1;
	cout<<"Enter no. of columns for 2 matrix :";
	cin>>m1;
	int b[n1][m1];
	cout<<"Enter elements of 2 matrix :\n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			cout<<"Enter element ["<<i<<"]["<<j<<"] :";
			cin>>b[i][j];
		}
	}
	if(n != n1)
	cout<<"Multiplication of matrices is not possible";
	else
	{
		int c[m][m1];
	cout<<"-----Array 1-----\n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"-----Array 2-----\n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			cout<<b[i][j]<<"\t";
		}
		cout<<endl;
	}
    for(i=0;i<m;i++)
	{
		for(j=0;j<m1;j++)
		{
			for(k=0;k<n;k++)
			{
				sum+=a[i][k]*b[k][j];
		    }
		    c[i][j]=sum;
		    sum=0;
		}
	}
	cout<<"Product of the matrices :\n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<m1;j++)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
    }
    return 0;
}
