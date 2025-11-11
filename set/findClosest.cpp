#include <iostream>
#include <vector>
#include <set>

int findClosest(const std::set<int>& st, int target) {
    if(st.empty()) return -1;
    
    auto it = st.lower_bound(target);
    
    if(it == st.begin()) return *it;
    if(it == st.end()) {
        --it;
        return *it;
    }
    
    auto before = it;
    --before;
    
    int right = *it;
    int left = *before;
    
    if(std::abs(right-target) < std::abs(left-target)) return right;
    else return left;
}

int main() {
    std::set<int> s = {1, 5, 10, 15, 20};
    std::cout << findClosest(s, 12) << '\n';  // 10
    std::cout << findClosest(s, 13) << '\n';   // 15
}