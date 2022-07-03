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

int check_BST(tree *root){
    if(root==NULL){
        return 1;
    }
    if(root->left && root->right)
    {
        if((root->data > root->left->data)&& (root->data < root->right->data)){
        check_BST(root->left);
        check_BST(root->right);
        }
        else{
        return 0;
        }
    }
    else if(root->left){
        if(root->data >root->left->data){
            return 1;
        }
    }
    else if(root->right){
        if(root->data < root->right->data){
            return 1;
        }
    }
    else{
        return 1;
    }
    
}

int main(){
    root=create();
    int i=check_BST(root);
    if(i==1){
        printf("It is a binary search tree\n");
    }
    else{
        printf("It is not a binary search tree\n");
    }
}