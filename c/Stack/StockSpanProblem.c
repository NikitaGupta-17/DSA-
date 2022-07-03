#include<stdio.h>
#define MAX 10

int stk[MAX];
int top=-1;
int push(int t){
    if(top>=MAX-1)
    {
        printf("Stack overflow");
        return 0;
    }
    else
    {
        stk[++top] = t;
        return 1;
    }
}
int pop()
{
    if(top<0)
    {
        printf("Stack Underflow");
        return 0;
    }
    else
    {
        int l = stk[top];
        top--;
        return l;
    }
}

int isEmpty()
{
    return (top<0);
}
int peek()
{
    return stk[top];
}

int Count(int size, int t)
{
    int i,count=1;
    if(t==0){
        return 1;
    }
    for(i=0;i<size;i++){
        if(stk[i-1]<stk[i]){
            count++;
            Count(size,i-1);
        }
    }
    return count;
}

int main()
{
    int size,i,temp;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    printf("Enter %d elements of array : ",size);
    for(i=0;i<size;i++){
        scanf("%d",&temp);
        push(temp);
    }
    for(i=0;i<size;i++){
        temp = Count(size,i);
        printf("%d ",temp);
    }
    
    return 0;
}