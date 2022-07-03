#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int info;
    int priority;
    struct Queue *next;
}queue;

queue *head=NULL;

void insert(int data,int prior){
    queue *newnode=(queue*)malloc(sizeof(queue));
    newnode->info=data;
    newnode->priority=prior;
    newnode->next=NULL;
    queue *pre,*ptr;
    ptr=head;
    pre=NULL;
    if(head==NULL || prior < head->priority){
        newnode->next=head;
        head=newnode;
    }
    else{
        pre=NULL;
        ptr=head;
        while(ptr!=NULL && ptr->priority <= prior){
            pre=ptr;
            ptr=ptr->next;
        }
        newnode->next=ptr;
        pre->next=newnode;
    }
}

void delete(int info){
    queue *ptr,*pre;
    if(head==NULL){
        printf("Deletion is not possible\n");
    }
    else{
        ptr=head;
        pre=NULL;
        while(ptr->next!=NULL && ptr->info!=info ){
            pre=ptr;
            ptr=ptr->next;
        }
        if(ptr->info!=info){
            printf("deletion is not possible");
        }
        else{
            pre->next=ptr->next;
            ptr->next=NULL;
            free(ptr);
        }
    }
}

void display(){
    queue *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
}

int main(){
    insert(1,1);
    insert(3,2);
    insert(5,4);
    insert(2,1);
    insert(4,5);
    insert(6,3);
    display();
    printf("\n");
    delete(2);
    display();
    return 0;
}