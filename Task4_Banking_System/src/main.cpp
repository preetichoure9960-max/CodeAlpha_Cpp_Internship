#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// ============================================================
// CUSTOMER CLASS
// ============================================================

class Customer {
private:
    int customerId;
    string name;
    string phone;
    string email;

public:
    Customer(int id, string n, string p, string e)
        : customerId(id), name(n), phone(p), email(e) {}

    int getCustomerId() const {
        return customerId;
    }

    string getName() const {
        return name;
    }

    void displayCustomer() const {
        cout << "\n---------- CUSTOMER INFORMATION ----------\n";
        cout << "Customer ID : " << customerId << endl;
        cout << "Name        : " << name << endl;
        cout << "Phone       : " << phone << endl;
        cout << "Email       : " << email << endl;
    }
};

// ============================================================
// TRANSACTION CLASS
// ============================================================

class Transaction {
private:
    int transactionId;
    string type;
    int accountNumber;
    double amount;
    string description;

public:
    Transaction(int id, string t, int acc, double amt, string desc)
        : transactionId(id),
          type(t),
          accountNumber(acc),
          amount(amt),
          description(desc) {}

    void displayTransaction() const {
        cout << left
             << setw(10) << transactionId
             << setw(15) << type
             << setw(15) << accountNumber
             << setw(15) << fixed << setprecision(2) << amount
             << description << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

// ============================================================
// ACCOUNT CLASS
// ============================================================

class Account {
private:
    int accountNumber;
    int customerId;
    string accountHolderName;
    string accountType;
    double balance;

public:
    Account(int accNo, int custId, string name, string type, double initialBalance)
        : accountNumber(accNo),
          customerId(custId),
          accountHolderName(name),
          accountType(type),
          balance(initialBalance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    int getCustomerId() const {
        return customerId;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }

        balance -= amount;
        return true;
    }

    void displayAccount() const {
        cout << "\n========== ACCOUNT INFORMATION ==========\n";
        cout << "Account Number      : " << accountNumber << endl;
        cout << "Customer ID         : " << customerId << endl;
        cout << "Account Holder      : " << accountHolderName << endl;
        cout << "Account Type        : " << accountType << endl;
        cout << "Current Balance     : Rs. "
             << fixed << setprecision(2) << balance << endl;
        cout << "=========================================\n";
    }
};

// ============================================================
// HELPER FUNCTIONS
// ============================================================

// Find customer using Customer ID
int findCustomerIndex(const vector<Customer>& customers, int customerId) {

    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getCustomerId() == customerId) {
            return i;
        }
    }

    return -1;
}

// Find account using Account Number
int findAccountIndex(const vector<Account>& accounts, int accountNumber) {

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }

    return -1;
}

// ============================================================
// CREATE CUSTOMER
// ============================================================

void createCustomer(vector<Customer>& customers) {

    int customerId;
    string name;
    string phone;
    string email;

    cout << "\n========== CREATE CUSTOMER ==========\n";

    cout << "Enter Customer ID: ";
    cin >> customerId;

    // Check duplicate customer ID
    if (findCustomerIndex(customers, customerId) != -1) {
        cout << "\nCustomer ID already exists!\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Enter Email: ";
    getline(cin, email);

    customers.push_back(
        Customer(customerId, name, phone, email)
    );

    cout << "\nCustomer created successfully!\n";
}

// ============================================================
// CREATE ACCOUNT
// ============================================================

void createAccount(
    vector<Customer>& customers,
    vector<Account>& accounts
) {

    int accountNumber;
    int customerId;
    string accountType;
    double initialBalance;

    cout << "\n========== CREATE ACCOUNT ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    // Check duplicate account number
    if (findAccountIndex(accounts, accountNumber) != -1) {
        cout << "\nAccount Number already exists!\n";
        return;
    }

    cout << "Enter Customer ID: ";
    cin >> customerId;

    int customerIndex = findCustomerIndex(customers, customerId);

    if (customerIndex == -1) {
        cout << "\nCustomer not found!\n";
        cout << "Please create the customer first.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Account Type: ";
    getline(cin, accountType);

    cout << "Enter Initial Balance: Rs. ";
    cin >> initialBalance;

    if (initialBalance < 0) {
        cout << "\nInitial balance cannot be negative!\n";
        return;
    }

    accounts.push_back(
        Account(
            accountNumber,
            customerId,
            customers[customerIndex].getName(),
            accountType,
            initialBalance
        )
    );

    cout << "\nAccount created successfully!\n";
}

// ============================================================
// DISPLAY ACCOUNT INFORMATION
// ============================================================

void displayAccountInformation(
    const vector<Account>& accounts
) {

    int accountNumber;

    cout << "\n========== ACCOUNT SEARCH ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    int index = findAccountIndex(accounts, accountNumber);

    if (index == -1) {
        cout << "\nAccount not found!\n";
        return;
    }

    accounts[index].displayAccount();
}

// ============================================================
// DEPOSIT MONEY
// ============================================================

void depositMoney(
    vector<Account>& accounts,
    vector<Transaction>& transactions,
    int& transactionCounter
) {

    int accountNumber;
    double amount;

    cout << "\n========== DEPOSIT MONEY ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    int accountIndex = findAccountIndex(accounts, accountNumber);

    if (accountIndex == -1) {
        cout << "\nAccount not found!\n";
        return;
    }

    cout << "Enter Deposit Amount: Rs. ";
    cin >> amount;

    if (amount <= 0) {
        cout << "\nInvalid deposit amount!\n";
        return;
    }

    accounts[accountIndex].deposit(amount);

    transactions.push_back(
        Transaction(
            transactionCounter++,
            "Deposit",
            accountNumber,
            amount,
            "Cash deposited"
        )
    );

    cout << "\nDeposit successful!\n";
    cout << "Amount Deposited : Rs. "
         << fixed << setprecision(2) << amount << endl;

    cout << "New Balance      : Rs. "
         << accounts[accountIndex].getBalance() << endl;
}

// ============================================================
// WITHDRAW MONEY
// ============================================================

void withdrawMoney(
    vector<Account>& accounts,
    vector<Transaction>& transactions,
    int& transactionCounter
) {

    int accountNumber;
    double amount;

    cout << "\n========== WITHDRAW MONEY ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    int accountIndex = findAccountIndex(accounts, accountNumber);

    if (accountIndex == -1) {
        cout << "\nAccount not found!\n";
        return;
    }

    cout << "Enter Withdrawal Amount: Rs. ";
    cin >> amount;

    if (amount <= 0) {
        cout << "\nInvalid withdrawal amount!\n";
        return;
    }

    if (!accounts[accountIndex].withdraw(amount)) {
        cout << "\nInsufficient balance!\n";
        cout << "Transaction cancelled.\n";
        return;
    }

    transactions.push_back(
        Transaction(
            transactionCounter++,
            "Withdrawal",
            accountNumber,
            amount,
            "Cash withdrawn"
        )
    );

    cout << "\nWithdrawal successful!\n";

    cout << "Amount Withdrawn : Rs. "
         << fixed << setprecision(2) << amount << endl;

    cout << "Remaining Balance: Rs. "
         << accounts[accountIndex].getBalance() << endl;
}

// ============================================================
// TRANSFER FUNDS
// ============================================================

void transferFunds(
    vector<Account>& accounts,
    vector<Transaction>& transactions,
    int& transactionCounter
) {

    int senderAccount;
    int receiverAccount;
    double amount;

    cout << "\n========== FUND TRANSFER ==========\n";

    cout << "Enter Sender Account Number: ";
    cin >> senderAccount;

    cout << "Enter Receiver Account Number: ";
    cin >> receiverAccount;

    if (senderAccount == receiverAccount) {
        cout << "\nSender and receiver accounts cannot be the same!\n";
        return;
    }

    int senderIndex = findAccountIndex(accounts, senderAccount);
    int receiverIndex = findAccountIndex(accounts, receiverAccount);

    if (senderIndex == -1) {
        cout << "\nSender account not found!\n";
        return;
    }

    if (receiverIndex == -1) {
        cout << "\nReceiver account not found!\n";
        return;
    }

    cout << "Enter Transfer Amount: Rs. ";
    cin >> amount;

    if (amount <= 0) {
        cout << "\nInvalid transfer amount!\n";
        return;
    }

    if (accounts[senderIndex].getBalance() < amount) {
        cout << "\nInsufficient balance in sender account!\n";
        cout << "Transaction cancelled.\n";
        return;
    }

    accounts[senderIndex].withdraw(amount);
    accounts[receiverIndex].deposit(amount);

    transactions.push_back(
        Transaction(
            transactionCounter++,
            "Transfer",
            senderAccount,
            amount,
            "Amount transferred to receiver"
        )
    );

    transactions.push_back(
        Transaction(
            transactionCounter++,
            "Transfer",
            receiverAccount,
            amount,
            "Amount received from sender"
        )
    );

    cout << "\nFund transfer successful!\n";

    cout << "Amount Transferred : Rs. "
         << fixed << setprecision(2) << amount << endl;

    cout << "From Account       : "
         << senderAccount << endl;

    cout << "To Account         : "
         << receiverAccount << endl;

    cout << "Sender New Balance : Rs. "
         << accounts[senderIndex].getBalance() << endl;
}

// ============================================================
// DISPLAY TRANSACTION HISTORY
// ============================================================

void displayTransactionHistory(
    const vector<Transaction>& transactions
) {

    int accountNumber;

    cout << "\n========== TRANSACTION HISTORY ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    bool found = false;

    cout << "\n";
    cout << left
         << setw(10) << "ID"
         << setw(15) << "TYPE"
         << setw(15) << "ACCOUNT"
         << setw(15) << "AMOUNT"
         << "DESCRIPTION" << endl;

    cout << string(75, '-') << endl;

    for (const Transaction& transaction : transactions) {

        if (transaction.getAccountNumber() == accountNumber) {

            transaction.displayTransaction();

            found = true;
        }
    }

    if (!found) {
        cout << "No transactions found for this account.\n";
    }
}

// ============================================================
// DISPLAY ALL ACCOUNTS
// ============================================================

void displayAllAccounts(
    const vector<Account>& accounts
) {

    cout << "\n========== ALL ACCOUNTS ==========\n";

    if (accounts.empty()) {
        cout << "No accounts available.\n";
        return;
    }

    for (const Account& account : accounts) {
        account.displayAccount();
    }
}

// ============================================================
// MAIN FUNCTION
// ============================================================

int main() {

    vector<Customer> customers;
    vector<Account> accounts;
    vector<Transaction> transactions;

    int transactionCounter = 1001;
    int choice;

    // --------------------------------------------------------
    // Sample customer data
    // --------------------------------------------------------

    customers.push_back(
        Customer(
            101,
            "Rahul Sharma",
            "9876543210",
            "rahul@gmail.com"
        )
    );

    customers.push_back(
        Customer(
            102,
            "Priya Patil",
            "9876501234",
            "priya@gmail.com"
        )
    );

    // --------------------------------------------------------
    // Sample account data
    // --------------------------------------------------------

    accounts.push_back(
        Account(
            1001,
            101,
            "Rahul Sharma",
            "Savings",
            10000
        )
    );

    accounts.push_back(
        Account(
            1002,
            102,
            "Priya Patil",
            "Savings",
            15000
        )
    );

    // --------------------------------------------------------
    // Main Menu
    // --------------------------------------------------------

    do {

        cout << "\n";
        cout << "=============================================\n";
        cout << "         BANKING MANAGEMENT SYSTEM           \n";
        cout << "=============================================\n";

        cout << "1. Create Customer\n";
        cout << "2. Create Account\n";
        cout << "3. Display Account Information\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Transfer Funds\n";
        cout << "7. View Transaction History\n";
        cout << "8. Display All Accounts\n";
        cout << "9. Exit\n";

        cout << "=============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                createCustomer(customers);
                break;

            case 2:
                createAccount(customers, accounts);
                break;

            case 3:
                displayAccountInformation(accounts);
                break;

            case 4:
                depositMoney(
                    accounts,
                    transactions,
                    transactionCounter
                );
                break;

            case 5:
                withdrawMoney(
                    accounts,
                    transactions,
                    transactionCounter
                );
                break;

            case 6:
                transferFunds(
                    accounts,
                    transactions,
                    transactionCounter
                );
                break;

            case 7:
                displayTransactionHistory(transactions);
                break;

            case 8:
                displayAllAccounts(accounts);
                break;

            case 9:
                cout << "\nThank you for using the Banking Management System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
