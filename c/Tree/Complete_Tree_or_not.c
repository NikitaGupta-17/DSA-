#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
    int data;
    struct Tree *left,*right;
}tree;

tree *root=NULL;

tree* create(){
   tree *temp;  
   int data,choice;  
   temp = (tree*)malloc(sizeof(tree));  
   printf("Press 0 to exit");  
   printf("\nPress 1 for new node\n");  
   printf("Enter your choice : ");  
   scanf("%d", &choice);   
   if(choice==0)  
   {  
       return 0;  
   }  
   else if(choice==1)  
   {  
   printf("Enter the data:");  
   scanf("%d", &data);  
   temp->data = data;  
   printf("Enter the left child of %d\n", data);  
   temp->left = create();  
   printf("Enter the right child of %d\n", data);  
   temp->right = create();  
   return temp;   
   }  
   else{
       printf("Invalid Choice\n");
   }
}

unsigned int countNodes(tree* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}

int check_Perfect(tree *root ,int index, unsigned int number_nodes){
    if(root==NULL){
        return 1;
    }
    if (index >= number_nodes)
        return 0;
    return (check_Perfect(root->left, 2*index + 1, number_nodes) && check_Perfect(root->right, 2*index + 2, number_nodes));
}

int main(){
    root=create();
    unsigned int total_node=countNodes(root);
    int i=check_Perfect(root,0,total_node);
    if(i==1){
        printf("It is a complete binary tree\n");
    }
    else{
        printf("It is not a complete binary tree\n");
    }
}