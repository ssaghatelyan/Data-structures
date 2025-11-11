#include <iostream>
#include <vector>
#include <set>

std::vector<int> findMissingNumbers(std::vector<int> nums, int N) {
    std::set<int> s;
    for (int x : nums) {
        s.insert(x);
    }
    std::vector<int> result;
    for (int i = 1; i <=N; ++i) {
        int size = s.size();
        s.insert(i);
        if (size != s.size()) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 7, 9};
    auto result = findMissingNumbers(nums, 10);
    // result: {2, 4}
    for (int x : result) {
        std::cout << x << " ";
    }
}
