#include<stdio.h>
int main()
{
int a[100], n, i, j, temp;
printf("Enter the no of the element for the array:");
scanf("%d",&n);
printf("Enter the number of the element in the array:");
for (i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
for(i=0;i<n-1;i++)
{
    for (int j=0;j<n-1-i;j++)
    {
        if (a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;

        }
    }
}
printf("the sorted array is: ");
for (int i=0;i<n;i++)
{
    printf("%d",a[i]);
}
}

