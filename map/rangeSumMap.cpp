#include <iostream>
#include <map>

int rangeSumMap(std::map<int, int> map, int left, int right) {
    int sum = 0;

    for (auto x : map) {
        if (x.first >= left && x.first <= right) {
            sum += x.second;
        }
    }
    return sum;
}

int main() {
    std::map<int, int> m = {{1, 10}, {3, 20}, {5, 30}, {7, 40}};
    std::cout << rangeSumMap(m, 3, 7) << '\n';  // 90 (20 + 30 + 40)
    std::cout << rangeSumMap(m, 2, 4) << '\n';  // 20 (только ключ 3)
}