#include <iostream>
#include <cstring>

template <typename T>
bool isEqual(const T& a, const T& b){
    return a == b;
}

template<>
bool isEqual<const char*>(const char* const &a, const char* const &b){
    return std::strcmp(a,b) == 0;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << isEqual(5,5) << "\n";
    std::cout << isEqual(5,8) << "\n";
    std::cout << isEqual(1.25,2.3) << "\n";
    std::cout << isEqual(2.5,2.5) << "\n";
    std::cout << isEqual("cup","pen") << "\n";
    std::cout << isEqual("cup","cup") << "\n";
}