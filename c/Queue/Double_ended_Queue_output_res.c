#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    struct Node *next;
    int data;
}node;
node *front=NULL;
node *rear=NULL;

//output restricted(insertion -> front / rear , deletion -> front)

//insertion from rear
void enqueue(int x){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        newnode->next=front;
    }
}
//insertion from front
void enqueue1(int x){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        newnode->next=front;
        front=newnode;
    }
}

//deletion from front end
int dequeue(){
    int data;
    node *ptr;
    if(front==NULL && rear==NULL){
        printf("Queue Underflow\n");
        return INT_MAX;
    }
    else{
        data=front->data;
        if(rear==front){
            ptr=front;
            rear=NULL;
            front=NULL;
        }
        else{
            if(front->next==rear){
                ptr=front;
                rear->next=rear;
                front=rear;
                ptr->next=NULL;
            }
            else{
                rear->next=front->next;
                ptr=front;
                front=front->next;
                ptr->next=NULL;
            }
        }
        free(ptr);
        return data;
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
    printf("1-Enqueue from rear \n2-Enqueue from front \n3-Dequeue\n4-Peek\n");
    scanf("%d",&choice);
    while(choice!=0)
    {
        if(choice==1)
        {
            printf("Enter the element to be inserted : ");
            scanf("%d",&element);
            enqueue(element);
        }
        else if(choice==2)
        {
            printf("Enter the element to be inserted : ");
            scanf("%d",&element);
            enqueue1(element);
        }
        else if(choice == 3)
        {
            temp=dequeue();
            if(temp!=INT_MAX)
            printf("%d\n",temp);
        }
        else if (choice == 4)
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
        printf("0-To Exit \n1-Enqueue from rear \n2-Enqueue from front \n3-Dequeue\n4-Peek\n");
        scanf("%d",&choice);
    }
    return 0;
}
