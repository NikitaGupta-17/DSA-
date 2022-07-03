#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Stack{
    int data;
    struct Stack *next;
}stack;

stack *top=NULL;
stack *top1=NULL;
stack *last=NULL;
stack *last1=NULL;

void push(int x){
    stack *newnode =(stack*)malloc(sizeof(stack));
    newnode->data=x;
    newnode->next=NULL;
    if(top==NULL){
        top=newnode;
        last=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}

int pop(){
    int temp;
    stack *ptr;
    if(top==NULL){
        printf("Stack underflow\n");
        return INT_MAX;
    }
    else{
        ptr=top;
        temp=ptr->data;
        top=top->next;
        ptr->next=NULL;
        free(ptr);
        return temp;
    }
}

void push1(int x){
    stack *newnode =(stack*)malloc(sizeof(stack));
    newnode->data=x;
    newnode->next=NULL;
    if(top1==NULL){
        top1=newnode;
        last1=newnode;
    }
    else{
        newnode->next=top1;
        top1=newnode;
    }
}

int pop1(){
    int temp;
    stack *ptr;
    if(top1==NULL){
        printf("Stack underflow\n");
        return INT_MAX;
    }
    else{
        ptr=top1;
        temp=ptr->data;
        top1=top1->next;
        ptr->next=NULL;
        free(ptr);
        return temp;
    }
}

void merge(int a,int b){
    if(a==1 && b==2){
        last->next=top1;
        last=last1;
    }
    else{
        last1->next=top;
        last1=last;
    }
}

void display(){
    stack *ptr=top;
    while(ptr!=last){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}

void display1(){
    stack *ptr=top1;
    while(ptr!=last1){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}

int main(){
    int a=1,b=2;
    int element,choice,temp,temp1,i=0;
    printf("Enter choice :\n");
    printf("1-push in stack 1 \n2-pop from stack 1 \n3-push in stack 2 \n4-pop from stack 2 \n5-merge two stacks\n6-display merge stack\n");
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
        	temp=pop();
            if(temp!=INT_MAX)
            printf("Popped Element : %d\n",temp);
		}
		else if(choice == 3)
		{
			printf("Enter Element :");
            scanf("%d",&element);
            push1(element);
		}
        else if(choice==4){
            temp=pop1();
        	if(temp!=INT_MAX)
            printf("Popped Element : %d\n",temp);
        }
        else if(choice == 5){
            printf("Enter the stack you want first in merge stack : ");
            scanf("%d",&a);
            if(a==1){
                b=2;
                merge(a,b);
            }
            else{
                b=1;
                merge(a,b);
            }
        }
        else if(choice == 6){
            if(a==1)
            display();
            else
            display1();
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
        printf("0-To Exit \n1-push in stack 1 \n2-pop from stack 1 \n3-push in stack 2 \n4-pop from stack 2 \n5-merge two stacks\n6-display merge stack\n");
        scanf("%d",&choice);
	}
    return 0;
}