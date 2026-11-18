#include <stdio.h>
int arr[100];
int n;
int top=-1;
void push(int d);
void pop();
void display();
int main()
{
    printf("Enter the array length (Max 100)\n");
    scanf("%d",&n);
    int y=0;
    while(y!=4)
    {
        printf("1.Add\n2.Remove\n3.Display\n4.Exit\n");
        scanf("%d",&y);
        switch(y)
        {
            case 1:
                printf("Enter element: ");
                int a;
                scanf("%d", &a);
                push(a);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
void push(int d)
{
    if(top==n-1)
        printf("Stack Overflow\n");
    else
    {
        arr[++top]=d;
        printf("Element added=%d\n",arr[top]);
    }
}
void pop()
{
    if(top==-1)
        printf("Stack underflow\n");
    else
    {
        printf("Element popped=%d\n",arr[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    int i;
    for(i=0;i<=top;i++)
    {
       printf("%d\t",arr[i]);
    }
    printf("\n");
}
