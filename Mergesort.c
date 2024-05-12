#include<stdio.h>

void merge(int A[],int beg, int mid, int end)
{
    int i,j,k;
    int n1 = mid-beg+1;
    int n2 = end-mid;
    
    int LA[n1];
    int RA[n2];

    for(i=0;i<n1;i++)
        LA[i] = A[beg+i];
    for(j=0;j<n2;j++)
        RA[j] = A[mid+1+j];

    i=0;
    j=0;
    k=beg;

    while(i<n1 && j<n2)
    {
        if(LA[i]<RA[j])
        {
            A[k] = LA[i];
            i++;
        }
        else
        {
            A[k] = RA[j];
            j++;
        }
        k++;
    }    
    while(i<n1)
    {
        A[k] = LA[i];
        i++;
        k++;
    }    
     while(j<n2)
    {
        A[k] = RA[j];
        j++;
        k++;
    }    
}
void mergesort(int A[], int beg, int end)
{
    if(beg<end)
    {
        int mid = (beg + end)/2;
        mergesort(A,beg,mid);
        mergesort(A,mid+1,end);
        merge(A,beg,mid,end);
    }
}
void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}
void main()
{
    int A[] = {7,1,9,3,0,2,4,8,5};
    int n = sizeof(A)/sizeof(A[0]);
    int beg=0, end=n-1;
    printf("\nArray before sort:\n");
    display(A,n);
    mergesort(A,beg,end);
    printf("\nArray after sort:\n");
    display(A,n);
}