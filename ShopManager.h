#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H

#include <iostream>
#include <vector>
#include "CUSTOMER.h"

using namespace std;

class ShopManager
{
private:
    vector<Customer> customers;

public:
    void addCustomer();
    void showCustomers();
    void searchCustomer();
};

#endif