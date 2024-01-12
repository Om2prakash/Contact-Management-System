#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;
// Structure to represent contact details
struct Contact {
    string phone;

    
    string email;
};

// Function to load contacts from a file
map<string, Contact> loadContacts() {
    map<string, Contact> contacts;
    ifstream file("contacts.txt");

    if (file.is_open()) {
        string name;
        
        Contact details;

        while (file >>name >> details.phone >>details.email) {
            contacts[name] = details;
        }

        file.close();
    }
    return contacts;
}
// Function to save contacts to a file
void saveContacts(const map<string, Contact>& contacts) {
    ofstream file("contacts.txt");

    for (const auto& entry : contacts) {
        file<< entry.first <<" " << entry.second.phone << " " << entry.second.email << "\n";
    }

    file.close();
}
// Function to add a new contact
void addContact(map<string, Contact>& contacts) {
    string name;
   
    cout << "Enter the contact's name: ";
    cin >> name;
    

    Contact details;
     
    cout << "Enter the contact's phone number: ";
    cin >> details.phone;
    cout << "Enter the contact's email address: ";
    cin >> details.email;

    contacts[name] = details;
    saveContacts(contacts);
    cout << "Contact " << name << " added successfully!\n";
}

// Function to display all contacts
void displayContacts(const map<string, Contact>& contacts) {
    if (contacts.empty()) {

        cout << "No contacts available.\n";
    } else {
        cout << "\nContacts:\n";
        for (const auto& entry : contacts) {
            cout << "Name: " << entry.first << " " << ", Phone: " << entry.second.phone << ", Email: " << entry.second.email << "\n";
        }
        cout << "\n";
    }
}

// Function to search for a contact
void searchContact(const map<string, Contact>& contacts) {
    string name;
    cout << "Enter the name to search: ";
    cin >> name;

    auto it = contacts.find(name);
    if (it != contacts.end()) {
        cout << "\nContact found:\n";
        cout << "Name: " << it->first << ", Phone: " << it->second.phone << ", Email: " << it->second.email << "\n";
    } else {
        cout << "Contact with name '" << name << "' not found.\n";
    }
}

// Function to delete a contact
void deleteContact(map<string, Contact>& contacts) {
    string name;
    cout << "Enter the name to delete: ";
    cin >> name;

    auto it = contacts.find(name);
    if (it != contacts.end()) {
        contacts.erase(it);
        saveContacts(contacts);
        cout << "Contact " << name << " deleted successfully!\n";
    } else {
        cout << "Contact with name '" << name << "' not found.\n";
    }
}

// Main function to run the contact management system
int main() {
    map<string, Contact> contacts = loadContacts();

    while (true) {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                cout << "Exiting Contact Management System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}

