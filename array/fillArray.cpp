#include <iostream>
#include <array>

std::array<int, 10> fillArray(std::array<int, 10> &arr, int value){
    for(int& x : arr){
        x = value;
    }
    return arr;
}

int main(){
    std::array<int, 10> arr = {1, 2, 3, 1, 2, 3, 1};
    fillArray(arr, 42);
    for(int x : arr){
        std::cout << x << " ";
    }
    
}