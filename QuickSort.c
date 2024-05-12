#include<stdio.h>

int swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
void printArray(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[100], size,i;
    printf("Enter size of the array: ");
    scanf("%d",&size);
    printf("Enter elements of the array:\n");
    for(i=0;i<size;i++){
        printf("Enter element arr%d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting: \n");
    printArray(arr, size);
    quickSort(arr, 0, size-1);
    printf("Sorted array is: \n");
    printArray(arr, size);
    return 0;
}