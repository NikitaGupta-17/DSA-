#include<stdio.h>
#include<limits.h>

int qe[5],qe1[5];
int front=-1;
int front1=-1;
int rear=-1;
int rear1=-1;

int pop() //for Q1
{
    if(rear<0)
    {
        printf("Stack underflow\n");
        return INT_MAX;
    }
    else
    {
        int temp = qe[front];
        front++;
        if(front>4)
        {
            front=-1;
            rear=-1;
        }
        return temp;
    }
}

void push(int x) //for Q1
{
    if(rear>=4)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int i;
        for(i=0;i<=rear;i++)
        {
            qe1[++rear1]=qe[front++];
        }
        front1++;
        front=-1;
        rear=-1;
        qe[++front]=x;//insertion in Q1
        rear++;
        for(i=0;i<=rear1;i++)
        {
            qe[++rear]=qe1[front1++];
        }
        front1=-1;
        rear1=-1;
    }
}

int main()
{
    int choice,element,temp;
    printf("Enter your choice - \n");
    printf("1-Push \n2-Pop\n");
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
            printf("Pop element = %d\n",temp);
        }
        else if(choice == 0)
        {
            break;
        }
        else{
            printf("Invalid Choice\n");
        }
        printf("Enter your choice - \n");
        printf("0-To exit \n1-Push \n2-Pop\n");
        scanf("%d",&choice);
    }
    return 0;
}