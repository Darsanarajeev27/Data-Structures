#include<stdio.h>
void main()
{
    int A[100],i,j,n,temp;
    printf("Enter array limit: ");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d: ",i+1);
        scanf("%d",&A[i]);
    }
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
        if(A[i]>A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

printf("Sorted array is:\n");
for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}