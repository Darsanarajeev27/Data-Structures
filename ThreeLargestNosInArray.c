#include<stdio.h>
void main()
{
    int A[100], n,first,second,third;
    first = second = third = -1;
    printf("Enter array limit:");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter element A%d:",i+1);
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]>first)
        {
            third = second;
            second = first;
            first = A[i];     
        }
        else if(A[i]>second)
        {
            third = second;
            second = A[i];
        }
        else if(A[i]>third)
        {
            third = A[i];
        } 
}
printf("Three largest elements are: %d,%d,%d",first,second,third);
}