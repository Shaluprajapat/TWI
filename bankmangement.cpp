#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Structure to represent a customer
struct Customer {
    string name;
    int accountNumber;
    float balance;
};

// Structure to represent an account
struct Account {
    int accountNumber;
    string accountType;
    float balance;
};

// Map to store customer accounts
map<int, Account> accounts;

// Function to set up the system
void setupSystem() {
    cout << "Setting up the system...\n";
    cout << "System setup complete.\n";
}

// Function to create a new customer
void createCustomer(vector<Customer>& customers) {
    Customer customer;
    cout << "Enter customer name: ";
    cin>> customer.name;
    cout << "Enter account number: ";
    cin >> customer.accountNumber;
    cout << "Customer created successfully.\n";
}

// Function to create a new account
void createAccount(vector<Customer>& customers) {
    int accountNumber;
    string accountType;
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter account type (Savings/Current): ";
    cin >> accountType;
    cout << "Account created successfully.\n";
}

// Function to handle transactions
void transaction(vector<Customer>& customers) {
    int accountNumber;
    float amount;
    cout << "Enter account number: ";
    cin >> accountNumber;
    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Enter amount to deposit/withdraw: ";
        cin >> amount;
        if (amount > 0) {
            accounts[accountNumber].balance += amount;
            cout << "Deposit successful. New balance: " << accounts[accountNumber].balance << endl;
        } else {
            if (accounts[accountNumber].balance >= -amount) {
                accounts[accountNumber].balance += amount;
                cout << "Withdrawal successful. New balance: " << accounts[accountNumber].balance << endl;
            } else {
                cout << "Insufficient balance.\n";
            }
        }
    } else {
        cout << "Account not found.\n";
    }
}

// Function to display user interface
void displayUI() {
    cout << "Bank Management System\n";
    cout << "1. Create Customer\n";
    cout << "2. Create Account\n";
    cout << "3. Transaction\n";
    cout << "4. Display Accounts\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function to display accounts
void displayAccounts() {
    cout << "Accounts:\n";
    for (auto& account : accounts) {
        cout << "Account Number: " << account.first << endl;
        cout << "Account Type: " << account.second.accountType << endl;
        cout << "Balance: " << account.second.balance << endl;
        cout << endl;
    }
}

// Function to test and debug the system
void testAndDebug() {
    // Test cases go here
    // Example:
    // createCustomer(customers);
    // createAccount(customers);
    // transaction(customers);
    // displayAccounts();
}

int main() {
    vector<Customer> customers;

    setupSystem();

    while (true) {
        displayUI();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                createCustomer(customers);
                break;
            case 2:
                createAccount(customers);
                break;
            case 3:
                transaction(customers);
                break;
            case 4:
                displayAccounts();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
