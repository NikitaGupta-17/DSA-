#include <stdio.h>
#include <stdlib.h>
int top = 10;

struct node
{
	char ch;
	struct node *next;
	struct node *prev;
}*stack[11];
typedef struct node node;
 
void push(node *str)
{
	if (top <= 0)
	printf("Stack is Full ");
	else
	{
		stack[top] = str;
		top--;
	}
}
 
node *pop()
{
	node *exp;
	if (top >= 10)
		printf("Stack is Empty ");
	else
		exp = stack[++top];
	return exp;
}
void convert(char exp[])
{
	node *op1,  *op2;
	node *temp;
	int i;
	for (i=0;exp[i]!='\0';i++)
	if (exp[i] >= 'a'&& exp[i] <= 'z'|| exp[i] >= 'A' && exp[i] <= 'Z')
	{
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = NULL;
		temp->prev = NULL;
		push(temp);
	}
	else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ||
exp[i] == '^')
	{
		op1 = pop();
		op2 = pop();
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = op1;
		temp->prev = op2;
		push(temp);
	}
}
 
void display(node *temp)
{
	if (temp != NULL)
	{
		display(temp->prev);
		printf("%c", temp->ch);
		display(temp->next);
	}
}
 
void main()
{
	char exp[50];
	printf("Enter the postfix expression :");
	scanf("%s", exp);
	convert(exp);
	printf("\nThe Equivalant Infix expression is:");
	display(pop());
	printf("\n\n");
}


//!(: Not Working
// #include<stdio.h>
// #include<stdlib.h>
// #include<limits.h>
// #include<string.h>

// typedef struct Stack{
//     char *data;
//     struct Stack *next;
// }stack;

// stack *top=NULL;

// void push(char *x){
//     stack *newnode=(stack*)malloc(sizeof(stack));
//     newnode->data=x;
//     newnode->next=NULL;
//     if(top==NULL){
//         top=newnode;
//     }
//     else{
//         newnode->next=top;
//         top=newnode;
//     }
// }

// char* pop(){
//     char* temp;
//     stack *ptr;
//     if(top==NULL){
//         printf("Stack Underflow\n");
//         return "Hello";
//     }
//     else{
//         ptr=top;
//         temp=ptr->data;
//         top=top->next;
//         ptr->next=NULL;
//         free(ptr);
//         return temp;
//     }
// }

// char* peek(){
//     if(top==NULL){
//         printf("Stack Underflow\n");
//         return "Hello";
//     }
//     else{
//         return top->data;
//     }
// }

// void PostfixToInfix(char *s){
//     int i;
//     char *op1,*op2,*op3="(",*op4=")";
//     for(i=0;s[i];i++){
//         if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
//             push(s[i]);
//         }
//         else{
//             op1=pop();
//             op2=pop();
//             strcat(op3,op1);
//             strcat(op3,s[i]);
//             strcat(op3,op2);
//             strcat(op3,op4);
//             push(op3);
//         }
//     }
//     op1=pop();
//     if(top==NULL)
//     printf("Infix String : %s\n",op1);
// }

// int main(){
//     //Postfix  : Infix
//     //abc*+d-  : a+b*c-d
//     char t[20];
//     printf("Enter the postfix string : ");
//     scanf("%s",t);
//     PostfixToInfix(t);
// }