#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Product();
    Product(int id, string name, double price, int quantity);

    virtual ~Product();

    int getId() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setName(string name);
    void setPrice(double price);
    void setQuantity(int quantity);

    virtual string getType() const = 0;
    virtual void displayInfo() const;
};

#endif