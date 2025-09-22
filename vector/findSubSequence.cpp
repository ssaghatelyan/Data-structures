#include <iostream>
#include <vector>

int findSubSequence(const std::vector<int>& v1, const std::vector<int>& v2){
    if(v2.empty() || v2.size() > v1.size()) {
        return -1;
    }
    for (int i = 0; i <= v1.size() - v2.size(); i++) {
        int j = 0;
        while (j < v2.size() && v1[i + j] == v2[j]){
            j++;
        }
        if (j == (int)v2.size()) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> main_vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> sub_vec  = {3, 4, 5};
    std::cout << findSubSequence(main_vec, sub_vec) << "\n";
}