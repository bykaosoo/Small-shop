#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

#include "Product.h"

using namespace std;

class Inventory
{
private:
    vector<Product*> products;

public:
    Inventory()
    {
    }

    ~Inventory()
    {
        for (Product* product : products)
        {
            delete product;
        }
    }

    bool isEmpty()
    {
        return products.empty();
    }

    bool idExists(int id)
    {
        for (Product* product : products)
        {
            if (product->getId() == id)
            {
                return true;
            }
        }

        return false;
    }

    Product* findProduct(int id)
    {
        for (Product* product : products)
        {
            if (product->getId() == id)
            {
                return product;
            }
        }

        return nullptr;
    }

    void viewProducts()
    {
        if (products.empty())
        {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "\n========== PRODUCT LIST ==========\n";

        for (Product* product : products)
        {
            product->displayInfo();
            cout << "-----------------------------\n";
        }
    }

    void searchProduct()
    {
        int id;

        cout << "Enter Product ID to search: ";
        cin >> id;

        Product* product = findProduct(id);

        if (product == nullptr)
        {
            cout << "Product not found.\n";
        }
        else
        {
            cout << "\nProduct Found:\n";
            product->displayInfo();
        }
    }

    void updateProduct()
    {
        int id;

        cout << "Enter Product ID to update: ";
        cin >> id;

        Product* product = findProduct(id);

        if (product == nullptr)
        {
            cout << "Product not found.\n";
            return;
        }

        string name;
        double price;
        int quantity;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter New Name: ";
        getline(cin, name);

        cout << "Enter New Price: ";
        cin >> price;

        cout << "Enter New Quantity: ";
        cin >> quantity;

        product->setName(name);
        product->setPrice(price);
        product->setQuantity(quantity);

        cout << "Product updated successfully.\n";
    }

    void deleteProduct()
    {
        int id;

        cout << "Enter Product ID to delete: ";
        cin >> id;

        for (auto it = products.begin(); it != products.end(); ++it)
        {
            if ((*it)->getId() == id)
            {
                delete *it;
                products.erase(it);

                cout << "Product deleted successfully.\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    void restockProduct()
    {
        int id;
        int quantity;

        cout << "Enter Product ID: ";
        cin >> id;

        Product* product = findProduct(id);

        if (product == nullptr)
        {
            cout << "Product not found.\n";
            return;
        }

        cout << "Enter quantity to add: ";
        cin >> quantity;

        product->setQuantity(product->getQuantity() + quantity);

        cout << "Product restocked successfully.\n";
    }

    void showLowStock()
    {
        bool found = false;

        cout << "\n========== LOW STOCK ==========\n";

        for (Product* product : products)
        {
            if (product->getQuantity() <= 5)
            {
                product->displayInfo();
                cout << "-----------------------------\n";
                found = true;
            }
        }

        if (!found)
        {
            cout << "No low stock products.\n";
        }
    }

    bool purchaseProduct(int id, int quantity, double& total)
    {
        Product* product = findProduct(id);

        if (product == nullptr)
        {
            return false;
        }

        if (product->getQuantity() < quantity)
        {
            return false;
        }

        product->setQuantity(
            product->getQuantity() - quantity
        );

        total = product->getPrice() * quantity;

        return true;
    }
};

#endif