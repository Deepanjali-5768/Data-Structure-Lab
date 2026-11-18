#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *top = NULL;
void push()
{
struct node *newnode;
newnode = (struct node*)malloc(sizeof(struct node));
if(newnode == NULL)
{
printf("Stack Overflow\n");
return;
}
printf("Enter value: ");
scanf("%d", &newnode->data);
newnode->next = top;
top = newnode;
printf("Element inserted successfully.\n");
}
void pop()
{
struct node *temp;
if(top == NULL)
{
printf("Stack Underflow\n");
return;
}
temp = top;
printf("Deleted element = %d\n", top->data);
top = top->next;
free(temp);
}
void peek()
{
if(top == NULL)
printf("Stack is Empty\n");
else
printf("Top element = %d\n", top->data);
}
void traversal()
{
struct node *temp;
if(top == NULL)
{
printf("Stack is Empty\n");
return;
}
printf("Stack Elements:\n");
temp = top;
while(temp != NULL)
{
printf("%d\n", temp->data);
temp = temp->next;
}
}

int main()
{
int choice;
do
{
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Peek\n");
printf("4. Display\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
traversal();
break;
case 5:
printf("Program Ended.\n");
break;
default:
printf("Invalid Choice!\n");
}
} while(choice != 5);
return 0;
}
