#include <iostream>
#include <array>

template <typename T, std::size_t N>
bool compareArrays(std::array<T,N>& arr1, std::array<T,N>& arr2){
    for(int i = 0; i<N; i++){
        if(arr1[i] != arr2[i]){
            return false;;
        }
    }
    return true;
}

int main(){
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    std::cout << std::boolalpha << compareArrays(arr1, arr2) << std::endl;
    std::array<int, 3> arr3 = {1, 2, 3};
    std::array<int, 3> arr4 = {1, 2, 5};
    std::cout << std::boolalpha << compareArrays(arr3, arr4) << std::endl;
}