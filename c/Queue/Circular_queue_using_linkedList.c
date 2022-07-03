#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node
{
   int data;
   struct Node* next;
}node;
node *head=NULL; 
node *front,*rear;


void enqueue(int x)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        front = newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Queue underflow\n");
    }
    else{
        node *temp;
        temp=front;
        front=front->next;
        free(temp);
    }
}

int peek()
{
    if(front==NULL)
    {
        return INT_MAX;
    }
    else
    {
        return front->data;
    }
}

int main()
{
    int choice,element,temp;
    printf("Enter your choice - \n");
    printf("1-Enqueue \n2-Dequeue\n3-Peek\n");
    scanf("%d",&choice);
    while(choice!=0)
    {
        if(choice==1)
        {
            printf("Enter the element to be inserted : ");
            scanf("%d",&element);
            enqueue(element);
        }
        else if(choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            temp = peek();
            if(temp!=INT_MAX)
            {
                printf("%d\n",temp);
            }
            else
            {
                printf("Queue Underflow\n");
            }
        }
        else if(choice == 0)
        {
            break;
        }
        else{
            printf("Invalid Choice\n");
        }
        printf("Enter your choice - \n");
        printf("0-To Exit \n1-Enqueue \n2-Dequeue\n3-Peek\n");
        scanf("%d",&choice);
    }
}
/*#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Queue{
    int data;
    struct Queue *next;
}queue;
queue *front=NULL;
queue *rear=NULL;

void enqueue(int x){
    queue *newnode=(queue*)malloc(sizeof(queue));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

int dequeue(){
    int data;
    queue *ptr;
    if(front==NULL && rear==NULL){
        printf("Queue Underflow\n");
        return INT_MAX;
    }
    else{
        ptr=front;
        data=ptr->data;
        front=front->next;
        if(front==NULL)
        rear=NULL;
        free(ptr);
        return data;
    }
}

int main(){
    long int x;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    printf("Dequeued Element : %d\n",dequeue());
    printf("Dequeued Element : %d\n",dequeue());
    printf("Dequeued Element : %d\n",dequeue());
    printf("Dequeued Element : %d\n",dequeue());
    printf("Dequeued Element : %d\n",dequeue());
    printf("Dequeued Element : %d\n",dequeue());
    x=dequeue();
    if(x!=INT_MAX)
    printf("Dequeued Element : %d\n",x);
    return 0;
}*/