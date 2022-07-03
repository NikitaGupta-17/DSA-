#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Queue{
    int info;
    int priority;
    struct Queue *next;
}queue;

int count=0;

queue *head=NULL;

void push(int data){
    queue *newnode=(queue*)malloc(sizeof(queue));
    newnode->info=data;
    newnode->priority=++count;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

void pop(){
    queue *ptr;
    if(head==NULL){
        printf("Deletion is not possible\n");
    }
    else{
        ptr=head;
        head=head->next;
        ptr->next=NULL;
        free(ptr);
    }
}

// void display(){
//     queue *ptr=head;
//     while(ptr!=NULL){
//         printf("%d ",ptr->info);
//         ptr=ptr->next;
//     }
// }

int peek(){
    if(head==NULL){
        printf("Empty Stack\n");
        return INT_MAX;    
    }
    else{
        return head->info;
    }
}

int main(){
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
    //display();
    return 0;
}