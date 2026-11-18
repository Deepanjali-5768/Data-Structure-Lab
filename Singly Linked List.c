#include <stdio.h>
#include <stdlib.h>
void insert();
void delete1();
void triverse();
void insertfirst();
void deletefirst();
void insertlast();
void deletelast();
struct node
{
    int info;
    struct node *link;
};
typedef struct node NODE;
NODE *start = NULL;
int main()
{
    int choice;
    do
    {
        printf("\n\n1. Insert the element");
        printf("\n2. Delete the element");
        printf("\n3. Traverse");
        printf("\n4. Insert First");
        printf("\n5. Delete First");
        printf("\n6. Insert Last");
        printf("\n7. Delete Last");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete1();
            break;
        case 3:
            triverse();
            break;
        case 4:
            insertfirst();
            break;
        case 5:
            deletefirst();
            break;
        case 6:
            insertlast();
            break;
        case 7:
            deletelast();
            break;
        case 8:
            printf("Program Ended");
            break;
        default:
            printf("Invalid choice");
        }

    } while(choice != 8);

    return 0;
}
void insert()
{
    NODE *ptr, *newnode;
    int data;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->link = NULL;
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        ptr = start;
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }
    printf("%d inserted", data);
}
void delete1()
{
    NODE *ptr, *prev;
    if(start == NULL)
    {
        printf("No element in the linked list");
    }
    else if(start->link == NULL)
    {
        printf("%d is deleted", start->info);
        free(start);
        start = NULL;
    }
    else
    {
        ptr = start;
        while(ptr->link != NULL)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = NULL;
        printf("%d is deleted", ptr->info);
        free(ptr);
    }
}
void triverse()
{
    NODE *ptr;
    if(start == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        ptr = start;
        printf("Linked List: ");
        while(ptr != NULL)
        {
            printf("%d ", ptr->info);
            ptr = ptr->link;
        }
    }
}
void insertfirst()
{
    NODE *newnode;
    int data;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data: ");
    scanf("%d", &data);

    newnode->info = data;
    newnode->link = start;
    start = newnode;

    printf("%d inserted at first", data);
}

void deletefirst()
{
    NODE *ptr;

    if(start == NULL)
    {
        printf("No element in the linked list");
    }
    else
    {
        ptr = start;
        start = start->link;

        printf("%d is deleted", ptr->info);

        free(ptr);
    }
}
void insertlast()
{
    NODE *ptr, *newnode;
    int data;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->link = NULL;
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        ptr = start;

        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }

        ptr->link = newnode;
    }

    printf("%d inserted at last", data);
}

void deletelast()
{
    NODE *ptr, *prev;

    if(start == NULL)
    {
        printf("No element in the linked list");
    }
    else if(start->link == NULL)
    {
        printf("%d is deleted", start->info);
        free(start);
        start = NULL;
    }
    else
    {
        ptr = start;

        while(ptr->link != NULL)
        {
            prev = ptr;
            ptr = ptr->link;
        }

        prev->link = NULL;

        printf("%d is deleted", ptr->info);

        free(ptr);
    }
}

