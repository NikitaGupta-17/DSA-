#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
    int data;
    struct Tree *left,*right;
}tree;

tree *qe[10];
int front=-1;
int rear=-1;

tree *root=NULL;

void insert(tree *node ,int value)
{
    tree *newnode=(tree*)malloc(sizeof(tree));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        root=newnode;
    }
    else if(node->data>value){
        if(node->left==NULL)
        {
            node->left=newnode;
        }
        else{
            insert(node->left,value);
        }
    }
    else if(node->data<value)
    {
        if(node->right==NULL)
        {
            node->right=newnode;
        }
        else{
            insert(node->right,value);
        }
    }
}

int find_largest(tree *node)
{
    if(node->right==NULL)
    {
        return node->data;
    }
    else
    {
        find_largest(node->right);
    }
}

tree *deletion(tree *root, int val)
{
    tree *temp;
    if(root == NULL)
        return NULL;
    if(root->data < val)
        root->right = deletion(root->right,val);
    else if(root->data > val)
        root->left = deletion(root->left,val);
    else
    {
        //Root has no child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        //root has right child
        else if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        //root has left child
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        //root has both left and right child
        else
        {
            int leftmax = find_largest(root->left);
            root->data = leftmax;
            root->left = deletion(root->left,leftmax);
        }

    }

    //return the actual root's address
    return root;
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

void preorder(tree *node)
{
    if(root == NULL)
    {
        printf("Tree is Empty\n");
        return;
    }
    if(node!=NULL)
    {
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(tree *node)
{
    if(root == NULL)
    {
        printf("Tree is Empty\n");
        return;
    }
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
}
void push(tree* data)
{
    if(front==0 && rear==9)
    {
        printf("Queue overflow\n");
    }
    else if(front==-1 && rear==-1)
    {
        qe[++rear]=data;
        front++;
    }
    else{
        qe[++rear]=data;
    }  
}
tree* pop()
{
    tree* temp;
    if(front==-1 && rear==-1)
    {
        printf("Queue underflow\n");
    }
    else if(front==rear)
    {
        temp=qe[rear];
        front=-1;
        rear=-1;
        return temp;
    }
    else{
        return qe[front++];
    }  
}

void levelorder(tree *Root)
{
    if(root == NULL)
    {
        printf("Tree is Empty\n");
        return;
    }
    push(Root);
    tree* node ;
    while(front!=-1)
    { 
        node=pop();
        printf("%d ",node->data);
        
        if(node->left != NULL)
        push(node->left);

        if(node->right != NULL)
        push(node->right);
    }
    
}

int main()
{
    int element,choice;
    printf("Enter choice :\n");
    printf("1-To insert 2-To delete 3-Inorder Traversal 4-Postorder Traversal 5-Preorder Traversal 6-Levelorder Traversal\n");
    scanf("%d",&choice);
    while(choice!=0)
    {
    	if(choice==1)
    	{
            printf("Enter Element to be inserted:");
            scanf("%d",&element);
            insert(root,element);
		}
        else if(choice==2)
        {
            printf("Enter Element to be deleted:");
            scanf("%d",&element);
        	root=deletion(root,element);
		}
		else if(choice == 3)
		{
			inorder(root);
		}
        else if(choice == 4)
		{
			postorder(root);
		}
        else if(choice == 5)
		{
			preorder(root);
		}
        else if(choice == 6)
		{
			levelorder(root);
		}
		else if(choice == 0)
		{
			break;
		}
		else
		{
			printf("Invalid Choice\n");
		}
		printf("\nEnter choice :\n");
        printf("1-To insert 2-To delete 3-Inorder Traversal 4-Postorder Traversal 5-Preorder Traversal ");
        printf("6-Levelorder Traversal 0-To Exit\n");
        scanf("%d",&choice);
	}
    return 0;
    /*
                8 
               / \
              3  10
             / \   \
            1   6   14
               / \  /
              4   7 13 

    inorder : 1 3 4 6 7 8 10 13 14
    deletion(root,6);
                8 
               / \
              3  10
             / \   \
            1   4   14
                 \  /
                 7 13 

    inorder : 1 3 4 7 8 10 13 14
    preorder : 8 3 1 4 7 10 14 13
    postorder : 1 7 4 3 13 14 10 8
    levelorder : 8 3 10 1 4 14 7 13
    */
}

