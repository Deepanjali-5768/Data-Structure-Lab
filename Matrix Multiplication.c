#include <stdio.h>
int main()
{
    int i, j, r1, c1, r2, c2, k;
    int choice;
    int a[10][10], b[10][10], c[10][10];
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d%d", &r2, &c2);
    printf("Enter the elements of matrix one:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of matrix two:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    do
    {
        printf("\n1. Addition of the 2D arrays\n");
        printf("2. Multiplication of the 2D arrays\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if (r1 == r2 && c1 == c2)
                {
                    printf("The addition is:\n");

                    for (i = 0; i < r1; i++)
                    {
                        for (j = 0; j < c1; j++)
                        {
                            c[i][j] = a[i][j] + b[i][j];
                            printf("%d\t", c[i][j]);
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("The addition is not possible.\n");
                }
                break;
            case 2:
                if (c1 == r2)
                {
                    for (i = 0; i < r1; i++)
                    {
                        for (j = 0; j < c2; j++)
                        {
                            c[i][j] = 0;

                            for (k = 0; k < c1; k++)
                            {
                                c[i][j] += a[i][k] * b[k][j];
                            }
                        }
                    }
                    printf("The multiplication is:\n");

                    for (i = 0; i < r1; i++)
                    {
                        for (j = 0; j < c2; j++)
                        {
                            printf("%d\t", c[i][j]);
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("The multiplication is not possible.\n");
                }
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 2);

    return 0;
}
