#include<stdio.h>
void main()
{
    int A[100], n,i,j,count=1,flag =0,temp;
    printf("Enter array limit:");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter element A%d: ",i+1);
        scanf("%d",&A[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i]==A[j])
            {
                ++count;
                temp = A[i];
                flag = 1;
                break;
            }
        }
    }
    if(flag==1)
    {
         printf("\nThe repeated element is %d with a count of %d",temp,count);
    }
    else
    {
        printf("\nNo repeating element");
    }     
}