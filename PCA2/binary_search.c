#include <stdio.h>

int binary_search(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {  // Corrected the loop condition
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements of the array in sorted order:\n"); // Move the prompt outside the loop
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element you want to search: ");
    scanf("%d", &target);
    
    int ans = binary_search(arr, n, target);
    if (ans != -1) {
        printf("%d is found in index %d\n", target, ans);
    } else {
        printf("%d is not found\n", target);
    }
    return 0;
}
