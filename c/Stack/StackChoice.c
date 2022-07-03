#include<stdio.h>
#include<limits.h>
#define MAX 4

int stk[MAX];
int top=-1;
//push
int push(int t){
    if(top>=MAX-1)
    {
        printf("Stack overflow\n");
        return 0;
    }
    else
    {
        stk[++top] = t;
        return 1;
    }
}
    //pop
int pop()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
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

int isEmpty()
{
    return (top<0);
}
    //peek(top)
int peek()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    return stk[top];
}

int main()
{
    int element,choice,temp;
    printf("Enter choice :\n");
    printf("1-push 2-pop 3-peek\n");
    scanf("%d",&choice);
    while(choice!=0)
    {
    	if(choice==1)
    	{
            printf("Enter Element :");
            scanf("%d",&element);
            temp=push(element);
		}
        else if(choice==2)
        {
        	pop();
        	printf("\n");
		}
		else if(choice == 3)
		{
			temp=peek();
            if(temp!=INT_MAX)
			printf("%d\n",temp);
		}
		else if(choice == 0)
		{
			break;
		}
		else
		{
			printf("Invalid Choice\n");
		}
		printf("Enter choice :\n");
        printf("0-To Exit 1-push 2-pop 3-peek\n");
        scanf("%d",&choice);
	}
    return 0;
}
