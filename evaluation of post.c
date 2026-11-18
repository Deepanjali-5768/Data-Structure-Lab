#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void push(int);
int pop();
void evaluation();
int stack[50];
int top = -1;
void push(int x)
{
    top++;
    stack[top] = x;
}
int pop()
{
    int x;
    x = stack[top];
    top--;
    return x;
}
void evaluation()
{
    char exp[50];
    int i, a, b, result;
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    for(i = 0; exp[i] != '\0'; i++)
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();
            switch(exp[i])
            {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                case '%':
                    result = a % b;
                    break;
            }
            push(result);
        }
    }
    printf("Result = %d", pop());
}
void main()
{
    evaluation();
}
