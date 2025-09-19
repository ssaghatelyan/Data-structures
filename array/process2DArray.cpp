#include <iostream>
#include <array>

template <typename T, size_t row, size_t col, typename func>
std::array<std::array<T, col>, row> process2DArray(const std::array<std::array<T, col>, row>& arr, func f){
    std::array<std::array<T, col>, row> arr1{};
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr1[i][j] = f(arr[i][j]);
        }
    } 
    return arr1;
}

int doubleValue(int x){
    return x * 2;
}

int main(){
    std::array<std::array<int, 3>, 3> m = {{
        {{1, 2, 3}},
        {{4, 5, 6}},
        {{7, 8, 9}},
    }};
    auto m1 = process2DArray(m, doubleValue);
    
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            std::cout << m1[i][j] << " ";
        }
        std::cout << "\n";
    }
}