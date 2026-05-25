#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], result[200];
    int choice, length;

    do
    {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. Concatenation\n");
        printf("2. Comparison\n");
        printf("3. Length Calculation\n");
        printf("4. Copy Operation\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        getchar(); // Clear newline from buffer

        switch(choice)
        {
            case 1:
                // Concatenation
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);

                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);

                // Remove newline characters
                str1[strcspn(str1, "\n")] = '\0';
                str2[strcspn(str2, "\n")] = '\0';

                strcpy(result, str1);
                strcat(result, str2);

                printf("Concatenated String: %s\n", result);
                break;

            case 2:
                // Comparison
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);

                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);

                str1[strcspn(str1, "\n")] = '\0';
                str2[strcspn(str2, "\n")] = '\0';

                if(strcmp(str1, str2) == 0)
                {
                    printf("Strings are equal.\n");
                }
                else
                {
                    printf("Strings are not equal.\n");
                }
                break;

            case 3:
                // Length Calculation
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);

                str1[strcspn(str1, "\n")] = '\0';

                length = strlen(str1);

                printf("Length of string = %d\n", length);
                break;

            case 4:
                // Copy Operation
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);

                str1[strcspn(str1, "\n")] = '\0';

                strcpy(str2, str1);

                printf("Copied String: %s\n", str2);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 5);

    return 0;
}
