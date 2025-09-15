#include <iostream>

template <typename T>
void printValue(const T& value){
    std::cout << value << "\n";
}

template<>
void printValue<bool>(const bool& value){
    if(value) {std::cout << "true\n";}
    else {std::cout << "false\n";}
}

template<>
void printValue<char*>(char* const &value){
    std::cout << "\"" << value << "\"\n";
}

int main(){
    printValue(12);
    printValue(1.5);
    printValue(true);
    printValue(false);
    printValue("RAU");
}