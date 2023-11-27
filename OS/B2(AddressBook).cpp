#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

void createAddressBook(std::vector<Contact>& addressBook) {
    addressBook.clear();
    std::cout << "Address book created successfully.\n";
}

void viewAddressBook(const std::vector<Contact>& addressBook) {
    if (addressBook.empty()) {
        std::cout << "Address book is empty.\n";
        return;
    }

    std::cout << "Address book:\n";
    for (const auto& contact : addressBook) {
        std::cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << "\n";
    }
}

void insertRecord(std::vector<Contact>& addressBook) {
    Contact newContact;
    std::cout << "Enter name: ";
    std::cin >> newContact.name;
    std::cout << "Enter phone number: ";
    std::cin >> newContact.phone;
    std::cout << "Enter email: ";
    std::cin >> newContact.email;

    addressBook.push_back(newContact);
    std::cout << "Record inserted successfully.\n";
}

void deleteRecord(std::vector<Contact>& addressBook) {
    if (addressBook.empty()) {
        std::cout << "Address book is empty.\n";
        return;
    }

    std::string nameToDelete;
    std::cout << "Enter the name to delete: ";
    std::cin >> nameToDelete;

    bool found = false;
    for (auto it = addressBook.begin(); it != addressBook.end(); ++it) {
        if (it->name == nameToDelete) {
            addressBook.erase(it);
            std::cout << "Record deleted successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Record not found.\n";
    }
}

void modifyRecord(std::vector<Contact>& addressBook) {
    if (addressBook.empty()) {
        std::cout << "Address book is empty.\n";
        return;
    }

    std::string nameToModify;
    std::cout << "Enter the name to modify: ";
    std::cin >> nameToModify;

    bool found = false;
    for (auto& contact : addressBook) {
        if (contact.name == nameToModify) {
            std::cout << "Enter new phone number: ";
            std::cin >> contact.phone;
            std::cout << "Enter new email: ";
            std::cin >> contact.email;
            std::cout << "Record modified successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Record not found.\n";
    }
}

int main() {
    std::vector<Contact> addressBook;
    char choice;

    do {
        std::cout << "\nOptions:\n";
        std::cout << "a) Create address book\n";
        std::cout << "b) View address book\n";
        std::cout << "c) Insert a record\n";
        std::cout << "d) Delete a record\n";
        std::cout << "e) Modify a record\n";
        std::cout << "f) Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                createAddressBook(addressBook);
                break;
            case 'b':
                viewAddressBook(addressBook);
                break;
            case 'c':
                insertRecord(addressBook);
                break;
            case 'd':
                deleteRecord(addressBook);
                break;
            case 'e':
                modifyRecord(addressBook);
                break;
            case 'f':
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'f');

    return 0;
}
