#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *front=NULL;
node *rear=NULL;

int a[20][20];

node *top=NULL;

void push(int x){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    if(top==NULL){
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}

void pop(){
    node *ptr;
    if(top==NULL){
        printf("stack underflow\n");
    }
    else{
       ptr=top;
       top=top->next;
       ptr->next=NULL;
    }
    free(ptr);
}

int peek1(){
    if(top==NULL){
        printf("Stack underflow\n");
        return INT_MAX;
    }
    else{
        return top->data;
    }
}

int isEmpty1(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void createGraph(int vertices){
    int source,destination,choice,i,j;
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            a[i][j]=0;
        }
    }
    //undirected graph
    do{
        printf("Enter source vertex : ");
        scanf("%d",&source);
        printf("enter destination vertex : ");
        scanf("%d",&destination);
        a[source][destination]=1;
        a[destination][source]=1;
        printf("Do you want to continue ?");
        scanf("%d",&choice);
    }while(choice!=0);
}

void DfsTraversal(int vertices,int startingVertex){
    int *visited=(int*)calloc(vertices,sizeof(int));
    int Node,j;
    visited[startingVertex]=1;
    push(startingVertex);
    while(!isEmpty1()){
        Node=peek1();
        printf("%d ",Node);
        pop();
        for(j=0;j<vertices;j++){
            if(a[Node][j]==1 && visited[j]==0){
                visited[j]=1;
                push(j);
            }
        }
    }
}

void enqueue(int x){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=newnode;
        rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

void dequeue(){
    node *ptr;
    if(front==NULL){
        printf("queue underflow\n");
    }
    else if(front==rear){
        ptr=front;
        front = NULL;
        rear=NULL;
    }
    else{
        ptr=front;
        front=front->next;
    }
    free(ptr);
}

int peek(){
    if(front==NULL){
        printf("queue underflow\n");
        return INT_MAX;
    }
    else{
        return front->data;
    }
}

int isEmpty(){
    if(front==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void BfsTraversal(int vertices,int startingVertex){
    int *visited=(int*)calloc(vertices,sizeof(int));
    int Node,j;
    visited[startingVertex]=1;
    enqueue(startingVertex);
    while(!isEmpty()){
        Node=peek();
        printf("%d ",Node);
        dequeue();
        for(j=0;j<vertices;j++){
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
    int vertices,startingVertex;
    printf("Enter the total number of vertices : ");
    scanf("%d",&vertices);
    createGraph(vertices);
    printf("Enter the starting Vertex : ");
    scanf("%d",&startingVertex);
    BfsTraversal(vertices,startingVertex);
    printf("\n");
    DfsTraversal(vertices,startingVertex);
    return 0;
}