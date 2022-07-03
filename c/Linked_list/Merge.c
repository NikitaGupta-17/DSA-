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

    printf("\nFirst linked List : ");
    display();

    printf("Second Linked List : ");
    display1();

    printf("Merge linked List : ");
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
    node *ptr1=head;
    node *ptr2=head1;
    while(ptr1 && ptr2){
        node *newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        if(ptr1->data > ptr2->data){
            newnode->data=ptr2->data;
            if(head2==NULL){
                head2=newnode;
            }
            else{
                ptr->next=newnode;
            }
            ptr=newnode;
            ptr2=ptr2->next;
        }
        else if(ptr1->data<ptr2->data){
            newnode->data=ptr1->data;
            if(head2==NULL){
                head2=newnode;
            }
            else{
                ptr->next=newnode;
            }
            ptr=newnode;
            ptr1=ptr1->next;
        }
        else{
            newnode->data=ptr1->data;
            if(head2==NULL){
                head2=newnode;
                ptr=newnode;
                ptr1=ptr1->next;
            }
            else{
                ptr->next=newnode;
                ptr=newnode;
                ptr1=ptr1->next;
            }
        }
    }
    while(ptr1!=NULL){
        node *newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->data=ptr1->data;
        ptr->next=newnode;
        ptr=newnode;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        node *newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->data=ptr2->data;
        ptr->next=newnode;
        ptr=newnode;
        ptr2=ptr2->next;
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