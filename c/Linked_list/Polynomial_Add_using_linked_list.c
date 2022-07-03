#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int pow;
    int coeff;
    struct Node *next;
}node;

node *head = NULL;
node *head1 = NULL;
node *head2 = NULL;

void insert();
void insert1();
void sum();
void insert2(int, int);
void display();
void display1();
void display2();

int main()
{
    insert();
    insert();
    display1();
    insert1();
    insert1();
    display2();
    sum();
    display();
    return 0;
}

void insert()
{
    node *ptr;
    int power,coefficient;
    node *newnode = (node*)malloc(sizeof(node));
    ptr=head;
    printf("Enter the power : ");
    scanf("%d",&power);
    printf("Enter the coeff : ");
    scanf("%d",&coefficient);
    newnode->pow = power;
    newnode->coeff = coefficient;
    newnode->next = NULL;
    if(head == NULL)
    head = newnode;
    else{
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void insert1()
{
    node *ptr;
    int power,coefficient;
    node *newnode = (node*)malloc(sizeof(node));
    ptr=head1;
    printf("Enter the power : ");
    scanf("%d",&power);
    printf("Enter the coeff : ");
    scanf("%d",&coefficient);
    newnode->pow = power;
    newnode->coeff = coefficient;
    newnode->next = NULL;
    if(head1 == NULL)
    head1 = newnode;
    else{
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void sum()
{
    node *ptr,*ptr1;
    int add=0;
    ptr=head;
    ptr1=head1;
    while((ptr!=NULL) && (ptr1!=NULL))
    {
        if(ptr->pow > ptr1->pow)
        {
            insert2(ptr->pow ,ptr->coeff);
            ptr=ptr->next;
        }
        else if(ptr->pow < ptr1->pow)
        {
            insert2(ptr1->pow, ptr1->coeff);
            ptr1=ptr1->next;
        }
        else if(ptr1->pow == ptr->pow)
        {
            add = ptr->coeff + ptr1->coeff;
            insert2(ptr->pow, add);
            ptr=ptr->next;
            ptr1=ptr1->next;
            add=0;
        } 
    }
    if(ptr==NULL)
    {
        while(ptr1){
            insert2(ptr1->pow, ptr1->coeff);
            ptr1=ptr1->next;
        }
    }
    if(ptr1==NULL)
    {
        while(ptr){
            insert2(ptr->pow ,ptr->coeff);
            ptr=ptr->next;
        }
    }
}
void insert2(int Pow, int Coeff)
{
    node *newnode = (node*)malloc(sizeof(node));
    node *ptr=head2;
    newnode->pow = Pow;
    newnode->coeff = Coeff;
    newnode->next = NULL;
    if(head2 == NULL)
    head2 = newnode;
    else{
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void display1()
{
   node *ptr=head;
   printf("First polynomial : ");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->coeff);
        ptr=ptr->next;
    }
    printf("\n");
}

void display2()
{
   node *ptr=head1;
   printf("Second polynomial : ");
    while(ptr!=NULL)
    {
        printf("->%d",ptr->coeff);
        ptr=ptr->next;
    }
    printf("\n");
}


void display()
{
   node *ptr=head2;
   printf("Addition of polynomials : ");
    while(ptr!=NULL)
    {
        printf("->%d",ptr->coeff);
        ptr=ptr->next;
    }
    printf("\n");

}

