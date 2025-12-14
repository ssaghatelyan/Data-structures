#include <iostream>
#include <vector>
#include <queue>

std::vector<int> mergeKSortedLists(const std::vector<std::vector<int>>& lists) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (auto list : lists) {
        for (int num : list) {
            minHeap.push(num);
        }
    }
    
    std::vector<int> result;

    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return result;
}

int main() {
    std::vector<std::vector<int>> lists = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };
    auto result = mergeKSortedLists(lists);
    // result: {1, 1, 2, 3, 4, 4, 5, 6}
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}
