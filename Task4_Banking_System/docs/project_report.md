
````markdown
# Banking Management System
## CodeAlpha C++ Programming Internship – Task 4

---

## 1. Project Overview

The Banking Management System is a console-based C++ application developed as part of the CodeAlpha C++ Programming Internship.

The project simulates essential banking operations through a menu-driven interface. It allows users to create customers, create bank accounts, view account information, deposit money, withdraw money, transfer funds between accounts, and view transaction history.

The application is designed using Object-Oriented Programming concepts. Separate classes are used to represent customers, accounts, and transactions, making the program structured and easier to understand.

The project demonstrates how C++ can be used to model a practical real-world system using classes, objects, functions, vectors, conditional statements, loops, and input validation.

---

# 2. Internship Task

## Task Name

**Banking System**

## Internship

**CodeAlpha C++ Programming Internship**

## Programming Language

**C++**

## Project Type

**Console-Based Banking Management Application**

---

# 3. Problem Statement

Banking applications involve multiple operations such as customer management, account management, deposits, withdrawals, fund transfers, and transaction tracking.

The objective of this project is to develop a simplified banking system using C++ that can perform these basic operations through a structured console interface.

The system should be able to:

- Manage customer information.
- Create and manage bank accounts.
- Maintain account balances.
- Deposit money into an account.
- Withdraw money from an account.
- Transfer funds between accounts.
- Display account information.
- Maintain transaction records.
- Validate banking operations.
- Provide a simple menu-driven interface.

---

# 4. Project Objectives

The main objectives of the project are:

1. To develop a functional banking application using C++.
2. To apply Object-Oriented Programming principles.
3. To represent customers, accounts, and transactions using classes.
4. To implement common banking operations.
5. To maintain accurate account balances.
6. To record successful transactions.
7. To validate user inputs and banking operations.
8. To create a structured menu-driven application.
9. To understand how programming concepts can be applied to a real-world system.

---

# 5. System Features

The Banking Management System provides the following major features:

### 5.1 Customer Management

Users can create new customers by entering:

- Customer ID
- Customer name
- Phone number
- Email address

The program checks whether the Customer ID already exists before creating a new customer.

---

### 5.2 Account Creation

A bank account can be created for an existing customer.

The account contains:

- Account number
- Customer ID
- Account holder name
- Account type
- Initial balance

The system prevents duplicate account numbers and verifies that the customer exists.

---

### 5.3 Account Information

Users can search for an account using the account number.

The system displays:

- Account number
- Customer ID
- Account holder name
- Account type
- Current balance

---

### 5.4 Deposit Money

The deposit feature allows users to add money to an existing account.

The system:

1. Searches for the account.
2. Checks the deposit amount.
3. Updates the account balance.
4. Creates a transaction record.
5. Displays the updated balance.

---

### 5.5 Withdraw Money

The withdrawal feature allows users to remove money from an account.

Before completing the transaction, the system checks:

- Whether the account exists.
- Whether the withdrawal amount is valid.
- Whether sufficient balance is available.

If sufficient balance is available, the account balance is reduced and a transaction record is created.

---

### 5.6 Fund Transfer

The fund transfer feature allows money to be transferred from one account to another.

The system verifies:

- Sender account.
- Receiver account.
- Transfer amount.
- Available sender balance.
- Sender and receiver are different accounts.

After successful validation, the amount is deducted from the sender and added to the receiver.

---

### 5.7 Transaction History

The system records successful banking transactions.

Each transaction contains:

- Transaction ID
- Transaction type
- Account number
- Amount
- Description

Users can enter an account number to view its recorded transactions.

---

### 5.8 Display All Accounts

The system provides an option to display all accounts currently stored in the application.

This allows the user to view the complete account information available during the current program execution.

---

# 6. Object-Oriented Design

The project uses three major classes:

```text
                    BANKING SYSTEM
                          |
             +------------+------------+
             |            |            |
             v            v            v
         Customer      Account     Transaction
             |            |            |
             v            v            v
       Customer Data  Account Data  Transaction Data
````

---

# 7. Customer Class

The `Customer` class represents a customer of the banking system.

## Attributes

The class stores:

* Customer ID
* Name
* Phone number
* Email address

## Main Functions

### `getCustomerId()`

Returns the customer's unique ID.

### `getName()`

Returns the customer's name.

### `displayCustomer()`

Displays customer information.

## Purpose

The Customer class separates customer-related information from account and transaction data.

---

# 8. Account Class

The `Account` class represents an individual bank account.

## Attributes

The class contains:

* Account number
* Customer ID
* Account holder name
* Account type
* Balance

## Main Functions

### `getAccountNumber()`

Returns the account number.

### `getCustomerId()`

Returns the customer ID associated with the account.

### `getAccountHolderName()`

Returns the account holder's name.

### `getBalance()`

Returns the current account balance.

### `deposit()`

Adds a specified amount to the account balance.

### `withdraw()`

Removes a specified amount after checking whether the withdrawal is valid.

### `displayAccount()`

Displays the account information.

---

# 9. Transaction Class

The `Transaction` class represents a banking transaction.

## Attributes

The class contains:

* Transaction ID
* Transaction type
* Account number
* Transaction amount
* Description

## Main Functions

### `displayTransaction()`

Displays transaction details.

### `getAccountNumber()`

Returns the account number associated with the transaction.

## Purpose

The Transaction class provides a structured way to maintain records of deposits, withdrawals, and transfers.

---

# 10. Data Management

The program uses C++ vectors to store multiple customers, accounts, and transactions.

The main function contains:

```cpp
vector<Customer> customers;
vector<Account> accounts;
vector<Transaction> transactions;
```

These collections allow the program to store multiple objects during program execution.

The C++ `vector` container is designed as a dynamically sized sequence container, making it suitable for maintaining a collection whose number of elements can grow during execution.

---

# 11. Helper Functions

The program uses helper functions to search for customers and accounts.

## `findCustomerIndex()`

This function searches the customer vector using the Customer ID.

If the customer exists, its index is returned.

If the customer does not exist, the function returns:

```text
-1
```

---

## `findAccountIndex()`

This function searches the account vector using the Account Number.

If the account exists, its index is returned.

If the account does not exist, the function returns:

```text
-1
```

These functions reduce repeated searching logic throughout the program.

---

# 12. Customer Creation Workflow

The customer creation process follows these steps:

```text
Start
  |
Enter Customer ID
  |
Check Duplicate ID
  |
Enter Customer Details
  |
Create Customer Object
  |
Store Customer
  |
Display Success Message
```

If the entered Customer ID already exists, the system stops the operation and displays an error message.

---

# 13. Account Creation Workflow

The account creation process follows:

```text
Enter Account Number
          |
Check Duplicate Account
          |
Enter Customer ID
          |
Check Customer Exists
          |
Enter Account Type
          |
Enter Initial Balance
          |
Validate Balance
          |
Create Account
          |
Display Success Message
```

An account cannot be created for a customer who does not exist.

---

# 14. Deposit Algorithm

The deposit operation follows this algorithm:

```text
1. Ask for account number.
2. Search for the account.
3. If the account does not exist, display an error.
4. Ask for deposit amount.
5. Check whether amount is greater than zero.
6. Add amount to account balance.
7. Create a transaction record.
8. Display updated balance.
```

The balance is updated using:

```text
New Balance = Current Balance + Deposit Amount
```

---

# 15. Withdrawal Algorithm

The withdrawal operation follows:

```text
1. Ask for account number.
2. Search for the account.
3. If the account does not exist, display an error.
4. Ask for withdrawal amount.
5. Check whether amount is greater than zero.
6. Check whether sufficient balance is available.
7. Deduct the amount.
8. Create a transaction record.
9. Display remaining balance.
```

The balance is updated using:

```text
New Balance = Current Balance - Withdrawal Amount
```

---

# 16. Fund Transfer Algorithm

The fund transfer operation follows:

```text
1. Enter sender account number.
2. Enter receiver account number.
3. Check that the accounts are different.
4. Search for both accounts.
5. Enter transfer amount.
6. Validate the amount.
7. Check sender balance.
8. Deduct amount from sender.
9. Add amount to receiver.
10. Record the transfer.
11. Display transfer details.
```

The balance changes are:

```text
Sender Balance
= Sender Balance - Transfer Amount
```

```text
Receiver Balance
= Receiver Balance + Transfer Amount
```

---

# 17. Transaction Recording

After successful deposit, withdrawal, or transfer operations, a `Transaction` object is created and stored in the transaction vector.

For example:

```text
Transaction ID : 1001
Type           : Deposit
Account        : 1001
Amount         : Rs. 5000
Description    : Cash deposited
```

For a transfer, records are created for both the sending and receiving account so that the transaction history can be viewed for either account.

---

# 18. Input Validation

Validation is an important part of the system.

## Customer Validation

The system checks whether the Customer ID already exists.

```text
If Customer ID exists
        |
        v
Display "Customer ID already exists"
```

---

## Account Validation

The system checks:

* Account number uniqueness.
* Customer existence.
* Initial balance validity.

---

## Deposit Validation

The deposit amount must be greater than zero.

```text
Amount > 0
```

If the amount is zero or negative, the transaction is rejected.

---

## Withdrawal Validation

The withdrawal amount must:

```text
Amount > 0
```

and

```text
Amount <= Current Balance
```

---

## Transfer Validation

A valid transfer requires:

```text
Sender exists
        AND
Receiver exists
        AND
Sender != Receiver
        AND
Amount > 0
        AND
Amount <= Sender Balance
```

---

# 19. Main Menu

The program uses a menu-driven interface:

```text
=============================================
         BANKING MANAGEMENT SYSTEM
=============================================
1. Create Customer
2. Create Account
3. Display Account Information
4. Deposit Money
5. Withdraw Money
6. Transfer Funds
7. View Transaction History
8. Display All Accounts
9. Exit
=============================================
Enter your choice:
```

The user selects an operation by entering the corresponding menu number.

The `switch` statement then calls the appropriate function.

---

# 20. Complete System Workflow

The overall system workflow is:

```text
                    START
                      |
                      v
                Display Menu
                      |
                      v
               Select Operation
                      |
        +-------------+-------------+
        |             |             |
        v             v             v
    Customer       Account      Transaction
    Management    Management    Operations
        |             |             |
        +-------------+-------------+
                      |
                      v
               Validate Input
                      |
                      v
                Perform Action
                      |
                      v
              Update Account Data
                      |
                      v
             Record Transaction
                      |
                      v
              Display Result
                      |
                      v
                Return to Menu
                      |
                      v
                   Exit
```

---

# 21. Sample Data

The program contains two sample customers.

## Customer 1

```text
Customer ID : 101
Name        : Rahul Sharma
Phone       : 9876543210
Email       : rahul@gmail.com
```

Associated account:

```text
Account Number : 1001
Account Type   : Savings
Initial Balance: Rs. 10000
```

## Customer 2

```text
Customer ID : 102
Name        : Priya Patil
Phone       : 9876501234
Email       : priya@gmail.com
```

Associated account:

```text
Account Number : 1002
Account Type   : Savings
Initial Balance: Rs. 15000
```

These accounts are included to demonstrate banking operations immediately when the program starts.

---

# 22. Sample Deposit Operation

Example:

```text
========== DEPOSIT MONEY ==========

Enter Account Number: 1001
Enter Deposit Amount: Rs. 5000

Deposit successful!
Amount Deposited : Rs. 5000.00
New Balance      : Rs. 15000.00
```

The original balance was:

```text
Rs. 10000
```

After depositing:

```text
Rs. 10000 + Rs. 5000 = Rs. 15000
```

---

# 23. Sample Withdrawal Operation

Example:

```text
========== WITHDRAW MONEY ==========

Enter Account Number: 1001
Enter Withdrawal Amount: Rs. 2000

Withdrawal successful!
Amount Withdrawn : Rs. 2000.00
Remaining Balance: Rs. 13000.00
```

The balance is reduced after successful withdrawal.

---

# 24. Sample Fund Transfer

Example:

```text
========== FUND TRANSFER ==========

Enter Sender Account Number: 1001
Enter Receiver Account Number: 1002
Enter Transfer Amount: Rs. 3000

Fund transfer successful!

Amount Transferred : Rs. 3000.00
From Account       : 1001
To Account         : 1002
Sender New Balance : Rs. 10000.00
```

The sender's account is reduced by the transfer amount and the receiver's account is increased by the same amount.

---

# 25. Sample Transaction History

Example:

```text
========== TRANSACTION HISTORY ==========

Enter Account Number: 1001

ID        TYPE           ACCOUNT        AMOUNT         DESCRIPTION
---------------------------------------------------------------------------
1001      Deposit        1001           5000.00        Cash deposited
1002      Withdrawal     1001           2000.00        Cash withdrawn
1003      Transfer       1001           3000.00        Amount transferred
```

The transaction history provides a record of successful operations associated with the selected account.

---

# 26. Error Handling

The program provides messages for invalid operations.

Examples include:

```text
Customer ID already exists!
```

```text
Account Number already exists!
```

```text
Customer not found!
```

```text
Account not found!
```

```text
Invalid deposit amount!
```

```text
Invalid withdrawal amount!
```

```text
Insufficient balance!
```

```text
Sender and receiver accounts cannot be the same!
```

```text
Invalid transfer amount!
```

These checks prevent invalid banking operations from being processed.

---

# 27. Technologies Used

## Programming Language

C++

## Standard Libraries

```cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
```

The program uses standard C++ input/output facilities, formatting utilities, strings, vectors, and input-related limits.

## Programming Concepts

* Classes
* Objects
* Encapsulation
* Constructors
* Member functions
* Vectors
* Functions
* Loops
* Conditional statements
* Switch-case
* Searching
* Input validation
* Menu-driven programming

---

# 28. Project Structure

```text
Task4_Banking_System/
│
├── README.md
│
├── src/
│   └── main.cpp
│
├── screenshots/
│   ├── dashboard.png
│   ├── account_creation.png
│   ├── deposit_withdrawal.png
│   ├── fund_transfer.png
│   └── transaction_history.png
│
└── docs/
    └── project_report.md
```

---

# 29. Compilation and Execution

The project can be compiled using a C++ compiler such as g++.

Navigate to the Task 4 directory:

```bash
cd Task4_Banking_System
```

Compile:

```bash
g++ src/main.cpp -o BankingSystem
```

On Windows:

```bash
BankingSystem.exe
```

On Linux/macOS:

```bash
./BankingSystem
```

---

# 30. Testing

The application should be tested using different normal and invalid scenarios.

| Test Case       | Input/Condition             | Expected Result           |
| --------------- | --------------------------- | ------------------------- |
| Create customer | New Customer ID             | Customer created          |
| Create customer | Existing Customer ID        | Creation rejected         |
| Create account  | Valid customer              | Account created           |
| Create account  | Invalid customer            | Account creation rejected |
| Create account  | Duplicate account number    | Creation rejected         |
| Deposit         | Positive amount             | Balance increases         |
| Deposit         | Zero amount                 | Transaction rejected      |
| Deposit         | Negative amount             | Transaction rejected      |
| Withdrawal      | Valid amount                | Balance decreases         |
| Withdrawal      | Amount greater than balance | Transaction rejected      |
| Transfer        | Valid sender and receiver   | Transfer successful       |
| Transfer        | Invalid sender              | Transfer rejected         |
| Transfer        | Invalid receiver            | Transfer rejected         |
| Transfer        | Same sender and receiver    | Transfer rejected         |
| Transfer        | Insufficient balance        | Transfer rejected         |
| History         | Existing account            | Transactions displayed    |
| History         | No transactions             | No transactions message   |
| Account Search  | Existing account            | Account details displayed |
| Account Search  | Invalid account             | Account not found         |

---

# 31. Advantages of the System

The project provides several benefits as a learning-oriented banking simulation:

* Simple console-based interface.
* Clear separation of customer, account, and transaction data.
* Demonstrates Object-Oriented Programming.
* Supports multiple customers and accounts.
* Maintains account balances during execution.
* Records successful transactions.
* Includes validation for common invalid operations.
* Uses reusable functions for repeated operations.
* Provides a practical application of C++ concepts.

---

# 32. Limitations

The current version is designed as an internship-level console application and therefore has some limitations.

### No Permanent Storage

Data is stored in memory using vectors. When the program terminates, the data created during that execution is not permanently saved.

### No Authentication

The current version does not implement login, passwords, or PIN-based authentication.

### Console Interface

The system uses a text-based interface rather than a graphical user interface.

### No Database

The application does not currently use a database for storing customer, account, or transaction information.

### No Real Banking Integration

This project is a programming simulation and does not connect to real banking systems or financial services.

---

# 33. Future Scope

The project can be expanded with:

## Database Integration

Customer, account, and transaction information could be stored in a database.

## File-Based Storage

Data could be saved and loaded using files so that information persists between program executions.

## Authentication

A login system could be added with username, password, or PIN authentication.

## Graphical User Interface

The console interface could be replaced with a graphical interface.

## ATM Simulation

ATM-related operations could be incorporated into the application.

## Interest Calculation

Savings account interest calculation could be implemented.

## Loan Management

Features for loan applications, repayments, and loan status could be added.

## Account Statements

The system could generate detailed account statements based on transaction history.

---

# 34. Learning Outcomes

This project provides practical experience with:

* C++ programming.
* Object-Oriented Programming.
* Class design.
* Encapsulation.
* Constructors.
* Member functions.
* Vectors.
* Searching through collections.
* Menu-driven programming.
* Input validation.
* Financial transaction logic.
* Program structure and modular functions.
* Testing and error handling.

The project also demonstrates how programming concepts can be combined to create a practical application.

---

# 35. Conclusion

The Banking Management System successfully demonstrates the implementation of a simplified banking application using C++.

The project provides functionality for customer management, account creation, deposits, withdrawals, fund transfers, account information, and transaction history.

The use of separate Customer, Account, and Transaction classes provides a structured approach to representing the different entities involved in the banking system.

Through this project, important C++ and Object-Oriented Programming concepts are applied to a practical problem while also demonstrating input validation, transaction processing, and account balance management.

---

# 36. Author

**Preeti Choure**

**CodeAlpha C++ Programming Internship**

**Task 4 – Banking System**

---

# 37. Acknowledgement

This project was developed as part of the CodeAlpha C++ Programming Internship.

The project provided an opportunity to apply C++ programming and Object-Oriented Programming concepts to a practical Banking Management System.

````



[1]: https://en.cppreference.com/cpp/standard_library?utm_source=chatgpt.com "C++ Standard Library - cppreference.com"

