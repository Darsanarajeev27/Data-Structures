#include<stdio.h>
void main()
{
    int n,A[100],i,searchKey,flag=0;
    printf("Enter array limit: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&A[i]);
    }

    printf("Enter searchkey: ");
    scanf("%d",&searchKey);

    for(i=0;i<n;i++)
    {
        if(A[i]==searchKey)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("Element not found!");
    }
    else
    {
        printf("Element found at %d",i);
    }
}