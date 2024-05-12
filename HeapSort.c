#include<stdio.h>
int n,i;
int A[20];

void display();
void swap(int *a,int *b);
void heapsort(int A[],int n);
void heapify(int A[], int n, int i);

void display(){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
}

void heapify(int A[], int n,int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left<n && A[left]>A[largest])
        largest = left;
    if(right<n && A[right]>A[largest])
        largest = right;
    if(largest !=i){
        swap(&A[i],&A[largest]);
        heapify(A,n,largest);  
    }          
}

void heapsort(int A[], int n){
    //Build max heap
    for(i=n/2 -1;i>=0;i--)
        heapify(A,n,i);
   
    //heapifying after swapping
    for(i=n-1;i>=0;i--){
        swap(&A[0],&A[i]);
        heapify(A,i,0);
    }    
}

void main(){
    printf("Enter array limit: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++){
        printf("Enter element A%d: ",i);
        scanf("%d",&A[i]);
    }
    printf("Array before sorting:\n");
    display();
    heapsort(A,n);
    printf("Array after sorting:\n");
    display();
}