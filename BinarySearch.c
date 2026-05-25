#include <stdio.h>

int main() 
{
    int arr[100], n, target;
    int low, high, mid;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input sorted array elements
    printf("Enter %d elements in sorted order:\n", n);

    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Input target element
    printf("Enter element to search: ");
    scanf("%d", &target);

    low = 0;
    high = n - 1;

    // Binary Search
    while(low <= high) 
    {
        mid = (low + high) / 2;

        // Target found
        if(arr[mid] == target) 
        {
            printf("Element found at index %d\n", mid);
            return 0;
        }

        // Search left half
        else if(target < arr[mid]) 
        {
            high = mid - 1;
        }

        // Search right half
        else 
        {
            low = mid + 1;
        }
    }

    printf("Element not found\n");

    return 0;
}
