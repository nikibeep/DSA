#include <stdio.h>
#include <stdlib.h>

// Structure for Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int rootValue, leftValue, rightValue;

    // User input
    printf("Enter Root Node Value: ");
    scanf("%d", &rootValue);

    printf("Enter Left Child Value: ");
    scanf("%d", &leftValue);

    printf("Enter Right Child Value: ");
    scanf("%d", &rightValue);

    // Create nodes
    struct Node* root = createNode(rootValue);
    root->left = createNode(leftValue);
    root->right = createNode(rightValue);

    // Display tree values
    printf("\nRoot Node: %d\n", root->data);
    printf("Left Child: %d\n", root->left->data);
    printf("Right Child: %d\n", root->right->data);

    // Inorder Traversal
    printf("\nInorder Traversal: ");
    inorder(root);

    return 0;
}
