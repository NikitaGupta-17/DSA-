#include<stdio.h>
#include<limits.h>
int front,rear,qe[5];


void enqueue(int x){
     if(front==-1 && rear == -1)
    {
        qe[++rear]=x;
        front++;
    }
    else if(front==rear+1 || (front==0 && rear==4))
    {
        printf("Queue Overflow!\n");
    }
    else if(rear==4){
        rear=0;
        qe[rear]=x;
    }
    else{
            rear++;
            qe[rear]=x;
    }
}
void dequeue()
{
    int x=-1;
    if(front == -1){
        printf("Queue Underflow!\n");
    }
    else if(front==rear)
    {
        x=front;
        front=-1;
        rear=-1;
    }
    else if(front==4)
    {
        x=front;
        front=0;
    }
    else{
        x=front;
        front++;
    }
    if(x!=-1)
    printf("%d\n",qe[x]);
}

int peek()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return INT_MAX;
    }
    else
    {
        return qe[front];
    }
}

int main()
{
    int choice,element,temp;
    front=-1;
    rear=-1;
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
    return 0;
}