#include<iostream>
using namespace std;

class node{
    public:
    node *next;
    int data;
};
node *head;

void insert(int x)
{
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    if(head==NULL)
    head = new_node;
    else
    {
        node *ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
}
void display()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<"->"<<ptr->data;
        ptr=ptr->next;
    }
}

void reverse(node **ptr,node **ptr1)
{
    node *prev=*ptr1;
    node *next=NULL;
    node *current=*ptr;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev=current;
        current =next;
    }
    *ptr = prev;
}

void isPalindrome()
{
    node *slow = head;
    node *fast = head;
    node *temp = head;
    node *temp1;
    int count=0,count1=0;
    while(fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    temp1 = slow->next;
    reverse(&(slow->next),&slow);
    // node *prev=slow;
    // node *next=NULL;
    // node *current=slow->next;
    // while(current != NULL)
    // {
    //     next = current->next;
    //     current->next = prev;
    //     prev=current;
    //     current =next;
    // }
    // slow->next = prev;
    while(temp1->next != NULL)
    {
        if(temp->data == temp1->data)
        {
            count++;
        }
        temp=temp->next;
        temp1=temp1->next;
        count1++;
    }
    if(count1 == count)
    cout<<endl<<"Palindrome";
    else
    cout<<endl<<"Not Palindrome";
}

int main()
{
    insert(1);
    insert(2);
    // insert(3);
    insert(2);
    insert(1);
    display();
    isPalindrome();
    return 0;
}