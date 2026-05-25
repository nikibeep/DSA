#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display linked list
void displayList() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Delete a node by value
void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;

    // If head node itself holds the value
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("%d deleted successfully.\n", value);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Value not found
    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);

    printf("%d deleted successfully.\n", value);
}

// Main function
int main() {
    int choice, value, n, i;

    while (1) {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Delete Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("How many nodes do you want to insert? ");
                scanf("%d", &n);

                for (i = 1; i <= n; i++) {
                    printf("Enter value for node %d: ", i);
                    scanf("%d", &value);

                    insertAtEnd(value);
                }
                break;

            case 2:
                displayList();
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                deleteNode(value);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
