#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *prev;
struct node *next;
};
struct node *head = NULL;
void insertFirst();
void insertLast();
void deleteFirst();
void deleteLast();
void traverseForward();
void traverseBackward();
int main()
{
    int choice;

    do
    {
        printf("\n ---------Double Linked list-----------\n");
        printf("1. Insertion at the first\n");
        printf("2. Insertion at the last\n");
        printf("3. Deletion of the first node\n");
        printf("4. Deletion of the last node\n");
        printf("5. Traverse forward\n");
        printf("6. Traverse backward\n");
        printf("7. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insertFirst();
                break;
            case 2:
                insertLast();
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                traverseForward();
                break;
            case 6:
                traverseBackward();
                break;
            case 7:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 7);
    return 0;
}
void insertFirst()
{
    struct node *newNode;
    int value;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL)
    {
    head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted at first successfully.\n");
}
void insertLast()
{
    struct node *newNode;
    struct node *temp;
    int value;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        printf("Node inserted at last successfully.\n");
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at last successfully.\n");
}
void deleteFirst()
{
    struct node *temp;
    if(head == NULL)
    {
    printf("List is empty.\n");
    return;
    }
    temp = head;
    head = head->next;
    if(head != NULL)
    {
        head->prev = NULL;
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}
void deleteLast()
{   struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    if(temp->next == NULL)
    {
        printf("Deleted element: %d\n", temp->data);
        head = NULL;
        free(temp);
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Deleted element: %d\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}
void traverseForward()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Forward traversal: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void traverseBackward()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Backward traversal: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
