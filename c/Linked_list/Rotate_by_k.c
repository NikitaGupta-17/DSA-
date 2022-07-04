#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *head = NULL;

void insert(int x, int y);
void Delete(int x);
void traverse();
void Rotate(int k);

int main()
{
	int choice,element,pos;
	printf("Enter your choice :-\n");
	printf("1-To insert node to linked list\n");
	printf("2-To delete node from linked list\n");
	printf("3-To traverse the linked list\n");
	scanf("%d",&choice);
	while(choice!=0)
	{
		if(choice == 1)
		{
			printf("Enter the element you want to insert : ");
			scanf("%d",&element);
			printf("Enter the position at which it is to be inserted : ");
			scanf("%d",&pos);
			insert(element,pos);
		}
		else if(choice == 2)
		{
			printf("Enter the position of element to be deleted : ");
			scanf("%d",&pos);
			Delete(pos);
		}
		else if(choice == 3)
		{
			traverse();
		}
		else{
			printf("Wrong Choice\n");
		}
		printf("Enter your choice :-\n");
		printf("0-To exit\n");
	    printf("1-To insert node to linked list\n");
	    printf("2-To delete node from linked list\n");
	    printf("3-To traverse the linked list\n");
	    scanf("%d",&choice);
	}
    Rotate(2);
    traverse();
	return 0;
	//getch();
}

void insert(int x,int y)
{
	int i=1;
	node *ptr;
	node *newnode = (node*)malloc(sizeof(node));
	ptr=head;
	newnode->data=x;
	newnode->next=NULL;
	if(ptr == NULL && y>1)
	{
		printf("Insertion is not possible\n");
	}
	else if(y==1)
	{
		if(head == NULL)
		head = newnode;
		else
		{
			newnode->next=head;
		    head = newnode;
		}
	}
	else{
		while(i<(y-1) && ptr->next!=NULL)
		{
			ptr=ptr->next;
			i++;
		}
		if(i==(y-1))
		{
			newnode->next=ptr->next;
			ptr->next=newnode;
		}
		else{
			printf("Insertion is not possible\n");
		}
	}
}

void Delete(int x){
	int i=1;
	node *ptr,*pre;
	ptr=head;
	pre=NULL;
	if(head == NULL)
	printf("Underflow\n");
	else if(x==1)
	{
		head = ptr->next;
		free(ptr);
		free(pre);
	}
	else{
		while(i<=(x-1) && ptr->next!=NULL)
		{
			pre=ptr;
			ptr=ptr->next;
			i++;
		}
		if(i==x)
		{
			pre->next =ptr->next;
			free(ptr);
		}
		else
		{
			printf("Deletion is not possible\n");
		}
	}
}

void traverse()
{
	node *ptr=head;
	if(ptr==NULL){
		printf("Empty Linked List\n");
	}
	else{
		printf("Linked List : ");
		while(ptr!=NULL)
		{
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void Rotate(int k){
    node *temp;
    node* ptr=head;
    int t,size=0;
    while(ptr->next!=NULL){
        size++;
        ptr=ptr->next;
    }
    temp=head;
    t=0;
    while(t<size-k){
        temp=temp->next;
        t++;
    }
    ptr->next=head;
    head=temp->next;
    temp->next=NULL;

}
