#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Queue{
    int data;
    struct Queue *next;
}queue;
queue *front=NULL;
queue *rear=NULL;

int pop(){
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

void insert(int x){
    queue *ptr;
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

void push(int x){
    queue *ptr;
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
        ptr=rear;
        while(front!=ptr){
            insert(pop());
        }
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

int main(){
    int choice,element,temp;
    printf("Enter your choice - \n");
    printf("1-Push \n2-Pop\n3-Peek\n");
    scanf("%d",&choice);
    while(choice!=0)
    {
        if(choice==1)
        {
            printf("Enter the element to be inserted : ");
            scanf("%d",&element);
            push(element);
        }
        else if(choice == 2)
        {
            temp=pop();
            if(temp!=INT_MAX)
            printf("Popped Element : %d\n",temp);
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
                printf("Stack Underflow\n");
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
        printf("0-To Exit \n1-Push \n2-pop \n3-Peek\n");
        scanf("%d",&choice);
    }
    return 0;
}

// #include<stdio.h>
// #include<limits.h>
// #define Max 10;

// int qe[Max];
// int front=-1;
// int rear=-1;

// void enqueue(int x){
//     int i,temp;
//     if(rear==Max-1){
//         printf("Queue Underflow\n");
//     }
//     else{
//         if(front==-1){
//             front+=1;
//             rear+=1;
//             qe[rear]=x;
//         }
//         else{
//            qe[++rear]=x;
//            i=rear;
//            while(i>front){
               
//            }
//            } 
//         }
//     }
// }

