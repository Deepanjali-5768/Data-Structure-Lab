#include <stdio.h>
int binarySearchIterative(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int binarySearchRecursive(int arr[], int low, int high, int key)
{
    int mid;
    if (low > high)
        return -1;
    mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearchRecursive(arr, low, mid - 1, key);
    else
        return binarySearchRecursive(arr, mid + 1, high, key);
}
int main()
{
    int arr[100], n, key, choice, result, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("\nBINARY SEARCH MENU\n");
        printf("1. Iterative Binary Search\n");
        printf("2. Recursive Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = binarySearchIterative(arr, n, key);
                if (result != -1)
                    printf("Element found at position %d\n", result + 1);
                else
                    printf("Element not found\n");
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = binarySearchRecursive(arr, 0, n - 1, key);
                if (result != -1)
                    printf("Element found at position %d\n", result + 1);
                else
                    printf("Element not found\n");
                break;
            case 3:
                printf("Program terminated.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

