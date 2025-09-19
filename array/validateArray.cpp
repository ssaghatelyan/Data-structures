#include <iostream>
#include <array>

template <typename T, size_t N>
bool validateArray(const std::array<T, N>& arr, T min, T max){
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<min ||arr[i]>max){
            return false;
        }
    }
    return true;
}

int main(){
    std::array<int, 4> scores = {85, 92, 78, 96};
    std::cout << std::boolalpha << validateArray<int, 4>(scores, 0, 100) << " ";
}