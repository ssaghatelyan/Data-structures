#include <iostream>
#include <array>

template <typename T, std::size_t N>
void shiftLeft(std::array<T, N>& arr, int k){
    for(int i = 0; i< k; i++){
        T first = arr[0];
        for(int j=0; j<arr.size()-1;j++){
            arr[j] = arr[j+1];
        }
        arr[arr.size()-1] = first;
    }
}

int main(){
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    shiftLeft<int, 5>(arr, 2);
    for(int x : arr){
        std::cout << x << " ";
    }
}