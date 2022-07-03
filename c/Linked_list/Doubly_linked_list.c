#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *pre;
    struct Node *next;
}node;

node *head=NULL;

void insert(int x,int pos){
    int i;
    node *ptr;
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->pre=NULL;
    if(head==NULL && pos>1){
        printf("Insertion is not possible\n");
    }
    else if(pos==1){
        newnode->next=head;
        if(head!=NULL)
        head->pre=newnode;
        head=newnode;
    }
    else{
        ptr=head;
        i=1;
        while(i<pos && ptr->next!=NULL){
            ptr=ptr->next;
            i++;
        }
        if(i==pos){
            ptr->pre->next=newnode;
            newnode->pre=ptr->pre;
            newnode->next=ptr;
            if(newnode->next!=NULL){
                ptr->pre=newnode;
            }
        }
        else if(ptr->next==NULL && i==pos-1){
            ptr->next=newnode;
            newnode->pre=ptr;
        }
        else{
            printf("Insertion is not possible\n");
        }
    }
}

void Delete(int pos){
    int i;
    node *ptr;
    ptr=head;
    if(head==NULL){
        printf("Deletion is not possible\n");
    }
    else if(pos==1){
        head=head->next;
        free(ptr);
    }
    else{
        i=1;
        while(i<pos && ptr->next!=NULL){
            ptr=ptr->next;
            i++;
        }
        if(i==pos){
            ptr->pre->next=ptr->next;
            if(ptr->next!=NULL)
            ptr->next->pre=ptr->pre;
            free(ptr);
        }
        else{
            printf("Deletion is not possible\n");
        }
    }
}

void display(){
    node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    insert(2,1);
    insert(1,1);
    insert(3,3);
    insert(4,3);
    insert(5,5);
    display();
    Delete(3);
    display();
    Delete(1);
    insert(7,1);
    display();
    Delete(4);
    display();
    // Delete(4);
    // display();
}