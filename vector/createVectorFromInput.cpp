#include <iostream>
#include <vector>

std::vector<int> createVectorFromInput(){
    std::vector<int> vec;
    int value;
    while(std::cin >> value && value != 0){
        vec.push_back(value);
    }
    
    return vec;
}

int main(){
    std::vector<int> inputVec = createVectorFromInput();
    for(int x : inputVec){
        std::cout << x << " ";
    }
}