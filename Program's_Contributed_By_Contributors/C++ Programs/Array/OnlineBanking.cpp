#include <iostream>
#include <map>

class Bank {
private:
    std::map<int, double> accounts; // Map account numbers to balances
    int nextAccountNumber;

public:
    Bank() : nextAccountNumber(1) {}

    int createAccount() {
        accounts[nextAccountNumber] = 0.0;
        return nextAccountNumber++;
    }

    void deposit(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber] += amount;
            std::cout << "Deposited $" << amount << " into account " << accountNumber << std::endl;
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }

    void withdraw(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            if (accounts[accountNumber] >= amount) {
                accounts[accountNumber] -= amount;
                std::cout << "Withdrew $" << amount << " from account " << accountNumber << std::endl;
            } else {
                std::cout << "Insufficient balance." << std::endl;
            }
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }

    void checkBalance(int accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            std::cout << "Account " << accountNumber << " has a balance of $" << accounts[accountNumber] << std::endl;
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }
};

int main() {
    Bank bank;
    int choice, accountNumber;
    double amount;

    while (true) {
        std::cout << "Banking System Menu:" << std::endl;
        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Check Balance" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                accountNumber = bank.createAccount();
                std::cout << "Account created with number " << accountNumber << std::endl;
                break;
            case 2:
                std::cout << "Enter account number and amount to deposit: ";
                std::cin >> accountNumber >> amount;
                bank.deposit(accountNumber, amount);
                break;
            case 3:
                std::cout << "Enter account number and amount to withdraw: ";
                std::cin >> accountNumber >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            case 4:
                std::cout << "Enter account number to check balance: ";
                std::cin >> accountNumber;
                bank.checkBalance(accountNumber);
                break;
            case 5:
                std::cout << "Exiting the banking system. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
