#include <iostream>
#include <vector>
#include <set>

std::vector<int> symmetricDifference(const std::vector<int>& v1, std::vector<int>& v2) {
    std::set<int> s;
    for(int x : v1) {
        s.insert(x);
    }
    
    for(int x : v2) {
        if(s.count(x)) s.erase(x);
        else s.insert(x);
    }
    
    std::vector<int> res;
    for(int x : s) {
        res.push_back(x);
    }
    
    return res;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4};
    std::vector<int> arr2 = {3, 4, 5, 6};
    auto result = symmetricDifference(arr1, arr2);
    // result: {1, 2, 5, 6}
    for(int x : result) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}