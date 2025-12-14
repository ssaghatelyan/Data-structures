#include <iostream>
#include <vector>
#include <queue>

int kthSmallestMinHeap(const std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
    }

    for (int i = 0; i < k - 1; ++i) {
        minHeap.pop();
    }
  
    return minHeap.top();
}

int main() {
    std::vector<int> nums = {7, 10, 4, 3, 20, 15, -1, 8};
    int k = 3;
    std::cout << kthSmallestMinHeap(nums, k) << "\n";
    std::cout << kthSmallestMinHeap(nums, 1) << "\n";
}
