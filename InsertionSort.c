#include<stdio.h>
void main()
{
    int n,A[100],key,i,j;
    printf("Enter array limit: ");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d: ",i+1);
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++)
    {
        key = A[i];
        j = i-1;
        while(j>=0 && A[j]>key)
        {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;
    }
    printf("Sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}
