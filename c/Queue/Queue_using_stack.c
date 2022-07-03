#include <stdio.h>
#include<limits.h>
#define N 4
int stk1[N],stk2[N];
int top1=-1;
int top2=-1;
int count=0;

int push1(int x){
    if(top1==N-1){
        printf("Stack Overflow\n");
        return INT_MAX;
    }
    else{
        stk1[++top1]=x;
        return 0;
    }
}

int pop1(){
    int x;
    if(top1==-1){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    else{
        x=stk1[top1];
        top1--;
        return x;
    }
}

void push2(int x){
    if(top2==N-1){
        printf("Stack Overflow\n");
    }
    else{
        stk2[++top2]=x;
    }
}

int pop2(){
    int x;
    if(top2==-1){
        printf("Stack Underflow\n");
        return INT_MAX;
    }
    else{
        x=stk2[top2];
        top2--;
        return x;
    }
}

void enqueue(int x){
    int i;
    i=push1(x);
    if(i!=INT_MAX)
    count++;
}

void dequeue(){
    if(top1==-1 && top2==-1)
    {
        printf("Queue underflow \n ");
    }
    else
    {
        int element,x,i;
        for(i=0;i<count;i++){
        element=pop1();
        if(element==INT_MAX)
        break;
        push2(element);
        }
        x=pop2();
        printf("Dequeued Element = %d\n",x);
        count--;
        for(i=0;i<count;i++){
        element=pop2();
        push1(element);
        }
    }
}

int main() {
    int choice,element,temp;
    printf("Enter your choice - \n");
    printf("1-Enqueue \n2-Dequeue\n");
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
        else if(choice == 0)
        {
            break;
        }
        else{
            printf("Invalid Choice\n");
        }
        printf("Enter your choice - \n");
        printf("0-To Exit \n1-Enqueue \n2-Dequeue\n");
        scanf("%d",&choice);
    }
   
}
/*#include<stdio.h>
#include<limits.h>
#define N 10

int qe1[N],qe[2];
int front1=-1;
int rear1=-1;
int front2=-1;
int rear2=-1;

void enqueue(int x){
    if(front1==-1 && rear1==-1){
        front1++;
        rear1++;
        qe1[rear1]=x;
    }
    else if(front1==0 && rear1==N-1)
    {
        printf("queue overflow\n");
    }
    else
    {
        qe1[++rear1]=x;
    }
}

int dequeue(){
    int x;
    if(front1==-1 && rear1==-1){
        printf("Queue Underflow\n");
        return INT_MAX;
    }
    else{
        x=qe1[front1];
        front1++;
    }
    return x;
}

void enqueue1(int x){
    if(front2==-1 && rear2==-1){
        front2++;
        rear2++;
        qe2[rear2]=x;
    }
    else if(front2==0 && rear2==N-1)
    {
        printf("queue overflow\n");
    }
    else
    {
        qe2[++rear2]=x;
    }
}

int dequeue1(){
    int x;
    if(front2==-1 && rear2==-1){
        printf("Queue Underflow\n");
        return INT_MAX;
    }
    else{
        x=qe2[front2];
        front2++;
    }
    return x;
}

void push(int x){
    enqueue(x);
}
int pop(){
    int element,x;
    if(front1==-1 && front2==-1)
    printf("stack Underflow\n");
    else
    {
        while(front<rear){
            element=dequeue();
            enqueue1(element);
        }
        x=dequeue();
        
    }
    
}

int main(){
    return 0;
}*/