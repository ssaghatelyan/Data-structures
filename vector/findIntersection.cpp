#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findIntersection(std::vector<int> v1, std::vector<int> v2) {
    std::vector<int> vec;

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    for (int x : v1) {
        for (int y : v2) {
            if (x == y) {
                if (std::find(vec.begin(), vec.end(), x) == vec.end())
                    vec.push_back(x);
                break; 
            }
        }
    }
    return vec;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {3, 4, 5, 6};
    std::vector<int> inter = findIntersection(a, b);

    std::cout << "{";
    for (int i = 0; i < inter.size() - 1 ; ++i) {
        std::cout << inter[i] << ", ";
    }
    std::cout << inter[inter.size() - 1] << "}";
}