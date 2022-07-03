#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}node;
node* head ;

void insert(int x,int pos)
{
    node *new_node = (node*)malloc(sizeof(node));
    node *ptr1,*ptr=head;
    int temp=1;
    new_node->data = x;
    new_node->next = NULL;
    if(head->next == head && pos>1)
    printf("Insertion is not possible\n");
    else if(pos==1)
    {
    	if(head->next == head)
        {
            head->next = new_node;
            new_node->next = head->next;
        }
        else
        {
            ptr=head->next;
        	while(ptr->next!=head->next)
            {
            ptr=ptr->next;
            }
            ptr->next = new_node;
            new_node->next = head->next;
            head->next = new_node;
        }
	}
    else
    {
        ptr=head->next;
    	while(temp<pos && ptr->next!=head->next)
        {
            ptr1=ptr;
            ptr=ptr->next;
            temp++;
        }
        if(ptr->next == head->next && temp == pos-1)
        {
    	ptr->next = new_node;
        new_node->next = head->next;
	    }
	    else if(temp == pos)
        {
    	new_node->next=ptr;
        ptr1->next=new_node;
	    }
	    else
	    {
		printf("Insertion is not possible\n");
	    }
	}
}

void delete(int pos)
{
	node *ptr1,*ptr=head->next;
	int temp =1;
    if(head->next == head)
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
			free(ptr);
	    }
	    else if(ptr->next != head && temp == pos)
        {
        	ptr1->next=ptr->next;
            ptr1=ptr->next;
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
    node *ptr=head->next;
    if(head == NULL)
    {
        printf("Empty Doubly Circular linked list\n");
    }
    else{
        while(ptr->next!=head->next)
        {
            printf("->%d",ptr->data);
            ptr=ptr->next;
        }
        printf("->%d\n",ptr->data);
    }
}


int main()
{
    head = (node*)malloc(sizeof(node));
    head->next = head;
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