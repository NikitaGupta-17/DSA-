#include<stdio.h>
#include<limits.h>
#define MAX 4

int stk1[MAX];
int stk[MAX];
int top=-1;
int top1=-1;
int mid=INT_MAX;

//push1
int push1(int t){
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
    //pop1
int pop1()
{
    if(top1<0)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    else
    {
        int l = stk1[top1];
        top1--;
        return l;
    }
}

//push
int push(int t){
    if(top%2==0){
        mid=top;
    }
    if(top>=MAX-1)
    {
        printf("Stack overflow\n");
        return 0;
    }
    else
    {
        stk[++top] = t;
        if(top==0){
            mid=top;
        }
        return 1;
    }
}
    //pop
int pop()
{
    if(top%2!=0){
        mid=mid-1;
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
    //peek(top)
int peek()
{
    if(top!=-1)
    return stk[top];
    else{
        printf("Stack Underflow\n");
        return INT_MAX;
    }
}

//find mid element
int find_mid_element(){
    if(top==-1){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    else{
        return stk[mid];
    }
}
//delete mid element
int delete_mid_element(){
    int i;
    int temp=stk[mid];
    if(top<0){
        printf("Stack underflow\n");
        return INT_MAX;
    }
    else{
        if(mid%2!=0){
        while(top!=mid){
            push1(pop());
        }
        mid=mid-1;
        pop();
        while(top1!=-1){
            push(pop1());
        }
    }
    else{
        while(top!=mid){
            push1(pop());
        }
        mid=mid-1;
        pop();
        if(top1!=-1){
            push(pop1());
            mid=top;
            while(top1!=-1){
              push(pop1());
           }
        }
    }
    return temp;
    }
}

int main()
{
    int element,choice,temp,temp1,i=0;
    printf("Enter choice :\n");
    printf("1-push \n2-pop \n3-peek \n4-Find Middle Element \n5-Delete Middle Element\n");
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
            if(temp1!=INT_MAX)
			printf("%d\n",temp1);
		}
        else if(choice==4){
            temp1=find_mid_element();
            if(temp1!=INT_MAX){
                printf("Middle Element : %d \n",temp1);
            }
        }
        else if(choice == 5){
            temp1=delete_mid_element();
            if(temp1!=INT_MAX){
                printf("Middle Element Deleted : %d\n",temp1);
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
        printf("0-To Exit \n1-push \n2-pop \n3-peek \n4-Find Middle Element \n5-Delete Middle Element\n");
        scanf("%d",&choice);
	}
    return 0;
}
