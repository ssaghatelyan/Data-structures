#include <iostream>
#include <vector>
#include <set>

int rangeCount(const std::set<int>& s, int low, int high) {
    int count = 0;
    for (int x : s) {
        if (*(s.lower_bound(x))>= low && *(s.lower_bound(x)) <= high) {
            count++;
        }
    }
    return count;
}

int main() {
    std::set<int> s = {1, 3, 5, 7, 9, 11, 13, 15};
    std::cout << rangeCount(s, 5, 11) << '\n';  // 4 (элементы: 5, 7, 9, 11)
}
