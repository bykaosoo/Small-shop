#ifndef ELECTRONICPRODUCT_H
#define ELECTRONICPRODUCT_H

#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

class ElectronicProduct : public Product
{
private:
    string brand;
    int warrantyMonths;

public:
    ElectronicProduct()
        : Product(), brand(""), warrantyMonths(0)
    {
    }

    ElectronicProduct(int id, string name, double price, int quantity,
                      string brand, int warrantyMonths)
        : Product(id, name, price, quantity)
    {
        this->brand = brand;
        this->warrantyMonths = warrantyMonths;
    }

    string getBrand() const
    {
        return brand;
    }

    int getWarrantyMonths() const
    {
        return warrantyMonths;
    }

    void setBrand(string brand)
    {
        this->brand = brand;
    }

    void setWarrantyMonths(int warrantyMonths)
    {
        if (warrantyMonths >= 0)
        {
            this->warrantyMonths = warrantyMonths;
        }
    }

    string getType() const override
    {
        return "Electronic";
    }

    void displayInfo() const override
    {
        Product::displayInfo();

        cout << "Type: " << getType() << endl;
        cout << "Brand: " << brand << endl;
        cout << "Warranty: " << warrantyMonths << " months" << endl;
    }
};

#endif