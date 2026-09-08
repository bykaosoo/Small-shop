#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H

#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

class FoodProduct : public Product
{
private:
    string expiryDate;

public:
    FoodProduct()
        : Product(), expiryDate("")
    {
    }

    FoodProduct(int id, string name, double price, int quantity, string expiryDate)
        : Product(id, name, price, quantity)
    {
        this->expiryDate = expiryDate;
    }

    string getExpiryDate() const
    {
        return expiryDate;
    }

    void setExpiryDate(string expiryDate)
    {
        this->expiryDate = expiryDate;
    }

    string getType() const override
    {
        return "Food";
    }

    void displayInfo() const override
    {
        Product::displayInfo();

        cout << "Type: " << getType() << endl;
        cout << "Expiry Date: " << expiryDate << endl;
    }
};

#endif