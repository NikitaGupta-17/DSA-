#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}node;
node* head=NULL;

void insert(int x,int pos)
{
    node *new_node = (node*)malloc(sizeof(node));
    node *ptr1,*ptr=head;
    int temp=1;
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    if(head==NULL && pos>1)
    printf("Insertion is not possible\n");
    else if(pos==1)
    {
    	if(head == NULL)
        {
        head = new_node;
        new_node->prev = head;
        new_node->next = head;
        }
        else
        {
        	while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
	}
    else
    {
    	while(temp<pos && ptr->next!=head)
        {
            ptr1=ptr;
            ptr=ptr->next;
            temp++;
        }
        if(ptr->next == head && temp == pos-1)
        {
    	ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = head;
        head->prev = new_node;
	    }
	    else if(temp == pos)
        {
    	new_node->next=ptr;
        ptr1->next=new_node;
        new_node->prev=ptr->prev;
        ptr->prev = new_node;
	    }
	    else
	    {
		printf("Insertion is not possible\n");
	    }
	}
}

void delete(int pos)
{
	node *ptr1,*ptr=head;
	int temp =1;
    if(head==NULL)
    printf("Underflow\n");
	else if(pos==1){
        if(ptr->next == head)
        head = NULL;
		else{
            while(ptr->next!=head)
			{
			    ptr=ptr->next;
			}
			ptr->next=head->next;
            ptr1=head->next;
			ptr1->prev = ptr;
			ptr = head;
			head = head->next;
        }
		free(ptr);
	}
	else
    {
    	while(temp<pos && ptr->next!=head)
        {
            ptr1=ptr;
		    ptr=ptr->next;
            temp++;
        }
        if(ptr->next == head && temp == pos)
        {
        	ptr1->next=head;
			head->prev = ptr->prev;
			free(ptr);
	    }
	    else if(ptr->next != head && temp == pos)
        {
        	ptr1->next=ptr->next;
            ptr1=ptr->next;
        	ptr1->prev = ptr->prev;
        	free(ptr);
	    }
	    else
	    {
		printf("Deletion is not possible\n");
	    }
	}
			
}

void display()
{
    node *ptr=head;
    if(head == NULL)
    {
        printf("Empty Doubly Circular linked list\n");
    }
    else{
        while(ptr->next!=head)
        {
            printf("->%d",ptr->data);
            ptr=ptr->next;
        }
        printf("->%d\n",ptr->data);
    }
}


int main()
{
    int choice,value,pos;
	printf("Enter your Choice -\n");
	printf("1- To insert element in doubly circular linked list \n");
	printf("2- To delete element in doubly circular linked list\n");
	printf("3- To traverse element in doubly circular linked list\n");
	scanf("%d",&choice);
	while(choice!=0){
		if(choice == 1){
			printf("Enter the data :");
            scanf("%d",&value);
            printf("Enter the position :");
            scanf("%d",&pos);
            insert(value,pos);
		}
		else if(choice == 2){
			printf("Enter the position :");
            scanf("%d",&pos);
            delete(pos);
		}
		else if(choice == 3){
			display();
		}
		else if(choice == 0)
		{
			break;
		}
        else{
            printf("invalid Choice");
        }
        printf("Enter your Choice -\n");
	    printf("1- To insert element in doubly circular linked list \n");
	    printf("2- To delete element in doubly circular linked list\n");
	    printf("3- To traverse element in doubly circular linked list\n");
	    printf("0 - To exit\n");
	    scanf("%d",&choice);
	}
    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *pre;
}node;

node *head=NULL;

void insert(int x, int y);
void Delete(int x);
void traverse();

int main(){
    insert(2,2);
    insert(2,1);
    insert(1,1);
    traverse();
    insert(3,3);
    traverse();
    insert(4,3);
    traverse();
    Delete(3);
    traverse();
    Delete(1);
    traverse();
    insert(4,3);
    traverse();
    return 0;
}

void insert(int x, int y){
    int i=1;
    node *ptr;
    node *newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->pre=NULL;
    newnode->data=x;
    if(head==NULL && y>1){
        printf("Insertion is not possible\n");
    }
    else if(y==1){
        if(head==NULL){
            head=newnode;
            newnode->next=head;
            newnode->pre=head;
        }
        else{
            ptr=head;
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->pre=ptr;
            newnode->next=head;
            head->pre=newnode;
            head=newnode;
        }
    }
    else{
        ptr=head;
        while(i<(y-1) && ptr->next!=head){
            ptr=ptr->next;
            i++;
        }
        if(i==y-1){
            newnode->next=ptr->next;
            ptr->next->pre=newnode;
            ptr->next=newnode;
            newnode->pre=ptr;
        }
        else{
            printf("Insertion is not possible\n");
        }
    }
}

void Delete(int pos){
    node *temp;
    int i=1;
    node *ptr=head;
    if(ptr==NULL){
        printf("Deletion is not possible\n");
    }
    else if(pos==1){
        if(ptr->next==head)
        head=NULL;
        else{
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=head->next;
            head->next->pre=ptr;
            temp=head;
            head=head->next;
            free(temp);
        }
    }
    else{
        while(ptr->next!=head && i<pos){
            ptr=ptr->next;
            i++;
        }
        if(i==pos){
            ptr->pre->next=ptr->next;
            ptr->next->pre=ptr->pre;
            ptr->next=NULL;
            ptr->pre=NULL;
            free(ptr);
        }
        else{
            printf("Deletion is not possible\n");
        }
    }
}

void traverse(){
    node *ptr=head;
    if(ptr==NULL){
        printf("Empty doubly circular linked list\n");
    }
    else{
        while(ptr->next!=head){
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\n",ptr->data);
    }
}
*/