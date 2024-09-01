#include "ALL_function.h"

int main(void) {
    int choice;

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. User Mode\n");
        printf("2. Admin Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                User_MODE();  // Call the user mode function
                break;
            case 2:
                ADMIN_MODE(); // Call the admin mode function
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);     // Exit the program
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
