#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push operation
void push(char item) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Pop operation
char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to check precedence
int precedence(char symbol) {
    switch(symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        // Ignore spaces
        if (symbol == ' ')
            continue;

        // Operand
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }

        // Opening bracket
        else if (symbol == '(') {
            push(symbol);
        }

        // Closing bracket
        else if (symbol == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }

        // Operator
        else {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];
    int choice;

    while (1) {
        printf("\n--- INFIX TO POSTFIX MENU ---\n");
        printf("1. Convert Expression\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        getchar(); // Clear newline from buffer

        switch(choice) {
            case 1:
                printf("Enter Infix Expression: ");
                fgets(infix, SIZE, stdin);

                // Remove newline character
                infix[strcspn(infix, "\n")] = '\0';

                top = -1; // Reset stack

                infixToPostfix(infix, postfix);

                printf("Postfix Expression: %s\n", postfix);
                break;

            case 2:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
