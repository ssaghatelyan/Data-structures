#include <iostream>
#include <vector>
#include <set>

int removeRange(std::set<int>& s, int low, int high) {
    int count = 0;
    for(auto it = s.begin(); it != s.end();) {
        if(* it >= low && *it <= high) {
            it = s.erase(it);
            count++;
        }
        else{
            ++it;
        }
    }
    return count;
}

int main() {
    std::set<int> s = {1, 3, 5, 7, 9, 11, 13, 15};
    int removed = removeRange(s, 5, 11);
    std::cout << removed << '\n';  // 4
    // s теперь содержит: {1, 3, 13, 15}
}