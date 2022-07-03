#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
 class list
 {
     node *head,*tail;
     public:
     list()
     {
         head=NULL;
         tail=NULL;
     }
     void insert(int item)
     {
        
         node *temp=new node;
         temp->data=item;
         temp->next=NULL;
         if(head==NULL)
         {
             head=temp;
             tail=temp;

         }
         else
         {
             
             
                 tail->next=temp;
                 tail=temp;
             
         }

     }
     void display()
     {
         node *temp;
         temp=head;
         while(temp!=NULL)
         {
             cout<<temp->data<<"->";
             temp=temp->next;
         }
     }
     void deleteatpos(int pos)
     {
         node *current,*pre;
         current=head;
         for(int i=0;i<pos-1;i++)
         {
             pre=current;
             current=current->next;

         }
         pre->next=current->next;
         delete current;
     }
        
          
 };
 int main()
 {
     list obj;
     obj.insert(2);
     obj.insert(3);
     obj.insert(4);
     obj.insert(5);
     obj.display();
     obj.deleteatpos(3);
     cout<<endl<<"after deletion"<<endl;
     obj.display();

     return 0;
 }