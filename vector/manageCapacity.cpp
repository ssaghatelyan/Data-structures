#include <iostream>
#include <vector>

void manageCapacity(std::vector<int>& vec){
    std::cout << "Before: \n";
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Capacity: " << vec.capacity() << "\n";
    
    vec.reserve(vec.size() + 500);
    
    for(int i = 0; i < 500; i++){
        vec.push_back(i);
    }
    
    std::cout << "After: \n";
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Capacity: " << vec.capacity() << "\n";
    
}

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    manageCapacity(vec);
}