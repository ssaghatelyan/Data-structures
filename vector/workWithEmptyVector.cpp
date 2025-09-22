#include <iostream>
#include <vector>

void workWithEmptyVector(){
    std::vector<int> vec;
    
    for(int i = 0; i < 10; i++){
        vec.push_back(i+1);
        std::cout << "Size: " << vec.size() << '\n';
        std::cout << "Capacity: " << vec.capacity() << '\n';
    }
}

int main(){
    workWithEmptyVector();
}