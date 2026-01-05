#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

void header() {
    cout << "=====================================\n";
    cout << "     ☕ COFFEE SHOP BILLING SYSTEM   \n";
    cout << "=====================================\n";
}

void showMenu() {
    cout << "\n------- MENU -------\n";
    cout << "1. Espresso        - Rs.250\n";
    cout << "2. Cappuccino      - Rs.300\n";
    cout << "3. Latte           - Rs.280\n";
    cout << "4. Cold Coffee     - Rs.350\n";
    cout << "5. Chocolate Shake - Rs.400\n";
    cout << "--------------------\n";
}

int main() {
    system("cls");
    header();

    string customerName;
    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    int choice, qty;
    double total = 0;
    char again;

    do {
        showMenu();
        cout << "\nEnter Item Number: ";
        cin >> choice;
        cout << "Enter Quantity: ";
        cin >> qty;

        switch (choice) {
            case 1: total += qty * 250; break;
            case 2: total += qty * 300; break;
            case 3: total += qty * 280; break;
            case 4: total += qty * 350; break;
            case 5: total += qty * 400; break;
            default: cout << "Invalid Choice!\n";
        }

        cout << "\nAdd more items? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    system("cls");
    header();

    double tax = total * 0.1; // 10% tax
    double netBill = total + tax;

    cout << "Customer: " << customerName << endl;
    cout << "-------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Total Amount:      Rs. " << total << endl;
    cout << "Sales Tax (10%):   Rs. " << tax << endl;
    cout << "-------------------------------------\n";
    cout << "Net Bill:          Rs. " << netBill << endl;
    cout << "-------------------------------------\n";

    cout << "\nThank you for visiting ☕!\n";
    cout << "Please visit again soon.\n";

    cout << "\nPress any key to exit...";
    system("pause>0");
}
