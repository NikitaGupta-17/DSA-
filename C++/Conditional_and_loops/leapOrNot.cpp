#include<iostream>
using namespace std;
int main()
{
	int yr;
	cout<<"Enter a year : ";
	cin>>yr;
	if((yr%4==0 && yr%100!=0) || yr%400==0) 
	{
        cout<<"LEAP YEAR";
	}
	else
    {
        cout<<"NOT A LEAP YEAR";
    }
    return 0;
}