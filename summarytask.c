#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_CONTACTS 100

void addContact(char** names, char** phones, int* numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }
    
    // Allocate memory for the new contact's name and phone number
    names[*numContacts] = malloc(MAX_NAME_LENGTH * sizeof(char));
    phones[*numContacts] = malloc(MAX_PHONE_LENGTH * sizeof(char));
    
    printf("Enter the name of the contact: ");
    scanf("%s", names[*numContacts]);
    
    printf("Enter the phone number of the contact: ");
    scanf("%s", phones[*numContacts]);
    
    (*numContacts)++;
    
    printf("Contact added successfully.\n");
}

void displayContacts(char** names, char** phones, int numContacts) {
    if (numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }
    
    printf("Contact List:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, names[i], phones[i]);
    }
}

void searchContact(char** names, char** phones, int numContacts) {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to search for: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s, Phone: %s\n", names[i], phones[i]);
            return;
        }
    }
    
    printf("Contact not found.\n");
}

void updateContact(char** names, char** phones, int numContacts) {
    char updateName[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to update: ");
    scanf("%s", updateName);
    
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(names[i], updateName) == 0) {
            printf("Enter the new phone number: ");
            scanf("%s", phones[i]);
            printf("Contact updated successfully.\n");
            return;
        }
    }
    
    printf("Contact not found.\n");
}

void deleteContact(char** names, char** phones, int* numContacts) {
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", deleteName);
    
    int contactIndex = -1;
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(names[i], deleteName) == 0) {
            contactIndex = i;
            break;
        }
    }
    
    if (contactIndex == -1) {
        printf("Contact not found.\n");
        return;
    }
    
    // Free the memory occupied by the contact's name and phone number
    free(names[contactIndex]);
    free(phones[contactIndex]);
    
    // Shift the remaining contacts in the arrays
    for (int i = contactIndex; i < *numContacts - 1; i++) {
        names[i] = names[i + 1];
        phones[i] = phones[i + 1];
    }
    
    (*numContacts)--;
    
    printf("Contact deleted successfully.\n");
}

void displayTotalContacts(int numContacts) {
    printf("Total number of contacts: %d\n", numContacts);
}

int main() {
    char* contactNames[MAX_CONTACTS];  // Array to store contact names
    char* contactPhones[MAX_CONTACTS]; // Array to store contact phone numbers
    int numContacts = 0;               // Number of contacts in the list
    
    int choice;
    do {
        printf("\nContact Management System\n");
        printf("1. Add a contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Update a contact\n");
        printf("5. Delete a contact\n");
        printf("6. Display total number of contacts\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(contactNames, contactPhones, &numContacts);
                break;
            case 2:
                displayContacts(contactNames, contactPhones, numContacts);
                break;
            case 3:
                searchContact(contactNames, contactPhones, numContacts);
                break;
            case 4:
                updateContact(contactNames, contactPhones, numContacts);
                break;
            case 5:
                deleteContact(contactNames, contactPhones, &numContacts);
                break;
            case 6:
                displayTotalContacts(numContacts);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
    // Free dynamically allocated memory before exiting
    for (int i = 0; i < numContacts; i++) {
        free(contactNames[i]);
        free(contactPhones[i]);
    }
    
    return 0;
}
