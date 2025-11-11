#include <iostream>
#include <vector>
#include <set>

bool isSubset(const std::vector<int>& subset, const std::vector<int>& superset) {
    std::set<int> s;
    for (int x : superset) {
        s.insert(x);
    }
    std::vector<int> result;
    for (int x : subset) {
        int size = s.size();
        s.insert(x);
        if (size != s.size()) {
            return false;
        }
    }
    return true;;
}

int main() {
    std::vector<int> subset = {1, 3, 5};
    std::vector<int> superset = {1, 2, 3, 4, 5};
    std::cout << std::boolalpha << isSubset(subset, superset) << '\n';  // 1 (true)

    std::vector<int> subset2 = {1, 6};
    std::cout << std::boolalpha << isSubset(subset2, superset) << '\n';  // 0 (false)
}
