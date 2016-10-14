// Program id: CSLab05.cpp
// This is our template for CS Lab 05
// REFACTORING PRACTICE PROGRAM
// This program is used for the University of Akron, Department of Computer Science Laboratories
// Goal: refactor main into functions
// examine each portion in main and analyze the code for refactoring
// Next build your function prototype
// Next build your function by copying and pasting the code from main, into your function
// repeat until complete

#include<iostream>
#include <iomanip>

using namespace std; // forgive me for being lazy!

const double TAX_RATE = .05;

double getPrice();
int getQuantity();
char getSaleType();
double calculateTotal(double price, int quantity, char saleType);
void displayTotal(double price, double total, int quantity, char saleType);

int main()
{
    double price = getPrice();
    int quantity = getQuantity();
    char saleType = getSaleType();
    double total = calculateTotal(price, quantity, saleType);

    displayTotal(price, total, quantity, saleType);

    return 0;
}

// FUNCTION BLOCK //

double getPrice()
{
    double price = 0;
    cout << "Enter price $";
    cin >> price;
    return price;
}

int getQuantity()
{
    int quantity = 0;
    cout << "Enter number purchased: ";
    cin >> quantity;
    return quantity;
}

char getSaleType()
{
    char saleType;
    cout << "Type W if this is wholesale purchase. \n"
         << "Type R if this is retail purchase. \n"
         << "then press return... \n";
    cin.ignore();
    cin.get(saleType);
    return saleType;
}

double calculateTotal(double price, int quantity, char saleType)
{
    double total = 0, subTotal = 0;

    if ((saleType == 'W') || (saleType == 'w'))
    {
        total = price * quantity;
    }
    else if ((saleType == 'R') || (saleType == 'r'))
    {
        subTotal = price * quantity;
        total = subTotal + subTotal * TAX_RATE;
    }
    else
    {
        cout << "Error in the input...";
    }

    return total;
}

void displayTotal(double price, double total, int quantity, char saleType)
{
    cout << setprecision(2) << fixed << showpoint << quantity << " items at $" << price << endl;
    cout << "Total bill $" << total;
    if ((saleType == 'R') || (saleType == 'r'))
    {
        cout << " includes sales tax.\n";
    }
}
