#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100]; 
    int n,target; 
    printf("Enter array limit: ");
    scanf("%d",&n);
    printf("Enter %d array elements: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element %d is present at index %d.\n", target, result);
    else
        printf("Element %d is not present in the array.\n", target);

    return 0;
}
