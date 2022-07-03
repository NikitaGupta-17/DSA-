#include <stdio.h>
//#include<conio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

node *head = NULL;
node *head1 = NULL;

void insert(int x, int y);
void Delete(int x);
void traverse();
void insert1(int x, int y);
void Delete1(int x);
void traverse1();
void merging();

int main()
{
	insert(1, 1);
	insert(3, 2);
	insert(4, 3);
	insert(5, 4);
	insert(2, 5);
	traverse();
	insert1(7, 1);
	insert1(8, 2);
	insert1(9, 3);
	insert1(10, 4);
	insert1(11, 5);
	traverse1();
	merging();

	return 0;
	//getch();
}

void insert(int x, int y)
{
	int i = 1;
	node *ptr;
	node *newnode = (node *)malloc(sizeof(node));
	ptr = head;
	newnode->data = x;
	newnode->next = NULL;
	if (ptr == NULL && y > 1)
	{
		printf("Insertion is not possible");
	}
	else if (y == 1)
	{
		if (head == NULL)
			head = newnode;
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	else
	{
		while (i < (y - 1) && ptr->next != NULL)
		{
			ptr = ptr->next;
			i++;
		}
		if (i == (y - 1))
		{
			newnode->next = ptr->next;
			ptr->next = newnode;
		}
		else
		{
			printf("Insertion is not possible");
		}
	}
}

void Delete(int x)
{
	int i = 1;
	node *ptr, *pre;
	ptr = head;
	pre = NULL;
	if (head == NULL)
		printf("Underflow\n");
	else if (x == 1)
	{
		head = ptr->next;
		free(ptr);
		free(pre);
	}
	else
	{
		while (i <= (x - 1) && ptr->next != NULL)
		{
			pre = ptr;
			ptr = ptr->next;
			i++;
		}
		if (i == x)
		{
			pre->next = ptr->next;
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
	node *ptr = head;
	if (ptr == NULL)
	{
		printf("Empty Linked List\n");
	}
	else
	{
		printf("Linked List : ");
		while (ptr != NULL)
		{
			printf("%d->", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void insert1(int x, int y)
{
	int i = 1;
	node *ptr;
	node *newnode = (node *)malloc(sizeof(node));
	ptr = head1;
	newnode->data = x;
	newnode->next = NULL;
	if (ptr == NULL && y > 1)
	{
		printf("Insertion is not possible");
	}
	else if (y == 1)
	{
		if (head1 == NULL)
			head1 = newnode;
		else
		{
			newnode->next = head1;
			head1 = newnode;
		}
	}
	else
	{
		while (i < (y - 1) && ptr->next != NULL)
		{
			ptr = ptr->next;
			i++;
		}
		if (i == (y - 1))
		{
			newnode->next = ptr->next;
			ptr->next = newnode;
		}
		else
		{
			printf("Insertion is not possible");
		}
	}
}

void Delete1(int x)
{
	int i = 1;
	node *ptr, *pre;
	ptr = head1;
	pre = NULL;
	if (head1 == NULL)
		printf("Underflow\n");
	else if (x == 1)
	{
		head1 = ptr->next;
		free(ptr);
		free(pre);
	}
	else
	{
		while (i <= (x - 1) && ptr->next != NULL)
		{
			pre = ptr;
			ptr = ptr->next;
			i++;
		}
		if (i == x)
		{
			pre->next = ptr->next;
			free(ptr);
		}
		else
		{
			printf("Deletion is not possible\n");
		}
	}
}

void traverse1()
{
	node *ptr = head1;
	if (ptr == NULL)
	{
		printf("Empty Linked List\n");
	}
	else
	{
		printf("Linked List : ");
		while (ptr != NULL)
		{
			printf("%d->", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void merging()
{
	node *ptr1, *ptr2, *ptr3;
	int temp;
	node *ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = head1;
	ptr1 = head;
	while (ptr1 != NULL)
	{
		ptr2 = ptr1->next;
		while (ptr2 != NULL)
		{
			if (ptr1->data > ptr2->data)
			{
				temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
				ptr2 = ptr2->next;
			}
			else
			{
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
	ptr3 = head;
	printf("Linked List : ");
	while (ptr3 != NULL)
	{
		printf("%d->", ptr3->data);
		ptr3 = ptr3->next;
	}
	printf("\n");
}