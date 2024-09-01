#include "ALL_function.h"

void User_MODE(void) {
    int choice;
    u16 patientID;

    // Initialize slots with default values
    slots[0] = (Slot){0, "2:00pm to 2:30pm"};
    slots[1] = (Slot){0, "2:30pm to 3:00pm"};
    slots[2] = (Slot){0, "3:00pm to 3:30pm"};
    slots[3] = (Slot){0, "4:00pm to 4:30pm"};
    slots[4] = (Slot){0, "4:30pm to 5:00pm"};

    do {
        printf("\n--- Patient Management System ---\n");
        printf("1. View Patient Record and Reserve Slot\n");
        printf("2. View Today's Reservations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%hu", &patientID);
                ViewPatientRecordAndReserveSlot(patientID);
                break;
            case 2:
                ViewTodaysReservations();
                break;
            case 3:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
}
