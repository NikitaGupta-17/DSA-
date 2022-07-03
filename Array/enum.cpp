#include<iostream>
using namespace std;
enum bix{
	a=1,b,c
};
int main(){
	int x=c;
	int &y =x;
	int &z=x;
	y=b;
	cout<<z--;
	return 0;
}
