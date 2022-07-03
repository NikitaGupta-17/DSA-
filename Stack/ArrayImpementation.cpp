#include<iostream>
using namespace std;
#define MAX 100

class stack
{
    int stk[MAX];
    int top;
    public:
        stack()
        {
            top=-1;
        }
        //push
        bool push(int t){
            if(top>=MAX-1)
            {
                cout<<"Stack overflow";
                return false;
            }
            else
            {
                stk[++top] = t;
                return true;
            }
        }
        //pop

        int pop()
        {
            if(top<0)
            {
                cout<<"Stack Underflow";
                return 0;
            }
            else
            {
                int l = stk[top];
                top--;
                return l;
            }
        }
        //isEmpty

        bool isEmpty()
        {
            return (top<0);
        }
        //peek(top)
        int peek()
        {
            return stk[top];
        }
};
//Stack  Result
//any expression operand goes to result and operator is goes to stack
//(if stack is empty or operator before is of less precedance ,in that cond that operator will go by emptying stack)
//Infix : a+b    a+b*c-d
//Postfix : ab+  abc*+d-
//Prefix : +ab   +a*b-cd

int prec(char c)
{
    if(c=='^')
    return 3;
    else if(c=='/' || c=='*')
    return 2;
    else if('-' || c=='+')
    return 1;
    else
    return -1;
}

string infixToPostfix (string s)
{
    string postfix;
    stack stk;
    for(int i=0;s[i];i++)
    {
        char c = s[i];
        cout<<c<<endl;
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
            postfix+=c;
        else if (c=='(')
            stk.push(c);
        else if(c==')'){
            while(stk.peek() != '(')
            postfix+= (char)stk.pop();
            stk.pop();
        }
        else {
            //operator
            while(!stk.isEmpty() && prec(stk.peek())>=prec(c))
                postfix+=(char)stk.pop();
            stk.push(c);
        }
    }
    while(!stk.isEmpty()){
        cout<<stk.pop()<<" ";
    }
    return postfix;

}

int main()
{
    stack st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);
    // st.push(6);
    // st.push(7);
    //cout<< "\nint popped = "<<st.pop();
    // while(!st.isEmpty())
    // {
    //     cout<<st.pop()<<" ";
    // }
    // cout<<endl;
    // if(st.isEmpty())
    // {
    //     cout<<"Stack is empty";
    // }
    cout<< "\n infix to postfix = " << infixToPostfix("a+b*c-d");
    return 0;
}