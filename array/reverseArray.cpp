#include <iostream>
#include <array>

template <typename T, std::size_t N>
void reverseArray(std::array<T,N>& arr){
    for(int i=0; i<N/2; i++){
        T temp = arr[i];
        arr[i] = arr[N-1-i];
        arr[N-1-i] = temp;
    }
}

int main(){
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    reverseArray<int, 5>(arr);
    for(int i=0; i<5; i++){
        std::cout << arr[i] << " ";
    }
}