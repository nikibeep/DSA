#include <stdio.h>

#define MAX 100

// Function declarations
void display(int arr[], int n);
void accessElement(int arr[], int n);
void insertElement(int arr[], int *n);
void deleteElement(int arr[], int *n);
void searchElement(int arr[], int n);

int main()
{
    int arr[MAX], n, i, choice;

    // Input initial array size
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n===== ARRAY OPERATIONS MENU =====\n");
        printf("1. Display Array\n");
        printf("2. Access Element\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                display(arr, n);
                break;

            case 2:
                accessElement(arr, n);
                break;

            case 3:
                insertElement(arr, &n);
                break;

            case 4:
                deleteElement(arr, &n);
                break;

            case 5:
                searchElement(arr, n);
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 6);

    return 0;
}

// Function to display array
void display(int arr[], int n)
{
    int i;

    if(n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements are:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Function to access element
void accessElement(int arr[], int n)
{
    int index;

    printf("Enter index to access (0 to %d): ", n - 1);
    scanf("%d", &index);

    if(index >= 0 && index < n)
    {
        printf("Element at index %d is %d\n", index, arr[index]);
    }
    else
    {
        printf("Invalid index!\n");
    }
}

// Function to insert element
void insertElement(int arr[], int *n)
{
    int pos, value, i;

    if(*n >= MAX)
    {
        printf("Array is full.\n");
        return;
    }

    printf("Enter position to insert (0 to %d): ", *n);
    scanf("%d", &pos);

    if(pos < 0 || pos > *n)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    // Shift elements to right
    for(i = *n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert new element
    arr[pos] = value;

    (*n)++;

    printf("Element inserted successfully.\n");
}

// Function to delete element
void deleteElement(int arr[], int *n)
{
    int pos, i;

    if(*n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter position to delete (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    if(pos < 0 || pos >= *n)
    {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements left
    for(i = pos; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully.\n");
}

// Function to search element
void searchElement(int arr[], int n)
{
    int value, i, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &value);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == value)
        {
            printf("Element found at position %d\n", i);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("Element not found.\n");
    }
}
