#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int a[20][20];

typedef struct Node
{
   int data;
   struct Node* next;
}node; 
node *front=NULL;
node *rear=NULL;


void enqueue(int x)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front = newnode;
        rear=newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        newnode->next=front;
    }
}

void dequeue()
{
    node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("Queue underflow\n");
    }
    else if(front==rear){
        temp=front;
        front=NULL;
        rear=NULL;
    }
    else{
        temp=front;
        front=front->next;
        rear->next=front;
    }
    free(temp);
}

int peek()
{
    if(front==NULL)
    {
        return INT_MAX;
    }
    else
    {
        return front->data;
    }
}
int isEmpty(){
    if(rear==NULL)
    return 1;
    else
    return 0;
}
void createGraph(int vertices){
    int num,num1,choice;
    int i,j,connectVertex;
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++)
        {
            a[i][j]=0;
        }
    }
    do{
        printf("Enter the source vertex : ");
        scanf("%d",&num);
        printf("Enter the destination vertex : ");
        scanf("%d",&num1);
        a[num][num1]=1;
        a[num1][num]=1;
        printf("Do you want to continue?");
        scanf("%d",&choice);
    }while(choice!=0);
    // for(i=0;i<vertices;i++){
    //     printf("Enter the no. of vertices which are connected to %d vertex : ",i);
    //     scanf("%d",&num);
    //     printf("Enter the vertices which are connected to %d vertex : ",i);
    //     for(j=0;j<num;j++){
    //         scanf("%d",&connectVertex);
    //         a[i][connectVertex]=1;
    //     }
    // }

}

void BFSGraphTraversal(int size,int i){
    int *visited=(int*)calloc(size,sizeof(int));
    int Node;
    visited[i]=1;
    enqueue(i);
    while(!isEmpty()){ 
        Node=peek();
        printf("%d ",Node);
        dequeue();
        for(int j=0;j<size;j++){
            if(a[Node][j]==1 && visited[j]==0){
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

/*
Graph Choosen:-
0-1
| |
3-2
| |
 4
| |
5 6
*/

int main(){
    int vertices,startingVertices;
    printf("Enter the number of vertices : ");
    scanf("%d",&vertices);
    createGraph(vertices);
    printf("Enter the starting vertex for traversal : ");
    scanf("%d",&startingVertices);
    BFSGraphTraversal(vertices,startingVertices);
}