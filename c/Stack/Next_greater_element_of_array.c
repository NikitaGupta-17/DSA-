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

int isEmpty(){
    return (top==NULL);
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

void printNGE(int arr[], int n)
{
    int i = 0;
    int element, next;
    /* push the first element to stack */
    push(arr[0]);
 
    // iterate for rest of the elements
    for (i = 1; i < n; i++) {
        next = arr[i];
 
        if (!isEmpty())
        {
            // if stack is not empty, then pop an element from stack
            element = pop();
 
            /* If the popped element is smaller than next,then a) print the pair b) keep popping while elements 
               are smaller and stack is not empty */
            
            while (element < next) {
                printf("\n %d --> %d", element, next);
                if (isEmpty())
                    break;
                element = pop();
            }
 
            //If element is greater than next, then push the element back
            if (element > next)
                push(element);
        }
 
        // push next to stack so that we can find next greater for it 
        push(next);
    }
 
    /* After iterating over the loop, the remaining elements in stack do not have the next greater 
    element, so print -1 for them */
    while (!isEmpty())
    {
        element = pop();
        next = -1;
        printf("\n %d --> %d", element, next);
    }
}

int main(){
    int size,i;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=(int*)calloc(size,sizeof(int));
    printf("Enter the elements of array : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("---------------------------------------------\n");
    printf("Next greater Elements of Array Elements are :\n");
    printNGE(arr,size);
    return 0;
}