#include <iostream>
#include <vector>
#include <set>

int firstRepeating(const std::vector<int>& v) {
    std::set<int> s;
    for(int x : v) {
        if(s.count(x)) return x;
        s.insert(x);
    }
    return -1;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 2, 5, 6, 3};
    std::cout << firstRepeating(nums) << '\n';  // 2
}