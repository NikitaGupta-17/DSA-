#include<stdio.h>
#define MAX 15

char stk[MAX];
int top=-1;

//push
void push(char t){
    if(top>=MAX-1)
    {
        printf("Stack overflow");
    }
    else
    {
        stk[++top] = t;
    }
}
//pop
void pop()
{
    if(top<0)
    {
        printf("Stack Underflow");
    }
    else
    {
        top--;
    }
}
//isEmpty
int isEmpty()
{
    //empty->return 1
    //not empty->return 0
    return (top<0?1:0);
}
//peek(top)
char peek()
{
	if(top<0)
    {
        printf("Stack Underflow");
        return '1';
    }
    return stk[top];
}
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
    else if(c=='-' || c=='+')
    return 1;
    else
    return 0;
}
void infixToPostfix (char* s)
{
	int i;
	char c;
	char post[20];
    int j=0;
    for(i=0;s[i];i++)
    {
        c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        {
        	post[j]=c;
        	j++;
		}
        else if (c=='('){
        	push(c);
		}
        else if(c==')')
        {
            while(!isEmpty() && peek() !='(')
            {
                post[j] = peek();
            	j++;
            	pop();
			}
			if(peek() == '(')
			pop();
			else
			printf("Invalid String\n");
        }
        else {
            //operator
            while(!isEmpty() && prec(peek())>=prec(c))
            {
            	post[j]=peek();
            	j++;
            	pop();
			}
            push(c);
        }
    }
    while(!isEmpty()){
        post[j]=peek();
        j++;
        pop();
    }
    post[j]='\0';
    
    printf("Postfix string : %s",post);
}

int main()
{
    //infixToPostfix("a+b*c-d");
    //a*(b+c*d)+e
    char t[20];
    printf("Enter the infix string : ");
    scanf("%s",t);
    infixToPostfix(t);
    return 0;
}