#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *head = NULL;

void insert(int x, int y);
void Delete(int x);
void traverse();
void swap();

int main()
{
	int choice,element,pos;
	//clrscr();
	printf("Enter your choice :-\n");
	printf("1-To insert node to linked list\n");
	printf("2-To delete node from linked list\n");
	printf("3-To traverse the linked list\n");
    printf("4-To swap Alternate elements\n");
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
        else if(choice==4)
        {
            swap();
        }
		else{
			printf("Wrong Choice\n");
		}
		printf("Enter your choice :-\n");
		printf("0-To exit\n");
	    printf("1-To insert node to linked list\n");
	    printf("2-To delete node from linked list\n");
	    printf("3-To traverse the linked list\n");
        printf("4-To swap Alternate elements\n");
	    scanf("%d",&choice);
	}
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

void swap()
{
    node *ptr,*ptr1,*temp;
    int count=0;
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr1=ptr->next;
        if(ptr==head)
        {
            ptr->next=ptr1->next;
            ptr1->next=ptr;
            head = ptr1;
            temp=ptr;
            ptr=ptr1;
            ptr1=temp;
        }
        else{
            if(count%2==0)
            {
                ptr->next=ptr1->next;
                ptr1->next=ptr;
            }
            else
            {
                ptr->next=ptr1->next;
                ptr1->next=ptr;
                temp=ptr;
                ptr=ptr1;
                ptr1=temp;
            }
        }
        if(ptr->next!=NULL)
        {
            ptr=ptr->next->next;
        ptr1=ptr1->next->next;
        count++;
        }
    }

}