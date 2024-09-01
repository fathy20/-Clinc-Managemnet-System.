#ifndef ALL_FUNCTION_H
#define ALL_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Type definitions
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

// Definition of Node structure
typedef struct Node {
    char *name;
    u8 age;
    char *gender;
    u16 ID;
    struct Node *Next;
    struct Node *Prev;
} Node;

// Definition of Slot structure
typedef struct Slot {
    u16 patientID;
    char *timeSlot;
} Slot;

// Global variables
extern u16 attempts;
extern u16 password;
extern Slot slots[5];
extern Node *First;
extern Node *Last;

// Function prototypes for admin functions
u32 checkPassword(void);
Node *Create_Node(void);
void Add_new_patient_record(Node *Node_to_add);
void EditPatientRecord(u16 ID);
void ReserveSlot(u16 ID);
void cancel_reservation(u16 ID);

// Function prototypes for user functions
void AddNode(char *name, u8 age, char *gender, u16 ID);
void ViewPatientRecordAndReserveSlot(u16 ID);
void ViewTodaysReservations(void);
void ADMIN_MODE(void);
void User_MODE(void);




#endif // ALL_FUNCTION_H
