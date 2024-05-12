#include<stdio.h>

int V;

//function to initialize the matrix to zero
void init(int A[][V]){
    int i, j;
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            A[i][j] = 0;
}

//function to add edges to graph
void insertEdge(int A[][V], int i, int j){
    A[i][j] = 1;
    A[j][i] = 1;
}

//function to print the matrix elements
void printAdjMatrix(int A[][V]){
    int i, j;
    for(i=0;i<V;i++){
        printf("%d: ",i);
        for(j=0;j<V;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
int main(){ 
    printf("Enter no of vertices: ");
    scanf("%d",&V);
    int adjMatrix[V][V];
    init(adjMatrix);
    insertEdge(adjMatrix,0,1);
    insertEdge(adjMatrix,0,2);
    insertEdge(adjMatrix,1,2);
    insertEdge(adjMatrix,2,0);
    insertEdge(adjMatrix,2,3);
    printAdjMatrix(adjMatrix);

    return 0;

}