//Q1 //insertion always at Q1
//Q2

/*void swap() //swap Q1 and Q2
{
    for(int i=front;i<=rear;i++)
    {
        qe1[++rear1]=qe[front++];
        if(front1==-1)
        {
            front1++;
        }
    }
    front=-1;
    rear=-1;
} */


#include<stdio.h>

int qe[5],qe1[5];
int front=-1;
int front1=-1;
int rear=-1;
int rear1=-1;
// void push(int);
// int pop();

void enqueue(int x)
{
    if(rear==5)
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
        front=-1;
        rear=-1;
        qe[++front]=x;
        rear++;
        for(i=0;i<=rear1;i++)
        {
            qe[++rear]=qe1[front1++];
        }
        front1=-1;
        rear1=-1;
    }
    // int i,element;
    // i=0;
    // if(front1==-1)
    // {
    //     qe[++front]=x;
    // }
    // else{
    //     qe[++front]=x;
    //     while(i<=rear1)
    //     {
    //         element=pop();
    //         push(element);
    //         i++;
    //     }
    // }
}

// void swap() //swap Q1 and Q2
// {
//     if(front1==-1)
//     {
//         qe1[++rear]=qe[rear];
//         front1++;
//     }
//     else
//     {
//         for(int i=0;i<=rear1;i++)
//         {
//             qe[++rear]=qe1[front1++];
//         }
//     }
//     front1=-1;
//     rear1=-1;
// } 

int pop() //for Q2
{
    if(front==-1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    else
    {
        int temp = qe[front];
        front++;
        return temp;
    }
}

void push(int x) //for Q1
{
    enqueue(x);
    //swap();
}
// void display()
// {
//     for(int i=0;i<count;i++)
//     {
//         printf("%d ",qe1[i]);
//     }
// }

int main()
{
    
    push(4);
    push(5);
    push(6);
    push(7);
    //display();
    printf("front = %d\n",front);
    printf("%d\n",pop());
    printf("front = %d\n",front);
    printf("%d\n",pop());
    printf("front = %d\n",front);
    printf("%d\n",pop());
    printf("front = %d\n",front);
    printf("%d\n",pop());
    printf("front = %d\n",front);
    printf("%d\n",pop());
    printf("front = %d\n",front);
    printf("%d\n",pop());
    printf("front = %d\n",front);

    return 0;
}