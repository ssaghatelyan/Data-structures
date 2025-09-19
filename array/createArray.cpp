#include <iostream>
#include <array>

std::array<int, 5> createArray(){
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    return arr;
}

int main(){
    std::array<int, 5> arr = createArray();
    for(int x : arr){
        std::cout << x << " ";
    }
    return 0;
}