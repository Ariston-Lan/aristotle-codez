#include <iostream>
#include <string>
#include <optional>
#include "bank.h"

std::string checkingName {"Checking"};
std::string savingsName {"Savings"};

double checkingBalance {500.0};
double savingsBalance {1000.0};

double* activeBalance{nullptr};

double& getBalance(int choice, double& checking, double& savings)
{
    if(choice==1){
        return checking;
    }
    else{
        return savings;
    }
}

const std::string& getAccountName(int choice, std::string& checkingName, std::string& savingsName)
{
    if(choice==1){
        return checkingName;
    }
    else{
        return savingsName;
    }
}

double* getBalancePtr(int choice, double& checking, double& savings)
{
    if(choice==1){
    }
    else if(choice==2){
        return &savings;
    }
    else{
        return nullptr;
    }
}

void setActiveAccount(double*& active, double* selected){
    active = selected;
}


void printAccountName(const std::string& balance){
    std::cout << balance << '\n';
}

void printBalance(const double* balance){
    if(balance){
        std::cout << *balance << '\n';
    }
    else{
        std::cout << "No Active Account Currently\n";
    }
}

void deposit(double& balance, double amount){
    if(amount>0){
        balance += amount;
    }
    else{
        std::cout << "Must deposit a positive number greater than 0\n";
    }
}

std::optional<double> withdraw(double& balance, double amount){
    if(amount<=balance && amount>0){
        balance -= amount;
        return balance;
    }
    else{
        return std::nullopt;
    }
}

bool transfer(double& from, double& to, double amount){
    if(amount>0){
        if(withdraw(from, amount)){
            deposit(to, amount);
        }

        return true;
    }
    else{
        return false;
    }
}

