#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};
node* head;

void insert(int x, int indicator)
{
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    if(head==NULL)
    head = new_node;
    else
    {
        if(indicator==0)
        {
            new_node->next = head;
            head = new_node;
        }
        else if (indicator == 1)
        {
            node *ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
        }
        else{
            cout<<"invalid choice";
        }

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
    int i,nodes,num,indicator;
    cout<< "Enter the total number of nodes : ";
    cin >> nodes;
    for(i=0;i<nodes;i++)
    {
        cout<<"Enter Node : ";
        cin>>num;
        cout<<"Enter Indicator : ";
        cin >> indicator;
        insert(num,indicator);
    }
    display();
    return 0;
}