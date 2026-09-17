#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Product
{
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Product()
    {
        id = 0;
        name = "";
        price = 0;
        quantity = 0;
    }

    Product(int id, string name, double price, int quantity)
    {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    virtual ~Product()
    {
    }

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    int getQuantity() const
    {
        return quantity;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setPrice(double price)
    {
        if (price >= 0)
        {
            this->price = price;
        }
    }

    void setQuantity(int quantity)
    {
        if (quantity >= 0)
        {
            this->quantity = quantity;
        }
    }

    virtual string getType() const = 0;

    virtual void displayInfo() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

#endif