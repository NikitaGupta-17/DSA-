#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int a[20][20];

int stk[MAX];
int top=-1;
//push
int push(int t){
    if(top>=MAX-1)
    {
        printf("Stack overflow\n");
        return 0;
    }
    else
    {
        stk[++top] = t;
        return 1;
    }
}
    //pop
void pop()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int l = stk[top];
        top--;
    }
}
    //isEmpty

int isEmpty()
{
    return (top<0);
}
    //peek(top)
int peek()
{
    return stk[top];
}

void createGraph(int vertices){
    int num;
    int i,j,connectVertex;
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++)
        {
            a[i][j]=0;
        }
    }
    for(i=0;i<vertices;i++){
        printf("Enter the no. of vertices which are connected to %d vertex : ",i);
        scanf("%d",&num);
        printf("Enter the vertices which are connected to %d vertex : ",i);
        for(j=0;j<num;j++){
            scanf("%d",&connectVertex);
            a[i][connectVertex]=1;
        }
    }

}

void DFSGraphTraversal(int size,int i){
    int *visited=(int*)calloc(size,sizeof(int));
    int Node;
    visited[i]=1;
    push(i);
    while(!isEmpty()){ 
        Node=peek();
        printf("%d ",Node);
        pop();
        for(int j=0;j<size;j++){
            if(a[Node][j]==1 && visited[j]==0){
                visited[j]=1;
                push(j);
            }
        }
    }
}

int main(){
    int vertices,startingVertices;
    printf("Enter the number of vertices : ");
    scanf("%d",&vertices);
    createGraph(vertices);
    printf("Enter the starting vertex for traversal : ");
    scanf("%d",&startingVertices);
    DFSGraphTraversal(vertices,startingVertices);
    return 0;
}