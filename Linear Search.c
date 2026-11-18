#include <stdio.h>
#include <stdlib.h>
void insertfirst();
void trav();
void dellast();
void search_link();
struct node
{
    int info;
    struct node *link;
};
typedef struct node NODE;
NODE *start = NULL;
int main()
{
    int c;
    while (1)
    {
        printf("1. Insertion\n");
        printf("2. Delete Last Node\n");
        printf("3. Traversing\n");
        printf("4. Searching\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                insertfirst();
                break;
            case 2:
                dellast();
                break;
            case 3:
                trav();
                break;
            case 4:
                search_link();
            case 5:
                exit(0);
            default:
                printf("Wrong Choice\n");
        }
    }
    return 0;
}
void insertfirst()
{
    NODE *ptr, *newNode;
    int data;
    newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Input the data to be stored in linked list: ");
    scanf("%d", &data);
    newNode->info = data;
    newNode->link = NULL;
    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newNode;
    }
    printf("Node inserted successfully.\n");
}
void trav()
{
    NODE *ptr;
    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    ptr = start;
    printf("Linked List: ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->info);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
void dellast()
{
    NODE *ptr, *prev;
    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    if (start->link == NULL)
    {
        printf("%d is deleted.\n", start->info);
        free(start);
        start = NULL;
        return;
    }
    ptr = start;
    while (ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = NULL;
    printf("%d is deleted.\n", ptr->info);
    free(ptr);
}
void search_link()
{
    NODE *ptr;
    int se, pos = 1, flag = 0;
    printf("Input search element: ");
    scanf("%d", &se);
    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->info == se)
        {
            flag = 1;
            break;
        }
        ptr = ptr->link;
        pos++;
    }
    if (flag == 1)
    {
        printf("Element found at position %d\n", pos);
    }
    else
    {
        printf("Element not found\n");
    }
}

