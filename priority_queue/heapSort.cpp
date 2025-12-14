#include <iostream>
#include <vector>
#include <queue>

std::vector<int> heapSort(const std::vector<int>& nums) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int x : nums)
        minHeap.push(x);

    std::vector<int> result;
    result.reserve(nums.size());

    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}
