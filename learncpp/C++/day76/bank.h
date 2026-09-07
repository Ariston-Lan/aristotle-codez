#pragma once

#include <iostream>
#include <string>
#include <optional>

std::string checkingName {"Checking"};
std::string savingsName {"Savings"};

double checkingBalance {500.0};
double savingsBalance {1000.0};

double* activeBalance{nullptr};

double& getBalance(int choice, double& checking, double& savings);

const std::string& getAccountName(int choice, std::string& checkingName, std::string& savingsName);

double* getBalancePtr(int choice, double& checking, double& savings);

void setActiveAccount(double*& active, double* selected);

void printAccountName(const std::string& balance);

void printBalance(const double& balance);

void deposit(double& balance, double amount);

std::optional<double> withdraw(double& balance, double amount);

bool transfer(double& from, double& to, double amount);