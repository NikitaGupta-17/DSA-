#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *head=NULL;
node *head1=NULL;
node *head2=NULL;

void insert(int);
void insert1(int);
void display();
void display1();
void merge();
void display2();

int main(){
    int element,choice;
    printf("Enter the elements of first linked list : \n");
    do{
        printf("Enter Element : ");
        scanf("%d",&element);
        insert(element);
        printf("Do you want to insert ?");
        scanf("%d",&choice);
    }while(choice!=0);

    printf("Enter the elements of second linked list : \n");
    do{
        printf("Enter Element : ");
        scanf("%d",&element);
        insert1(element);
        printf("Do you want to insert ?");
        scanf("%d",&choice);
    }while(choice!=0);

    printf("First linked List : ");
    display();

    printf("\nSecond Linked List : ");
    display1();
    printf("\nMerge Linked List : ");
    merge();
    display2();
    return 0;
}

void insert(int x){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    node *ptr=head;
    node *pre=NULL;
    if(head==NULL || x < head->data){
        newnode->next=head;
        head=newnode;
    }
    else if(ptr->data >newnode->data){
        newnode->next=ptr;
        head=newnode;
    }
    else{
        pre=NULL;
        ptr=head;
        while(ptr!=NULL && ptr->data <= x){
            pre=ptr;
            ptr=ptr->next;
        }
        newnode->next=ptr;
        pre->next=newnode;
    }
}

void insert1(int x){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    node *ptr=head1;
    node *pre=NULL;
    if(head1==NULL || x < head1->data){
        newnode->next=head1;
        head1=newnode;
    }
    else if(ptr->data >newnode->data){
        newnode->next=ptr;
        head1=newnode;
    }
    else{
        pre=NULL;
        ptr=head1;
        while(ptr!=NULL && ptr->data <= x){
            pre=ptr;
            ptr=ptr->next;
        }
        newnode->next=ptr;
        pre->next=newnode;
    }
}

void display(){
    node *ptr=head;
    while(ptr!=NULL){
        printf("->%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void display1(){
    node *ptr1=head1;
    while(ptr1!=NULL){
        printf("->%d",ptr1->data);
        ptr1=ptr1->next;
    }
    printf("\n");
}

void merge(){
    node *ptr=head2;
    while(head && head1){
        if(head->data > head1->data){
            if(head2==NULL){
                head2=head1;
                ptr=head1;
            }
            else{
                ptr->next=head1;
                ptr=head1;
            }
            head1=head1->next;
        }
        else if(head->data<head1->data){
            if(head2==NULL){
                head2=head;
                ptr=head;
            }
            else{
                ptr->next=head;
                ptr=head;
            }
            head=head->next;
        }
        else{
            if(head2==NULL){
                head2=head;
                ptr=head;
                head=head->next;
            }
            else{
                ptr->next=head1;
                ptr=head1;
                head1=head1->next;
                ptr->next=head;
                ptr=head;
                head=head->next;
            }
        }
    }
    while(head!=NULL){
        ptr->next=head;
        ptr=head;
        head=head->next;
    }
    while(head1!=NULL){
        ptr->next=head1;
        ptr=head1;
        head1=head1->next;
    }
}

void display2(){
    node *ptr2=head2;
    while(ptr2!=NULL){
        printf("->%d",ptr2->data);
        ptr2=ptr2->next;
    }
    printf("\n");
}

