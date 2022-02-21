//
// Created by Muwaffaq Imam on 20.02.2022.
//


#include <iostream>
#include <utility>
#include <vector>

using namespace std;


class Tenant {
    string name;
    int apartment;
public:
    Tenant(string &, int &);
    string toString();
};

class Rent {
    int apartment;
    int month;
    float rentValue;
public:
    explicit Rent(int, int, float);
    string toString();
};

class Expense {
    int month;
    string category;
    float charge;
public:
    Expense(int, string &, float );
    string toString();
};

class Landlord {
    vector<Tenant> tenantList;
    vector<Rent> rentList;
    vector<Expense> expenseList;
public:

    void manage();

    void registerTenant();

    void registerRent();

    void registerExpenses();

    void displayTenants();

    void displayRents();

    void displayExpenses();
};



