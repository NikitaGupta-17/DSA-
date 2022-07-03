#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}node;
node* head = NULL;

void insert(int x,int y)
{
	int i=1;
	node *ptr=head;
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data=x;
	newnode->next=NULL;
	if(ptr == NULL && y>1)
	{
		printf("Insertion is not possible\n");
	}
	else if(y==1)
	{
		if(head == NULL)
		{
            head = (node*)malloc(sizeof(node));
            head->next = newnode;
        }
		else
		{
			newnode->next=head->next;
		    head->next = newnode;
		}
	}
	else{
        ptr=head->next;
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
		head->next = ptr->next;
		free(ptr);
		free(pre);
	}
	else{
        ptr=head->next;
		while(i<x && ptr->next!=NULL)
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


void display()
{
    node *ptr;
    if(head == NULL ){
        printf("Empty header linked list\n");
    }
    else{
        ptr = head->next;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
  
int main()
{
    int choice,element,pos;
	//clrscr();
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
			display();
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
	return 0;
	//getch();
  
}