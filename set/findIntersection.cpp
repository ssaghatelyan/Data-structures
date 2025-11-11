#include <iostream>
#include <vector>
#include <set>

std::vector<int> findIntersection(const std::vector<int>& v1, const std::vector<int>& v2) {
    std::set<int> s;
    for (int x : v1) {
        s.insert(x);
    }
    std::vector<int> result;
    for (int x : v2) {
        int size = s.size();
        s.insert(x);
        if (size == s.size()) result.push_back(x);
    }
    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {3, 4, 5, 6, 7};
    auto result = findIntersection(arr1, arr2);
    // result: {3, 4, 5}
    for (int x : result) {
        std::cout << x << " ";
    }
}
