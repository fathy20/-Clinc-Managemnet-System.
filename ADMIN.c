#include "ALL_function.h"

void ADMIN_MODE(void) {
    int choice;
    u16 ID;

    // Call the password check function
    checkPassword();

    while (1) {
        printf("\nAdmin Menu:\n");
        printf("1. Add New Patient Record\n");
        printf("2. Edit Patient Record\n");
        printf("3. Reserve Slot\n");
        printf("4. Cancel Reservation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Node *newPatient = Create_Node();
                if (newPatient != NULL) {
                    Add_new_patient_record(newPatient);
                } else {
                    printf("Failed to create new patient record.\n");
                }
                break;
            }
            case 2:
                printf("Enter ID of the patient to edit: ");
                scanf("%hu", &ID);
                EditPatientRecord(ID);
                break;
            case 3:
                printf("Enter ID of the patient to reserve a slot: ");
                scanf("%hu", &ID);
                ReserveSlot(ID);
                break;
            case 4:
                printf("Enter ID of the patient to cancel reservation: ");
                scanf("%hu", &ID);
                cancel_reservation(ID);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}
