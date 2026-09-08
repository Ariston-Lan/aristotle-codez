#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout << "Usage: ./addem.exe <name>\n";
        
        return 1;
    }

    std::size_t first_num{std::strlen(argv[1])};
    std::size_t second_num{(first_num+13)%7};

    std::cout << "Hello " << argv[1] << " what is " << first_num << " + " << second_num << '\n';
    
    std::size_t sum{first_num+second_num};
    int answer{};
    std::cin >> answer;

    if(answer==sum)
        std::cout << "Correct " << argv[1] << "!\n";
    else
        std::cout << "No " << argv[1] << ", it is " << sum << " .\n";
    
    return 0;

}