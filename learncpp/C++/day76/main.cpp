#include "bank.h"

void addOne(int* ptr){
    ++*ptr; 
    std::cout << *ptr << "\n";
}

auto& getRef(){
    static int x{5};
    return x;
}

int main(){
    /*int x{0};
    addOne(&x);
    addOne(&x);
    addOne(&x);

    auto& ref{getRef()};
    auto not_ref{getRef()};
    std::cout << not_ref << " THIS IS NOT A REFERENCE, BUT INITIALIZED WITH getREF()\n";
    addOne(&ref);
    addOne(&ref);
    std::cout << not_ref << " THIS IS NOT A REFERENCE, BUT INITIALIZED WITH getREF()\n";
    */


    bool running{true};
    while(running==true){
        std::cout << "=== PocketBank ===";

        std::cout << "1. View account\n";
        std::cout << "2. Set active account\n";
        std::cout << "3. Deposit to active account\n";
        std::cout << "4. Withdraw from active account\n";
        std::cout << "5. Transfer from active account\n";
        std::cout << "6. View active balance\n";
        std::cout << "7. Exit\n\n";

        int choice{};
        std::cin >> choice;
        if(choice==1){
            std::cout << "Choose balance (Checking = 1, Savings = 2)\n";
            printAccountName(getAccountName(choice, checkingName, savingsName));
            printBalance(getBalance(choice, checkingBalance, savingsBalance));
        }
        else{
            running=false;
        }

    }

}
