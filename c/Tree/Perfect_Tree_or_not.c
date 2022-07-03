#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

int countNodes(tree* root)
{
    if (root == NULL)
        return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

int count_levels(tree *root, int level){
    if(root==NULL){
        return level;
    }
    else{
        if(root->left!=NULL)
        count_levels(root->left,level+1);
        else
        return level;
    }
}

int check_Perfect(int level, int total_node){
    int num=0;
    while(level>=0){
        num=num+pow(2,level);
        level--;
    }
    if(num == total_node){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    root=create();
    int total_nodes=countNodes(root);
    int total_levels=count_levels(root,0);
    int i=check_Perfect(total_levels,total_nodes);
    if(i==1){
        printf("It is a Perfect Binary Tree\n");
    }
    else{
        printf("It is not a Perfect Binary Tree\n");
    }
}