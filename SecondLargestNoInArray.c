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
    for(i=1;i<n;i++)
    {
        temp = A[i];
        j = i-1;
       while(temp>A[j] && j>=0)
        {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = temp;
    }
    for(i=0;i<n;i++)
     {
        printf("%d\t",A[i]);
     } 
     for(i=0;i<n;i++)
     {
        if(A[i]!=A[0])
        {
            printf("The second largest element is %d",A[i]);
            break;
        }
     }
} 