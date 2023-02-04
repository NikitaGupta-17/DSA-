#include<iostream>
#include<climits>
using namespace std;

class Queue{
    public:
    int info;
    int priority;
    Queue *next;
};

int count=0;

Queue *head=NULL;

void push(int data){
    Queue *newnode=new Queue();
    newnode->info=data;
    newnode->priority=++count;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

void pop(){
    Queue *ptr;
    if(head==NULL){
        printf("Deletion is not possible\n");
    }
    else{
        ptr=head;
        head=head->next;
        ptr->next=NULL;
        free(ptr);
    }
}

int peek(){
    if(head==NULL){
        printf("Empty Stack\n");
        return INT_MAX;    
    }
    else{
        return head->info;
    }
}

int main(){
    int element,choice,temp;
    cout<<"Enter choice :"<<endl;
    cout<<"1-push 2-pop 3-peek"<<endl;
    cin>>choice;
    while(choice!=0)
    {
    	if(choice==1)
    	{
            cout<<"Enter Element :";
            cin>>element;
            push(element);
		}
        else if(choice==2)
        {
        	pop();
		}
		else if(choice == 3)
		{
			temp=peek();
            if(temp!=INT_MAX)
			cout<<temp<<endl;
		}
		else if(choice == 0)
		{
			break;
		}
		else
		{
			cout<<"Invalid Choice\n";
		}
		cout<<"Enter choice :"<<endl;
        cout<<"0-To Exit 1-push 2-pop 3-peek"<<endl;
        cin>>choice;
	}
    return 0;
}
