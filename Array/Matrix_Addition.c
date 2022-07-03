#include<stdio.h>
void main()
{
	int a[10][10],b[10][10],c[10][10],i,j,k,m,n,n1,m1;
	printf("Enter no. of rows for 1 matrix :");
	scanf("%d",&m);
	printf("Enter no. of columns for 1 matrix :");
	scanf("%d",&n);
	printf("Enter elements of 1 matrix :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter element [%d][%d] :",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter no. of rows for 2 matrix :");
	scanf("%d",&n1);
	printf("Enter no. of columns for 2 matrix :");
	scanf("%d",&m1);
	printf("Enter elements of 2 matrix :\n");
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			printf("Enter element [%d][%d] :",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	if(m != n1 || n != m1)
	printf("Addition of matrices is not possible");
	else
	{
	printf("-----Array 1-----\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("-----Array 2-----\n");
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
    for(i=0;i<m;i++)
	{
		for(j=0;j<m1;j++)
		{
		    c[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("Sum of the matrices :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m1;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
    }
}
