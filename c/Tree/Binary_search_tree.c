#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
    int data;
    struct Tree *left,*right;
}tree;

tree *root=NULL;

void insert(int x)
{
    tree *new_child = (tree*)malloc(sizeof(tree));
    tree *node1=NULL;
    tree *node = root;
    new_child->data=x;
    new_child->left=NULL;
    new_child->right=NULL;
    if(root==NULL)
    {
        root = new_child;
    }
    else
    {
        while(node!=NULL)
        {
            node1=node;
            if(node->data > x)
            {
                node = node->left;
            }
            else
            {
                node= node->right;
            }
        }
        if(node1->data>x)
        {
            node1->left=new_child;
        }
        else
        {
            node1->right=new_child;
        }
    }
}

void inorder(tree *node)
{
    if(root == NULL)
    {
        printf("Tree is Empty\n");
        return;
    }
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

int main()
{
    inorder(root);
    insert(3);
    insert(5);
    insert(11);
    insert(8);
    insert(4);
    insert(1);
    insert(12);
    insert(7);
    insert(2);
    insert(6);
    insert(10);
    inorder(root);
    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
}tree;
tree *root=NULL;

void insertion(tree *node,int x){
    tree *newnode=(tree*)malloc(sizeof(tree));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        root=newnode;
    }
    else if(node->data>x){
        if(node->left==NULL){
            node->left=newnode;
        }
        else
        {
            insertion(node->left,x);
        }
    }
    else if(node->data<x){
        if(node->right==NULL){
            node->right=newnode;
        }
        else
        {
            insertion(node->right,x);
        }
    }
}

int find_largest(tree *root){
    if(root->right==NULL){
        return root->data;
    }
    else{
        find_largest(root->right);
    }
}

tree *deletion(tree *root,int x){
    tree *temp;
    if(root==NULL){
        printf("Deletion is not possible\n");
        return NULL;
    }
    else if(root->data<x){
        root->right=deletion(root->right,x);
    }
    else if(root->data>x){
        root->left=deletion(root->left,x);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->right==NULL){
            temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL){
            temp=root->right;
            free(root);
            return temp;
        }
        else{
            int leftmax= find_largest(root->left);
            root->data=leftmax;
            root->left=deletion(root->left,leftmax);
            return root;
        }
    }
}

void inorder(tree *node){
    if(root==NULL){
        printf("Tree is empty\n");
        return;
    }
    if(node!=NULL){
       inorder(node->left);
       printf("%d ",node->data);
       inorder(node->right);
    }
}

int main(){
    insertion(root,8);
    insertion(root,7);
    insertion(root,10);
    insertion(root,9);
    insertion(root,12);
    insertion(root,5);
    insertion(root,6);
    insertion(root,3);
    inorder(root);
    return 0;
}
*/