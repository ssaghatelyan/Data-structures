#include <iostream>
#include <vector>

template <typename T>
void resizeVector(std::vector<T>& vec, int newSize, const T& defaultValue){
    std::cout << "Before: \n";
    for(const auto& x : vec){
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    vec.resize(newSize, defaultValue);
    std::cout << "After: \n";
    for(const auto& x : vec){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main(){
    std::vector<int> vec = {1, 2, 3};
    resizeVector(vec, 5, 42);
}