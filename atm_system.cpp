/*
 * Simple ATM System
 * Developer : Zulqarnain Khan Jadoon
 * Language  : C++
 * Description: A simulated ATM with balance check,
 *              deposit, withdraw and PIN change
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int    CORRECT_PIN = 1234;
const double DAILY_LIMIT = 50000.0;

void printLine(int n = 45) { cout << string(n, '=') << endl; }

void showBalance(double balance) {
    cout << "\n  Current Balance: Rs " << fixed
         << setprecision(2) << balance << endl;
}

bool confirmAmount(double amount, double balance) {
    if (amount <= 0) {
        cout << "❌ Invalid amount." << endl;
        return false;
    }
    if (amount > balance) {
        cout << "❌ Insufficient balance." << endl;
        return false;
    }
    if (amount > DAILY_LIMIT) {
        cout << "❌ Exceeds daily limit of Rs "
             << fixed << setprecision(0) << DAILY_LIMIT << endl;
        return false;
    }
    return true;
}

int main() {
    double balance  = 25000.0;
    int    pin      = CORRECT_PIN;
    int    attempts = 0;

    printLine();
    cout << "        SIMPLE ATM SYSTEM" << endl;
    cout << "  Developer: Zulqarnain Khan Jadoon" << endl;
    printLine();

    // PIN VERIFICATION
    while (attempts < 3) {
        int entered;
        cout << "\nEnter PIN: "; cin >> entered;
        if (entered == pin) break;
        attempts++;
        cout << "❌ Wrong PIN. Attempts left: " << (3 - attempts) << endl;
        if (attempts == 3) {
            cout << "\n🔒 Card blocked. Too many wrong attempts." << endl;
            return 0;
        }
    }

    cout << "\n✅ Login Successful! Welcome." << endl;

    while (true) {
        cout << "\n--- ATM Menu ---" << endl;
        cout << "  1. Check Balance"   << endl;
        cout << "  2. Deposit"         << endl;
        cout << "  3. Withdraw"        << endl;
        cout << "  4. Change PIN"      << endl;
        cout << "  5. Exit"            << endl;
        cout << "Choose (1-5): ";

        int choice; cin >> choice;

        if (choice == 1) {
            showBalance(balance);

        } else if (choice == 2) {
            double amount;
            cout << "\nDeposit Amount (Rs): "; cin >> amount;
            if (amount <= 0) { cout << "❌ Invalid amount." << endl; continue; }
            balance += amount;
            cout << "✅ Rs " << fixed << setprecision(0)
                 << amount << " deposited.";
            showBalance(balance);

        } else if (choice == 3) {
            double amount;
            cout << "\nWithdraw Amount (Rs): "; cin >> amount;
            if (!confirmAmount(amount, balance)) continue;
            balance -= amount;
            cout << "✅ Rs " << fixed << setprecision(0)
                 << amount << " withdrawn.";
            showBalance(balance);

        } else if (choice == 4) {
            int oldPin, newPin, confirm;
            cout << "\nCurrent PIN : "; cin >> oldPin;
            if (oldPin != pin) { cout << "❌ Wrong PIN." << endl; continue; }
            cout << "New PIN     : "; cin >> newPin;
            cout << "Confirm PIN : "; cin >> confirm;
            if (newPin == confirm) {
                pin = newPin;
                cout << "✅ PIN changed successfully." << endl;
            } else {
                cout << "❌ PINs do not match." << endl;
            }

        } else if (choice == 5) {
            printLine();
            cout << "  Thank you for using ATM System" << endl;
            cout << "  Developer: Zulqarnain Khan Jadoon" << endl;
            printLine();
            break;

        } else {
            cout << "⚠  Invalid choice. Enter 1-5." << endl;
        }
    }
    return 0;
}
