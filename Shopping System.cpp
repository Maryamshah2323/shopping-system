#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to calculate the discount based on total price
double calculateDiscount(double totalPrice) {
    if (totalPrice < 100) {
        return 0.0; // No discount
    } else if (totalPrice >= 100 && totalPrice <= 500) {
        return totalPrice * 0.10; // 10% discount
    } else {
        return totalPrice * 0.20; // 20% discount
    }
}

// Function to display the invoice
void displayInvoice(const string& itemName, int quantity, double pricePerItem, double totalPrice, double discount) {
    cout << "------------------------------" << endl;
    cout << "          INVOICE" << endl;
    cout << "------------------------------" << endl;
    cout << "Item: " << itemName << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price per Item: $" << fixed << setprecision(2) << pricePerItem << endl;
    cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
    cout << "Discount: $" << fixed << setprecision(2) << discount << endl;
    cout << "------------------------------" << endl;
    cout << "Final Amount Due: $" << fixed << setprecision(2) << (totalPrice - discount) << endl;
    cout << "------------------------------" << endl;
}

int main() {
    int categoryChoice, itemChoice, quantity;
    double pricePerItem = 0.0;

    cout << "Welcome to the Shopping System!" << endl;
    cout << "Select a category:" << endl;
    cout << "1. Electronics" << endl;
    cout << "2. Clothing" << endl;
    cout << "3. Groceries" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> categoryChoice;

    switch (categoryChoice) {
        case 1: // Electronics
            cout << "Select an item:" << endl;
            cout << "1. Laptop ($1000)" << endl;
            cout << "2. Smartphone ($700)" << endl;
            cout << "3. Headphones ($150)" << endl;
            cout << "Enter your choice (1-3): ";
            cin >> itemChoice;

            if (itemChoice == 1) pricePerItem = 1000;
            else if (itemChoice == 2) pricePerItem = 700;
            else if (itemChoice == 3) pricePerItem = 150;
            else {
                cout << "Invalid item choice!" << endl;
                return 1;
            }
            break;

        case 2: // Clothing
            cout << "Select an item:" << endl;
            cout << "1. Jacket ($120)" << endl;
            cout << "2. T-shirt ($40)" << endl;
            cout << "3. Jeans ($60)" << endl;
            cout << "Enter your choice (1-3): ";
            cin >> itemChoice;

            if (itemChoice == 1) pricePerItem = 120;
            else if (itemChoice == 2) pricePerItem = 40;
            else if (itemChoice == 3) pricePerItem = 60;
            else {
                cout << "Invalid item choice!" << endl;
                return 1;
            }
            break;

        case 3: // Groceries
            cout << "Select an item:" << endl;
            cout << "1. Milk (1 litre - $2)" << endl;
            cout << "2. Bread (1 loaf - $3)" << endl;
            cout << "3. Eggs (1 dozen - $5)" << endl;
            cout << "Enter your choice (1-3): ";
            cin >> itemChoice;

            if (itemChoice == 1) pricePerItem = 2;
            else if (itemChoice == 2) pricePerItem = 3;
            else if (itemChoice == 3) pricePerItem = 5;
            else {
                cout << "Invalid item choice!" << endl;
                return 1;
            }
            break;

        default:
            cout << "Invalid category choice!" << endl;
            return 1;
    }

    cout << "Enter quantity: ";
    cin >> quantity;

    double totalPrice = pricePerItem * quantity;
    double discount = calculateDiscount(totalPrice);
    
    displayInvoice("Selected Item", quantity, pricePerItem, totalPrice, discount);

}
