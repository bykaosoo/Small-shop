#include <iostream>
#include <string>
#include <limits>

#include "Product.h"
#include "FoodProduct.h"
#include "ElectronicProduct.h"
#include "Inventory.h"
#include "Customer.h"
#include "ShopManager.h"

using namespace std;

int main()
{
    Inventory inventory;
    ShopManager manager;

    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << "       SMALL SHOP INVENTORY\n";
        cout << "=================================\n";
        cout << "1. Customer\n";
        cout << "2. Shop Manager\n";
        cout << "3. Exit\n";
        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int customerId;
            string name;

            cout << "\nEnter Customer ID: ";
            cin >> customerId;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Customer Name: ";
            getline(cin, name);

            Customer customer(customerId, name);

            customer.customerMenu(inventory);
        }
        else if (choice == 2)
        {
            if (!manager.hasAccount())
            {
                cout << "\nNo manager account found.\n";
                manager.createAccount();
            }

            if (manager.login())
            {
                manager.managerMenu(inventory);
            }
        }
        else if (choice == 3)
        {
            cout << "\nThank you for using Small Shop Inventory System.\n";
        }
        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
