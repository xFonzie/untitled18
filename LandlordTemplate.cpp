//
// Created by Muwaffaq Imam on 20.02.2022.
//

#include "LandlordTemplate.h"

char getChar()                 // get a character
{
    char ch = cin.get();
    cin.ignore(80, '\n');
    return ch;
}

void getaLine(string &inStr)    // get line of text
{
    char temp[21];
    cin.get(temp, 20, '\n');
    cin.ignore(20, '\n');
    inStr = temp;
}



void Landlord::registerTenant()       //get tenantName info
{
    cout << "Enter tenant name: ";
    string name;
    getaLine(name);

    cout << "Enter tenant apartment: ";
    int apartment;
    cin >> apartment;

    tenantList.emplace_back(Tenant(name, apartment));
}

void Landlord::registerRent()       //get tenantName info
{
    cout << "Enter apartment number: ";
    int apt;
    cin >> apt;

    cout << "Enter month number (from 1 to 12): ";
    int month;
    cin >> month;

    cout << "Enter rent value (i.e. 312.45): ";
    float rentValue;
    cin >> rentValue;

    this->rentList.emplace_back(Rent(apt, month, rentValue));
}

void Landlord::registerExpenses() {
    cout << "Enter month number (from 1 to 12): ";
    int month;
    cin >> month;

    cout << "Enter category of the expense: ";
    string category;
    getaLine(category);

    cout << "Enter amount of money: ";
    float charge;
    cin >> charge;

    this->expenseList.emplace_back(Expense(month, category, charge));
}

void Landlord::displayTenants() {
    cout << "-------------- Display Tenants ------------ " <<  endl;
    for (auto tenant : this->tenantList)
        cout << tenant.toString() << "\n";
    cout << "---------------------------------------- " <<  endl;

}

void Landlord::displayRents() {
    cout << "-------------- Display Rent ------------ " <<  endl;
    for (auto rent : this->rentList)
        cout << rent.toString() << "\n";
    cout << "---------------------------------------- " <<  endl;
}

void Landlord::displayExpenses() {
    cout << "-------------- Display Expenses ------------ " <<  endl;
    for (auto expense : this->expenseList)
        cout << expense.toString() << "\n";
    cout << "---------------------------------------- " <<  endl;
}


void Landlord::manage() {
    char ch;
    while (true) {
        cout << "Enter 'i' to input data, \n"
             << "      'd' to display a report, \n"
             << "      'q' to quit program: ";
        ch = getChar();
        if (ch == 'i')                                // enter data
        {
            cout << "Enter 't' to add tenantName, \n"
                 << "      'r' to record rent payment, \n"
                 << "      'e' to record expense: ";
            ch = getChar();
            switch (ch) {
                //input screens exist only while being used
                case 't': {
                    /// TODO add tenants
                    this->registerTenant();
                    break;
                }
                case 'r': {
                    /// TODO Add Rent record
                    this->registerRent();
                    break;
                }
                case 'e': {
                    /// TODO Add expense record
                    this->registerExpenses();
                    break;
                }
                default: {
                    cout << "Unknown input option\n";
                    break;
                }
            }  // end switch
        }  // end if
        else if (ch == 'd')                           // display data
        {
            cout << "Enter 't' to display tenants, \n"
                 << "      'r' to display rents\n"
                 << "      'e' to display expenses, \n"
                 << "      'a' to display annual report: ";
            ch = getChar();
            switch (ch) {
                case 't':
                    /// TODO display Tenants record
                    this->displayTenants();
                    break;
                case 'r':
                    /// TODO display Rent record
                    this->displayRents();
                    break;
                case 'e':
                    /// TODO display Expenses record
                    this->displayExpenses();
                    break;
                case 'a':
                    /// Homework : display Annual record
                    /// The program displays the Annual Summary, which consists of
                    /// 1. The sum of all rents paid for the year to date
                    /// 2. A list of the total expenses for each budget category
                    /// 3. The resulting balance (profit or loss for the year to date)
                    break;
                default:
                    cout << "Unknown display option\n";
                    break;
            }  // end switch
        }  // end elseif
        else if (ch == 'q')
            return;
        else
            cout << "Unknown option. Enter only 'i', 'd' or 'q'\n";
    }
}


int main() {
    Landlord landlord;
    landlord.manage();
}

Tenant::Tenant(string & name, int & apartment) {
    this->name = name;
    this->apartment = apartment;
}

string Tenant::toString() {
    return  "Name: " + this->name + 
            "\tApartment: " + to_string(apartment);
}

Rent::Rent(int apartment, int month, float rentValue) {
    this->apartment = apartment;
    this->month = month;
    this->rentValue = rentValue;
}

string Rent::toString() {
    return  "Month: " + to_string(this->month) +
            "\tApartment: " + to_string(this->apartment) +
            "\tRent value: " + to_string(this->rentValue);
}

Expense::Expense(int month, string & category, float charge) {
    this->month = month;
    this->category = category;
    this->charge = charge;
}

string Expense::toString() {
    return  "Month: " + to_string(this->month) +
            "\tCategory: " + this->category +
            "\tCharge: " + to_string(this->charge);
}
