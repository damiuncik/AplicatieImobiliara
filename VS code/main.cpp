#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include "class.h"

using namespace std;


int main() {
    string password = "password";  // Initial password
    string securityQuestion = "How many cats does Damian have?";
    string securityAnswer = "Three";

    string enteredPassword;
    string enteredAnswer;

    while (true) {
        int choice;//First menu for password
        cout << "------------------ Real Estate Agency ------------------\n";
        cout << "1. Change Password\n";
        cout << "2. Access Program\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {cout << "Security Question: " << securityQuestion << endl;
                cout << "Enter your answer: ";
                cin >> enteredAnswer;
                if (enteredAnswer == securityAnswer) {
                    cout << "Enter a new password: ";

                    // Hiding password characters
                    char ch;
                    enteredPassword = "";
                    while (true) {
                        ch = _getch();
                        if (ch == 13) // Enter key
                            break;
                        enteredPassword += ch;
                        cout << "*";
                    }

                    password = enteredPassword;
                    cout << "\nPassword changed successfully!\n";
            }
            case 2: {
                cout << "Enter the password to access the program: ";

                // Hiding password characters
                char ch;
                enteredPassword = "";
                while (true) {
                    ch = _getch();
                    if (ch == 13) // Enter key
                        break;
                    enteredPassword += ch;
                    cout << "*";
                }

                cout << endl;

                // Password check
                if (enteredPassword != password) {
                    cout << "Incorrect password. Access denied." << endl;
                } else {
                    RealEstateAgency agency;
                    int choice;//Main menu
                    while (true) {
                        cout << "------------------ Real Estate Agency ------------------\n";
                        cout << "1. Add Property\n";
                        cout << "2. Add Request\n";
                        cout << "3. Add Offer\n";
                        cout << "4. Add Loyal Customer\n";
                        cout << "5. Process Transactions\n";
                        cout << "6. Exit\n";
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 1: {
                                string type, area;
                                int rooms;
                                double price;
                                cout << "Enter property type: ";
                                cin >> type;
                                cout << "Enter number of rooms: ";
                                cin >> rooms;
                                cout << "Enter area: ";
                                cin >> area;
                                cout << "Enter price: ";
                                cin >> price;
                                agency.addProperty(type, rooms, area, price);
                                cout << "Property added successfully!\n";
                                break;
                            }
                            case 2: {
                                string type, area,customerName;
                                int rooms;
                                double maxPrice;
                                cout << "Enter customer name: ";
                                cin >> customerName;
                                cout << "Enter request type: ";
                                cin >> type;
                                cout << "Enter number of rooms: ";
                                cin >> rooms;
                                cout << "Enter area: ";
                                cin >> area;
                                cout << "Enter maximum price: ";
                                cin >> maxPrice;
                                agency.addRequest(type, rooms, area, maxPrice, customerName);
                                cout << "Request added successfully!\n";
                                break;
                            }
                            case 3: {
                                string type, area;
                                int rooms;
                                double minPrice;
                                cout << "Enter offer type: ";
                                cin >> type;
                                cout << "Enter number of rooms: ";
                                cin >> rooms;
                                cout << "Enter area: ";
                                cin >> area;
                                cout << "Enter minimum price: ";
                                cin >> minPrice;
                                agency.addOffer(type, rooms, area, minPrice);
                                cout << "Offer added successfully!\n";
                                break;
                            }
                            case 4: {
                                string customerName;
                                cout << "Enter customer name: ";
                                cin >> customerName;
                                agency.addLoyalCustomer(customerName);
                                cout << "Loyal customer added successfully!\n";
                                break;
                            }
                            case 5: {
                                agency.processTransactions();
                                break;
                            }
                            case 6: {
                                cout << "Exiting the program...\n";
                                return 0;
                            }
                            default: {
                                cout << "Invalid choice. Please try again.\n";
                                break;
                            }
                        }

                        cout << "\n";
                    }
                                    cout << "\n";
                                }
                                break;
                            }
                            case 3: {
                                cout << "Exiting the program...\n";
                                return 0;
                            }
                            default: {
                                cout << "Invalid choice. Please try again.\n";
                                break;
                            }
                        }
                    }

    return 0;
}
}