#include <iostream>
#include <string>

using namespace std;

#define MAX_CONTACTS 100

struct Contact {
    string name;
    string phone;
};

void addContact(Contact contacts[], int& numContacts) {
    if (numContacts >= MAX_CONTACTS) {
        cout << "Contact list is full.\n";
        return;
    }
    
    cout << "Enter the name of the contact: ";
    cin >> contacts[numContacts].name;
    cout << "Enter the phone number of the contact: ";
    cin >> contacts[numContacts].phone;
    
    numContacts++;
    cout << "Contact added successfully.\n";
}

void displayContacts(Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        cout << "No contacts found.\n";
        return;
    }
    
    cout << "Contact List:\n";
    for (int i = 0; i < numContacts; i++) {
        cout << i + 1 << ". Name: " << contacts[i].name 
             << ", Phone: " << contacts[i].phone << "\n";
    }
}

void searchContact(Contact contacts[], int numContacts) {
    string searchName;
    cout << "Enter the name of the contact to search for: ";
    cin >> searchName;
    
    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].name == searchName) {
            cout << "Contact found:\n";
            cout << "Name: " << contacts[i].name 
                 << ", Phone: " << contacts[i].phone << "\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}

void updateContact(Contact contacts[], int numContacts) {
    string updateName;
    cout << "Enter the name of the contact to update: ";
    cin >> updateName;
    
    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].name == updateName) {
            cout << "Enter the new phone number: ";
            cin >> contacts[i].phone;
            cout << "Contact updated successfully.\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}

void deleteContact(Contact contacts[], int& numContacts) {
    string deleteName;
    cout << "Enter the name of the contact to delete: ";
    cin >> deleteName;
    
    int index = -1;
    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].name == deleteName) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        cout << "Contact not found.\n";
        return;
    }
    
    // Shift remaining contacts
    for (int i = index; i < numContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    numContacts--;
    
    cout << "Contact deleted successfully.\n";
}

void displayTotalContacts(int numContacts) {
    cout << "Total number of contacts: " << numContacts << "\n";
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    
    do {
        cout << "\nContact Management System\n";
        cout << "1. Add a contact\n";
        cout << "2. Display all contacts\n";
        cout << "3. Search for a contact\n";
        cout << "4. Update a contact\n";
        cout << "5. Delete a contact\n";
        cout << "6. Display total number of contacts\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addContact(contacts, numContacts); break;
            case 2: displayContacts(contacts, numContacts); break;
            case 3: searchContact(contacts, numContacts); break;
            case 4: updateContact(contacts, numContacts); break;
            case 5: deleteContact(contacts, numContacts); break;
            case 6: displayTotalContacts(numContacts); break;
            case 7: cout << "Exiting the program.\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}
