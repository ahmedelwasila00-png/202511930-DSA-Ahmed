#include <iostream>
#include <string>
using namespace std;

// Constants
const int MAX_TRANSACTIONS = 100;
const int DEFAULT_PIN = 12345;
const int MAX_ATTEMPTS = 3;

// Function prototypes
void checkBalance(double balance);
void deposit(double &balance, string transactions[], int &transCount);
void withdraw(double &balance, string transactions[], int &transCount);
void showHistory(string transactions[], int transCount);

int main() {
    int pin;
    int attempts = 0;
    bool loggedIn = false;
    
    // User data
    double balance = 5000.00;
    string transactionHistory[MAX_TRANSACTIONS];
    int transactionCount = 0;
    
    // Welcome message
    cout << "\t\t===========" << endl;
    cout << "\t\t BK ATM SYSTEM" << endl;
    cout << "\t\t===========" << endl;
    
    // PIN Authentication Loop
    do {
        cout << "\n\tEnter your PIN: ";
        cin >> pin;
        attempts++;
        
        if (pin == DEFAULT_PIN) {
            loggedIn = true;
            cout << "\n\tLogin Successful!" << endl;
            cout << "\tWelcome to BK ATM" << endl;
        } else {
            cout << "\tWrong PIN! Attempts left: " << (MAX_ATTEMPTS - attempts) << endl;
        }
        
        if (attempts >= MAX_ATTEMPTS && !loggedIn) {
            cout << "\n\tToo many failed attempts. Account locked." << endl;
            return 0;
        }
        
    } while (!loggedIn);
    
    // Main menu loop
    int choice;
    do {
        cout << "\n======== MAIN MENU ========" << endl;
        cout << " [1] Check Balance" << endl;
        cout << " [2] Deposit Money" << endl;
        cout << " [3] Withdraw Money" << endl;
        cout << " [4] Transaction History" << endl;
        cout << " [5] Exit" << endl;
        cout << "===========================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                deposit(balance, transactionHistory, transactionCount);
                break;
            case 3:
                withdraw(balance, transactionHistory, transactionCount);
                break;
            case 4:
                showHistory(transactionHistory, transactionCount);
                break;
            case 5:
                cout << "\n\tThank you for using BK ATM. Goodbye!" << endl;
                break;
            default:
                cout << "\n\tInvalid choice. Please try again." << endl;
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}

// Function to check balance
void checkBalance(double balance) {
    cout << "\n\tCurrent Balance: " << balance << " FRW" << endl;
}

// Function to deposit money
void deposit(double &balance, string transactions[], int &transCount) {
    double amount;
    cout << "\n\tEnter amount to deposit: ";
    cin >> amount;
    
    if (amount > 0) {
        balance = balance + amount;
        cout << "\n\tDeposit Successful!" << endl;
        cout << "\tNew Balance: " << balance << " FRW" << endl;
        
        if (transCount < MAX_TRANSACTIONS) {
            transactions[transCount] = "Deposited: " + to_string(amount) + " FRW";
            transCount = transCount + 1;
        }
    } else {
        cout << "\n\tInvalid amount!" << endl;
    }
}

// Function to withdraw money
void withdraw(double &balance, string transactions[], int &transCount) {
    double amount;
    cout << "\n\tEnter amount to withdraw: ";
    cin >> amount;
    
    if (amount <= 0) {
        cout << "\n\tInvalid amount!" << endl;
    } else if (amount > balance) {
        cout << "\n\tInsufficient Funds!" << endl;
    } else {
        balance = balance - amount;
        cout << "\n\tWithdrawal Successful!" << endl;
        cout << "\tWithdrawn: " << amount << " FRW" << endl;
        cout << "\tRemaining Balance: " << balance << " FRW" << endl;
        
        if (transCount < MAX_TRANSACTIONS) {
            transactions[transCount] = "Withdrew: " + to_string(amount) + " FRW";
            transCount = transCount + 1;
        }
    }
}

// Function to show transaction history
void showHistory(string transactions[], int transCount) {
    cout << "\n===== TRANSACTION HISTORY =====" << endl;
    
    if (transCount == 0) {
        cout << "\tNo transactions found." << endl;
    } else {
        for (int i = 0; i < transCount; i = i + 1) {
            cout << "\t" << (i + 1) << ". " << transactions[i] << endl;
        }
    }
    cout << "===============================" << endl;
}