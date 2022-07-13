#include<iostream>
using namespace std;
int main()
{
    long int x,y,i;
    char z;
    while(0<1)
    {
		cout<<"Please enter a number"<<endl;
	    cin>>x;
	    y=1;
	    i=1;
	    if(x==0)
	    y=1;
	    else
	    if(x<0){
			cout<<"Please enter a positive number "<<endl;	
	    }
	    else{
			while(i<=x)
	        {
				y=y*i;
		        i++;
	        }
	        cout<<"the value of the factorial of this number is :"<<y<<endl;
        }
        cout<<"do you want to continue the process (y,n) ?"<<endl;
        cin>>z;
        if(z=='n'||z=='N')
        break;
    }
	return 0;
}
