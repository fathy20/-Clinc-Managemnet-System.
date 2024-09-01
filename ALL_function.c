#include "ALL_function.h"

// Initialize global variables
u16 attempts = 0;
u16 password = 1234;
Slot slots[5] = {
    {0, "2:00pm to 2:30pm"},
    {0, "2:30pm to 3:00pm"},
    {0, "3:00pm to 3:30pm"},
    {0, "4:00pm to 4:30pm"},
    {0, "4:30pm to 5:00pm"}
};

Node *First = NULL;
Node *Last = NULL;

// Function to check the password
u32 checkPassword(void) {
    u16 enteredPassword;

    while (attempts < 3) {
        printf("Enter admin password: ");
        scanf("%hu", &enteredPassword);

        if (enteredPassword == password) {
            printf("Login successful.\n");
            return 1; // Success indicator
        } else {
            printf("Incorrect password. Try again.\n");
            attempts++;
        }
    }

    // If 3 incorrect attempts are made, exit the program
    printf("Too many incorrect attempts. System closing.\n");
    exit(0);
}

// Function to create a new node
Node *Create_Node(void) {
    Node *Created_Node = (Node *)malloc(sizeof(Node));
    if (Created_Node != NULL) {
        Created_Node->name = (char *)malloc(100 * sizeof(char));
        Created_Node->gender = (char *)malloc(10 * sizeof(char));

        if (Created_Node->name == NULL || Created_Node->gender == NULL) {
            printf("Memory allocation failed\n");
            free(Created_Node);
            return NULL;
        }

        printf("\nEnter name: ");
        scanf("%s", Created_Node->name);
        printf("\nEnter age: ");
        scanf("%hhu", &Created_Node->age);
        printf("\nEnter gender: ");
        scanf("%s", Created_Node->gender);
        printf("\nEnter ID: ");
        scanf("%hu", &Created_Node->ID);

        Created_Node->Next = Created_Node->Prev = NULL;
    } else {
        printf("Memory Error\n");
    }
    return Created_Node;
}

// Function to add a new patient record
void Add_new_patient_record(Node *Node_to_add) {
    if (Node_to_add != NULL) {
        if (First == NULL && Last == NULL) {
            First = Last = Node_to_add;
        } else {
            Last->Next = Node_to_add;
            Node_to_add->Prev = Last;
            Last = Node_to_add;
        }
    } else {
        printf("Error: Reject the entry!\n");
    }
}

// Function to edit a patient record
void EditPatientRecord(u16 ID) {
    Node *current = First;
    while (current != NULL) {
        if (current->ID == ID) {
            // Patient ID found, proceed with editing
            printf("Editing patient with ID: %u\n", ID);
            printf("Enter new name: ");
            char newName[100];
            scanf("%s", newName);
            free(current->name);
            current->name = (char *)malloc(strlen(newName) + 1);
            if (current->name != NULL) {
                strcpy(current->name, newName);
            } else {
                printf("Memory allocation for new name failed\n");
                return;
            }

            printf("Enter new age: ");
            scanf("%hhu", &current->age);

            printf("Enter new gender: ");
            char newGender[10];
            scanf("%s", newGender);
            free(current->gender);
            current->gender = (char *)malloc(strlen(newGender) + 1);
            if (current->gender != NULL) {
                strcpy(current->gender, newGender);
            } else {
                printf("Memory allocation for new gender failed\n");
                return;
            }

            printf("Patient record updated successfully!\n");
            return;
        }
        current = current->Next;
    }
    printf("Incorrect ID: %u. No patient found.\n", ID);
}

// Function to reserve a slot
void ReserveSlot(u16 ID) {
    // Display available slots
    printf("Available Slots:\n");
    for (int i = 0; i < 5; i++) {
        if (slots[i].patientID == 0) {
            printf("%d. %s\n", i + 1, slots[i].timeSlot);
        }
    }

    // Reserve a slot
    int slotNumber;
    printf("Enter the slot number to reserve for this patient: ");
    scanf("%d", &slotNumber);

    // Validate the input
    if (slotNumber < 1 || slotNumber > 5 || slots[slotNumber - 1].patientID != 0) {
        printf("Invalid slot or slot already reserved.\n");
    } else {
        slots[slotNumber - 1].patientID = ID;
        printf("Slot %s reserved for Patient ID %u.\n", slots[slotNumber - 1].timeSlot, ID);
    }
}

// Function to view a patient record and reserve a slot
void ViewPatientRecordAndReserveSlot(u16 ID) {
    Node *current = First;
    while (current != NULL) {
        if (current->ID == ID) {
            printf("Patient ID: %u\n", current->ID);
            printf("Name: %s\n", current->name);
            printf("Age: %u\n", current->age);
            printf("Gender: %s\n", current->gender);

            // Call ReserveSlot function
            ReserveSlot(ID);
            return;
        }
        current = current->Next;
    }
    printf("Patient with ID %u not found.\n", ID);
}

// Function to view today's reservations
void ViewTodaysReservations(void) {
    int hasReservations = 0;

    printf("Today's Reservations:\n");
    for (int i = 0; i < 5; i++) {
        if (slots[i].patientID != 0) {
            printf("Slot %d: Patient ID %u at %s\n", i + 1, slots[i].patientID, slots[i].timeSlot);
            hasReservations = 1;
        }
    }

    if (!hasReservations) {
        printf("No reservations for today.\n");
    }
}

// Function to cancel a reservation
void cancel_reservation(u16 ID) {
    int i;
    int found = 0;

    // Iterate through all slots to find the reservation
    for (i = 0; i < 5; i++) {
        if (slots[i].patientID == ID) {
            // Found the reservation, cancel it
            slots[i].patientID = 0;
            printf("Reservation for Patient ID %u has been cancelled.\n", ID);
            found = 1;
            break;
        }
    }

    // If no reservation was found
    if (!found) {
        printf("No reservation found for Patient ID %u.\n", ID);
    }
}
