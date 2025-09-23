#include <iostream>
#include <vector>

template <typename T>
std::vector<T> filterVector(const std::vector<T>& vec, bool (*pred)(T)) {
    std::vector<T> vec1;
    for(T x : vec){
        if(pred(x)) { vec1.push_back(x);}
    }
    return vec1;
}

bool isEven(int x) {return x % 2 == 0;}

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> filtered = filterVector(vec, isEven);
    
    for(int i = 0; i < filtered.size(); ++i){
        std::cout << filtered[i] << " ";
    }
}