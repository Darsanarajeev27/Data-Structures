
#include <stdio.h>

int main() {
    int A[20][20], B[20][20], i,j,k=0,m,n,a,b;
    printf("Enter no of rows of A: ");
    scanf("%d",&m);
    printf("\nEnter no of columns of A: ");
    scanf("%d",&n);
    printf("Enter elements of A:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter element A%d%d: ",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    printf("Matrix A is: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    B[0][0] = m;
    B[0][1] = n;
    k = 1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[i][j]!=0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }
    B[0][2] = k-1;
    printf("3-Tuple form is:\n");
    for(a=0;a<k-1;a++)
    {
        for(b=0;b<3;b++)
        {
            printf("%d ",B[a][b]);
        }
        printf("\n");
    }
    
    return 0;
}