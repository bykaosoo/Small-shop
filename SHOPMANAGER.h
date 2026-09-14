#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H

#include <iostream>
#include <vector>
#include "CUSTOMER.H"
using namespace std;

class ShopManager {
private:
    vector<Customer> customers;

public:
    void addCustomer(Customer customer) {
        customers.push_back(customer);
        cout << "Customer added successfully!" << endl;
    }

    void showCustomers() const {
        if (customers.empty()) {
            cout << "No customers found." << endl;
            return;
        }

        for (const Customer& customer : customers) {
            customer.displayCustomer();
            cout << "-------------------" << endl;
        }
    }

    void searchCustomer(int id) const {
        for (const Customer& customer : customers) {
            if (customer.getCustomerId() == id) {
                customer.displayCustomer();
                return;
            }
        }

        cout << "Customer not found." << endl;
    }
};

#endif