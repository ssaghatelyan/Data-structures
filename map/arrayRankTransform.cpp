#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> arrayRankTransform(const std::vector<int>& arr) {
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());

    std::map<int, int> rank_m;
    int rank = 1;

    for (int x : sortedArr) {
        if (rank_m.count(x) == 0) {
            rank_m[x] = rank++;
        }
    }

    std::vector<int> result;
    for (int x : arr) {
        result.push_back(rank_m[x]);
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {40, 10, 20, 30};
    auto result1 = arrayRankTransform(arr1);
    for (int x : result1) std::cout << x << " ";  // 4 1 2 3
    std::cout << "\n";

    std::vector<int> arr2 = {100, 100, 100};
    auto result2 = arrayRankTransform(arr2);
    for (int x : result2) std::cout << x << " ";  // 1 1 1
}