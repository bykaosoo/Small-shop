#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;

class Customer
{
private:
    int customerId;
    string name;
    double totalSpent;

public:
    Customer(int id, string n)
    {
        customerId = id;
        name = n;
        totalSpent = 0;
    }

    void customerMenu(Inventory& inventory)
    {
        int choice;

        do
        {
            cout << "\n=================================\n";
            cout << "          CUSTOMER MENU\n";
            cout << "=================================\n";
            cout << "1. View Products\n";
            cout << "2. Purchase Product\n";
            cout << "3. Customer Information\n";
            cout << "4. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                inventory.viewProducts();
            }
            else if (choice == 2)
            {
                int id;
                int quantity;
                double total = 0;

                cout << "\nEnter Product ID: ";
                cin >> id;

                cout << "Enter Quantity: ";
                cin >> quantity;

                if (inventory.purchaseProduct(id, quantity, total))
                {
                    totalSpent = totalSpent + total;

                    cout << "\nPurchase successful!\n";
                    cout << "Total Price: $" << fixed << setprecision(2)
                         << total << endl;
                }
                else
                {
                    cout << "\nPurchase failed.\n";
                    cout << "Product not found or not enough stock.\n";
                }
            }
            else if (choice == 3)
            {
                displayCustomer();
            }
            else if (choice == 4)
            {
                cout << "Returning to main menu...\n";
            }
            else
            {
                cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 4);
    }

    void displayCustomer()
    {
        cout << "\n=================================\n";
        cout << "       CUSTOMER INFORMATION\n";
        cout << "=================================\n";
        cout << "Customer ID : " << customerId << endl;
        cout << "Name        : " << name << endl;
        cout << "Total Spent : $" << fixed << setprecision(2)
             << totalSpent << endl;
    }

    int getCustomerId()
    {
        return customerId;
    }

    string getName()
    {
        return name;
    }

    double getTotalSpent()
    {
        return totalSpent;
    }
};

#endif