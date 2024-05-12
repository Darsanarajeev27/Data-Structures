#include<stdio.h>
void main()
{
    int A[100],n,i,j,temp;
    printf("Enter array limit:");
    scanf("%d",&n);
    printf("Enter elements in array:\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter element A%d: ",i+1);
        scanf("%d",&A[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i]>A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    printf("The three largest elements are: %d,%d,%d",A[n-1],A[n-2],A[n-3]);
}    