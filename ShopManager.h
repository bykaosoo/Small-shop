#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H

#include <iostream>
#include <string>

#include "Inventory.h"

using namespace std;

class ShopManager
{
private:
    string username;
    string password;
    bool accountCreated;

public:

    ShopManager()
    {
        username = "";
        password = "";
        accountCreated = false;
    }

    void createAccount()
    {
        cout << "\n=================================\n";
        cout << "       CREATE MANAGER ACCOUNT\n";
        cout << "=================================\n";

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        accountCreated = true;

        cout << "\nAccount created successfully!\n";
    }

    bool hasAccount()
    {
        return accountCreated;
    }

    bool login()
    {
        string inputUsername;
        string inputPassword;

        cout << "\n=================================\n";
        cout << "          SHOP MANAGER LOGIN\n";
        cout << "=================================\n";

        cout << "Enter username: ";
        cin >> inputUsername;

        cout << "Enter password: ";
        cin >> inputPassword;

        if (inputUsername == username &&
            inputPassword == password)
        {
            cout << "\nLogin successful!\n";
            cout << "Welcome, " << username << "!\n";

            return true;
        }

        cout << "\nInvalid username or password.\n";

        return false;
    }

    void managerMenu(Inventory& inventory)
    {
        int choice;

        do
        {
            cout << "\n=================================\n";
            cout << "        SHOP MANAGER MENU\n";
            cout << "=================================\n";
            cout << "1. Add Food Product\n";
            cout << "2. Add Electronic Product\n";
            cout << "3. View Products\n";
            cout << "4. Update Product\n";
            cout << "5. Delete Product\n";
            cout << "6. Search Product\n";
            cout << "7. Restock Product\n";
            cout << "8. Show Low Stock\n";
            cout << "9. Back\n";
            cout << "=================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    inventory.addFoodProduct();
                    break;

                case 2:
                    inventory.addElectronicProduct();
                    break;

                case 3:
                    inventory.viewProducts();
                    break;

                case 4:
                    inventory.updateProduct();
                    break;

                case 5:
                    inventory.deleteProduct();
                    break;

                case 6:
                    inventory.searchProduct();
                    break;

                case 7:
                    inventory.restockProduct();
                    break;

                case 8:
                    inventory.showLowStock();
                    break;

                case 9:
                    cout << "\nReturning to main menu...\n";
                    break;

                default:
                    cout << "\nInvalid choice. Please try again.\n";
            }

        } while (choice != 9);
    }
};

#endif
