/*
Fascinating Number: When a number( 3 digits or more ) is multiplied by 2 and 3, and when both these products are
concatenated with the original number, then it results in all digits from 1 to 9 present exactly once. There could
be any number of zeros and are ignored.
*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number : ";
    cin >> num;
    string str;
    if(num < 100)
    cout << "Not a fascinating number ";
    else
    {
        str = to_string(num)+to_string(num*2)+to_string(num*3);
        int count =0;
        sort(str.begin(),str.end());
        cout<<str<<endl;
        char c='1';
        for(int i=0; str[i] ;i++){
            if(str[i]==c){
                count++;
                c++;
            }
        }
        if(count == 9)
        cout << "It is a fascinating number";
        else
        cout << "Not a fascinating number";
    }
    return 0;
}
/* sorting function
for(int i =0 ; str[i] ; i++)
{
    for(int j=i+1 ; str[j] ; j++){
        if(str[i]>str[j]){
            char c =str[i];
            str[i]=str[j];
            str[j]=c;
        }
    }
}
*/

//alternate method
/*#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int num,num1,num2;
    cout << "Enter a number : ";
    cin >> num;
    string str;
    if(num < 100)
    cout << "Not a fascinating number ";
    else
    {
        int concatinatenum = num;
        num1 = num*2;
        num2 = num*3;
        concatinatenum = concatinatenum*pow(10,int(log10(num1)+1)) + num1;
        concatinatenum = concatinatenum*pow(10,int(log10(num2)+1)) + num2;
        str = to_string(concatinatenum);
        int count =0;
        for(int i =0 ; str[i] ; i++)
        {
            for(int j=i+1 ; str[j] ; j++){
                if(str[i]>str[j]){
                    char c =str[i];
                    str[i]=str[j];
                    str[j]=c;
                }
            }
        }
        char c='1';
        for(int i =0 ; str[i] ; i++)
        {
            if(str[i] == c)
            count++;
            c++;
        }
        if(count == 9)
        cout << "It is a fascinating number";
        else
        cout << "Not a fascinating number";
    }
    return 0;
}*/