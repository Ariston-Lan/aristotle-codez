#include <string>
#include <iostream>

int main(){
  std::string phrase;
  std::cout << "Enter the phrase you want to turn into whale speech\n";
  std::getline(std::cin, phrase);
  std::string whale;
  for (int i = 0; i < phrase.size(); i++){
    if (std::tolower(phrase[i]) == 'a' || std::tolower(phrase[i]) == 'i' || std::tolower(phrase[i]) == 'o' ){
      whale += std::tolower(phrase[i]);
    }

    else if (std::tolower(phrase[i]) == 'e' || std::tolower(phrase[i]) == 'u'){
      whale += std::tolower(phrase[i]);
      whale += std::tolower(phrase[i]);
    }
  }
  std::cout << whale;
}