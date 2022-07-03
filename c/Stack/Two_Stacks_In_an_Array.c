#include<stdio.h>
#include<limits.h>
#define Max 5

int stk[Max];
int stk1[Max];
int top=-1;
int top1=Max;

//Stack1

//push
void push(int t){
    if(top+1==top1){
        printf("Stack Overflow\n");
    }
    else{
        stk[++top]=t;
    }
}

//pop
int pop(){
    int temp;
    if(top==-1){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    else{
        temp=stk[top];
        top--;
        return temp;
    }
}

//isEmpty
int isEmpty(){
    return (top<0 && top1!=0);
}

//peek
int peek(){
    if(top==-1){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    else{
        return stk[top];
    }
}

//Stack2

//push
void push1(int t){
    if(top1==top+1){
        printf("Stack Overflow\n");
    }
    else{
        stk1[--top1]=t;
    }
}

//pop
int pop1(){
    int temp;
    if(top1==Max){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    else{
        temp=stk1[top1];
        top++;
        return temp;
    }
}

//isEmpty
int isEmpty1(){
    return (top1>Max-1 && top!=Max-1);
}

//peek
int peek1(){
    if(top1==Max){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    else{
        return stk1[top1];
    }
}

int main()
{
    int element,choice,temp,temp1,i=0;
    printf("Enter choice :\n");
    printf("For first Stack \n1-push  \n2-pop \n3-peek \nFor second Stack \n4-push \n5-pop \n6-peek\n");
    scanf("%d",&choice);
    while(choice!=0)
    {
    	if(choice==1)
    	{
            printf("Enter Element :");
            scanf("%d",&element);
            push(element);
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
        else if(choice==4)
    	{
            printf("Enter Element :");
            scanf("%d",&element);
            push1(element);
		}
        else if(choice==5)
        {
        	pop1();
        	printf("\n");
		}
		else if(choice == 6)
		{
			temp1=peek1();
            if(temp1!=INT_MAX)
			printf("%d\n",temp1);
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
        printf("0-To Exit \nFor first Stack \n1-push  \n2-pop \n3-peek \nFor second Stack \n4-push \n5-pop \n6-peek\n");
        scanf("%d",&choice);
	}
    return 0;
}
