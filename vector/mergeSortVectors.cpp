#include <iostream>
#include <vector>

std::vector<int> mergeSortedVectors(const std::vector<int>& v1, const std::vector<int>& v2){
    std::vector<int> v3;
    v3.reserve(v1.size() + v2.size());
    
    std::size_t i = 0;
    std::size_t j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            v3.push_back(v1[i]);
            ++i;
        } else {
            v3.push_back(v2[j]);
            ++j;
        }
    }

    while (i < v1.size()) {
        v3.push_back(v1[i]);
        ++i;
    }
    while (j < v2.size()) {
        v3.push_back(v2[j]);
        ++j;
    }
    
    return v3;
}

int main(){
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8, 9};
    std::vector<int> merged = mergeSortedVectors(vec1, vec2);
    for(int x : merged){
        std::cout << x << " ";
    }
    std::cout << "\n";
}