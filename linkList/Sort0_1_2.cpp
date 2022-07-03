#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};
node* head;

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

void sort(){
    node *ptr = head;
    node *prev = ptr;
    // ptr=ptr->next;
    while(ptr != NULL)
    {
        if(ptr->data == 0 && (ptr!=head))
        {
           node *temp = ptr;
           prev->next=temp->next;
           ptr = ptr->next;
           temp->next=head;
           head=temp;
           prev = prev->next;
            
        }
        else if(ptr->data == 2)
        {
            node *temp = ptr;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            prev->next=ptr->next;
            temp->next = ptr;
            ptr->next = NULL;
            prev=prev->next;
            ptr=temp;
        }
        //1 0 1 0 2 0 1
        //0 1 1 0 2 0 1
        //0 0 1 1 2 0 1
        //0 0 1 1 0 1 2
        //0 0 0 1 1 1 2 


        //1 0 1 0 2 2 1
        //0 1 1 0 2 2 1
        //0 0 1 1 2 2 1
        //0 0 1 1 2 1 2
        //0 0 1 1 1 2 2
        // if((ptr->next == NULL) && (ptr->data == 1) && (prev-> data == 0)) 
        // {}
            // prev=ptr;
            // ptr=ptr->next;
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

int main()
{
    int i,nodes,num;
    cout<< "Enter the total number of nodes : ";
    cin >> nodes;
    for(i=0;i<nodes;i++)
    {
        cout<<"Enter Node : ";
        cin>>num;
        insert(num);
    }
    display();
    cout<<endl<<"After Sorting : ";
    sort();
    display();
    return 0;
}