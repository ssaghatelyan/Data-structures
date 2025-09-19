#include <iostream>
#include <array>

template <typename T, std::size_t N, std::size_t M>
std::array<T, M> copySubArray(std::array<T,N>& arr1, int start, int size){
    std::array<T, M> arr2{};
    for(int i=0; i<size; i++){
        arr2.at(i) = arr1.at(start + i);
    }
    return arr2;
}

int main(){
    std::array<int, 10> source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto sub = copySubArray<int, 10, 5>(source, 2, 5);
    for(int x : sub){
        std::cout << x << " ";
    }
}