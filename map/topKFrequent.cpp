#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::map<int, int> freq;

    for (int x : nums) {
        freq[x]++;
    }

    std::vector<std::pair<int, int>> vec;
    for (auto p : freq) {
        vec.push_back({p.second, p.first});
    }

    std::sort(vec.begin(), vec.end());

    std::vector<int> result;
    for (int i = 0; i < k && i < vec.size(); ++i) {
        result.push_back(vec[i].first);
    }
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    auto result = topKFrequent(nums, 2);

    for (int x : result) std::cout << x << " ";
}