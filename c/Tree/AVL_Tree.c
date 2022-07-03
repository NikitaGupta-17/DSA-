#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}node;
 
int height(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

/*
Newnode in tree is inserted at T1
      y
     / \
    x   T3
   / \
  T1  T2 

*/

node* rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}
/*
Newnode in tree is inserted at T3
     x
    / \
  T1   y
      / \
    T2   T3
*/

node* leftRotate(struct Node *x)
{
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}
 
int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
node* insert(node* node1, int key)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1; 
    if (node1 == NULL)
        return(newnode);
    if (key < node1->key)
        node1->left  = insert(node1->left, key);
    else if (key > node1->key)
        node1->right = insert(node1->right, key);
    else 
        return node1;

    node1->height = 1 + max(height(node1->left),height(node1->right));

    int balance = getBalance(node1);

    //LL Rotation->newnode inserted at left of left sub tree
    if (balance > 1 && key < node1->left->key)
        return rightRotate(node1);

    //RR Rotation->newnode inserted at right of right sub tree
    if (balance < -1 && key > node1->right->key)
        return leftRotate(node1);

    //LR Rotation->newnode inserted at right of left sub tree 
    if (balance > 1 && key > node1->left->key)
    {
        node1->left =  leftRotate(node1->left);
        return rightRotate(node1);
    }

    //RL Rotation->newnode is inserted at left of right sub tree
    if (balance < -1 && key < node1->right->key)
    {
        node1->right = rightRotate(node1->right);
        return leftRotate(node1);
    }
    return node1;
}

int find_largest(node* root)
{
    if(root->right==NULL)
    {
        return root->key;
    }
    else
    {
        find_largest(root->right);
    }
}

node* deletion(node *root, int val){
    node *temp;
    if(root == NULL)
        return NULL;
    if(root->key < val)
        root->right = deletion(root->right,val);
    else if(root->key > val)
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
            root->key = leftmax;
            root->left = deletion(root->left,leftmax);
        }
    }
        if(root==NULL){
            return root;
        }
        root->height=1+max(height(root->left),height(root->right));

        int balance=getBalance(root);

        if (balance > 1 && getBalance(root->left)>=0)
            return rightRotate(root);
        if (balance < -1 && getBalance(root->right)<=0)
            return leftRotate(root);
        if (balance > 1 &&  getBalance(root->left)<0)
        {
            root->left =  leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right)>0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    return root;
}
 

void preOrder(node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
  node* root = NULL;
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);

  root=deletion(root,40);
  /*AVL Tree after deletion would be
           30
          /  \
        20    50
       /  \      
     10    25
  */
    printf("\nPreorder traversal of the AVL tree after deletion of 40 is \n");
    preOrder(root);    
  return 0;
}