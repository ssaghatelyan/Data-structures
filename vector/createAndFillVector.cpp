#include <iostream>
#include <vector>

void createAndFillVector(int N){
    std::vector<int> vec(N);
    for(int i = 0; i < vec.size(); i++){
        vec[i] = i + 1;
    }
    
    for(int x : vec){
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    std::cout << "Size: " << vec.size() << '\n';
    std::cout << "Capacity: " << vec.capacity() << '\n';
}

int main(){
    int n = 5;
    createAndFillVector(5);
}