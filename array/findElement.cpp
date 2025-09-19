#include <iostream>
#include <array>

template <typename T, std::size_t N>
int findElement(std::array<T, N>& arr,const T& value){
    for(int i=0; i<N; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}

int main(){
    std::array<int, 4> arr = {12, 64, 4, 25};
    
    std::cout << findElement(arr, 4) << std::endl;
    std::cout << findElement(arr, 10) << std::endl;
}