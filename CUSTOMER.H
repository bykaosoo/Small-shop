#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    int customerId;
    string name;
    string phone;

public:
    Customer() {
        customerId = 0;
        name = "";
        phone = "";
    }

    Customer(int id, string n, string p) {
        customerId = id;
        name = n;
        phone = p;
    }

    void setCustomerId(int id) {
        customerId = id;
    }

    void setName(string n) {
        name = n;
    }

    void setPhone(string p) {
        phone = p;
    }

    int getCustomerId() const {
        return customerId;
    }

    string getName() const {
        return name;
    }

    string getPhone() const {
        return phone;
    }

    void displayCustomer() const {
        cout << "Customer ID: " << customerId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
    }
};

#endif