#include <iostream>
#include <vector>
#include <string>

template <typename T>
int linearSearch(const std::vector<T>& vec, const T& value) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> v1 = {1, 2, 3, 1, 2, 3};
    std::cout << "index: " << linearSearch(v1, 2) << "\n";
    
    std::vector<double> v2 = {1.1, 2.4, 3.8, 5.1, 9.2, 3.0};
    std::cout << "index: " << linearSearch(v2, 5.1) << "\n";
    
    std::vector<std::string> v3 = {"practice", "problems", "homework", "template"};
    std::cout << "index: " << linearSearch(v3, (std::string)"homework") << "\n";
    
    return 0;
}