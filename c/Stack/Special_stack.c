#include<stdio.h>
#include<limits.h>
#define MAX 12

int stk[MAX];
int stk1[MAX];
int top1=-1;
int top=-1;

//special stavk push
int special_stack_push(int t){
    if(top1>=MAX-1)
    {
        printf("Stack overflow\n");
        return 0;
    }
    else
    {
        stk1[++top1] = t;
        return 1;
    }
}
//special stack pop
void special_stack_pop()
{
    if(top1<0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        top1--;
    }
}

//special stack isEmpty
int special_stack_isEmpty()
{
    return (top1<0);
}

//special stack peek(top)
int special_stack_peek()
{
    return stk1[top1];
}

//min element of stack
int minimum(){
    if(special_stack_isEmpty()){
        return INT_MAX;
    }
    return stk1[top1];
}

    //push
int push(int t){
    if(top1==-1 || special_stack_peek()>t){
        special_stack_push(t);
    }
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

    //peek(top)
int peek()
{
    return stk[top];
}

    //pop
int pop()
{
    if(peek()==special_stack_peek()){
        special_stack_pop();
    }
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

int main()
{
    int element,choice,temp,temp1,i=0;
    printf("Enter choice :\n");
    printf("1-push \n2-pop \n3-peek \n4-Min Element Of Stack \n");
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
			temp1=peek();
			printf("%d\n",temp1);
		}
        else if(choice == 4){
            temp1=minimum();
            if(temp1==INT_MAX){
                printf("Empty Stack\n");
            }
            else{
                printf("Minimum Element of input Stack : %d\n",temp1);
            }
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
        printf("0-To Exit \n1-push \n2-pop \n3-peek \n4-Min Element Of Stack \n");
        scanf("%d",&choice);
	}
    return 0;
}
