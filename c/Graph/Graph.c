#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct AdjListNode{
    int dest;
    struct AdjListNode *next;
};

struct AdjList{
    struct AdjListNode *head;
};

struct Graph{
    int size;
    struct AdjList *array;
};


struct Graph* creategraph(int size){
    struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->size=size;
    graph->array=(struct AdjList*)malloc(size*sizeof(struct AdjList));
    int i;
    for(i=0;i<size;i++){
        graph->array[i].head=NULL;
    }
    return graph;
};

void addEdge(struct Graph *graph,int source,int des){
    struct AdjListNode *ptr=NULL;
    struct AdjListNode *newNode=(struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    struct AdjListNode *newNode1=(struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest=des;
    newNode->next=NULL;
    if(graph->array[source].head==NULL){
        newNode->next=graph->array[source].head;
        graph->array[source].head=newNode;
    }
    else{
        ptr=graph->array[source].head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }
    newNode1->dest=source;
    newNode1->next=NULL;
    if(graph->array[des].head==NULL){
        newNode1->next=graph->array[des].head;
        graph->array[des].head=newNode1;
    }
    else{
        ptr=graph->array[des].head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newNode1;
    }

}


void display(struct Graph *graph){
    int i;
    for(i=0;i<graph->size;i++){
        struct AdjListNode *ptr=graph->array[i].head;
        printf("Adjacency list of vertex %d : ",i);
        while(ptr!=NULL){
            printf("->%d",ptr->dest);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
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
    if(front==NULL && rear==NULL)
    {
        printf("Queue underflow\n");
    }
    else if(front==rear){
        front=NULL;
        rear=NULL;
    }
    else{
        node *temp;
        temp=front;
        front=front->next;
        rear->next=front;
        free(temp);
    }
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
void BFSGraphTraversal(struct Graph *graph, int size){
    int *visited=(int*)malloc(sizeof(size));
    int i,Node;
    i=0;
    struct AdjListNode *ptr=graph->array[i].head;
    for(i=0;i<size;i++){
        visited[i]=0;
    }
    int k;
    i=0;
    visited[i]=1;
    enqueue(i);
    while(!isEmpty()){
        Node=peek();
        printf("%d ",Node);
        dequeue();
        for(k=0;k<graph->size;k++){
            ptr=graph->array[k].head;
            while(ptr!=NULL){
                if(visited[ptr->dest]==0){
                visited[ptr->dest]=1;
                enqueue(ptr->dest);
                }
                ptr=ptr->next;
            }
        }
    }
}


int main(){
    int size=7;
    struct Graph *graph=creategraph(size);
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    addEdge(graph,4,5);
    addEdge(graph,4,6);
    display(graph);
    printf("BFS Graph Traversal : ");
    BFSGraphTraversal(graph,size);
    return 0;
}