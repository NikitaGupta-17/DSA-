//O(1) 
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct Stack{
    int element,min_element;
    struct Stack *next;
}stack;

int min=INT_MAX;

stack *top=NULL;

void push(int x){
    stack *newnode=(stack*)malloc(sizeof(stack));
    newnode->element=x;
    newnode->min_element=min;
    newnode->next=NULL;
    if(top==NULL){
        top=newnode;
        newnode->min_element=x;
        min=x;
    }
    else{
        newnode->next=top;
        top=newnode;
        if(min>newnode->element){
            min=newnode->element;
            newnode->min_element=min;
        }
    }
}

int pop(){
    int data;
    stack *ptr;
    if(top==NULL){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    else{
        ptr=top;
        data=ptr->element;
        top=top->next;
        ptr->next=NULL;
        free(ptr);
        return data;
    }
}

int peek(){
    if(top==NULL){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    else{
        return top->element;
    }
}

int get_Min(){
    if(top==NULL){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    return top->min_element;
}

int main(){
    int element,choice,temp;
    printf("Enter choice :\n");
    printf("1-push \n2-pop \n3-peek \n4-Get minimum Element\n");
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
		}
		else if(choice == 3)
		{
			temp=peek();
            if(temp!=INT_MAX)
			printf("%d\n",temp);
		}
        else if(choice==4){
            temp=get_Min();
            if(temp!=INT_MAX){
                printf("minimum element : %d \n",temp);
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
        printf("0-To Exit \n1-push \n2-pop \n3-peek \n4-Get minimum Element\n");
        scanf("%d",&choice);
	}
    return 0;
}