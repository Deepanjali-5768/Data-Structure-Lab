#include<stdio.h>
int main(){
int a[100], n, i, j, temp,min_ind;
printf("Enter the no of the element for the array:");
scanf("%d",&n);
printf("Enter the number of the element in the array:");
for (i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for (int i=0;i<n-1;i++)
{
    int min_ind=i;
    for(int j=i+1;j<n;j++){
        if (a[j]<a[min_ind]){
            min_ind=j;
        }
    }
    if (min_ind!=i){
        temp=a[i];
        a[i]=a[min_ind];
        a[min_ind]=temp;
    }
}
printf("the sorted array is: ");
for (int i=0;i<n;i++){
    printf("%d",a[i]);
}
}

