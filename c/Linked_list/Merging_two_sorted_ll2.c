#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;

void display(node* head)
{
    node* ptr = head;
    while (ptr)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insert(node** head, int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
node* sortedMerge(node* a, node* b)
{
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    node* result = NULL;
 

    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
 
    return result;
}
 
int main(void)
{
    int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node *a = NULL, *b = NULL;
    for (int i = n - 1; i >= 0; i = i - 2) {
        insert(&a, keys[i]);
    }
 
    for (int i = n - 2; i >= 0; i = i - 2) {
        insert(&b, keys[i]);
    }
    printf("First List: ");
    display(a);
 
    printf("Second List: ");
    display(b);
 
    node* head = sortedMerge(a, b);
    printf("After Merge: ");
    display(head);
 
    return 0;
}