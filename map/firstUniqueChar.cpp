#include <iostream>
#include <map>

int firstUniqueChar(std::string str) {
    std::map<char, int> m;
    for (auto x : str) {
        m[x]++;
    }
    for (int i = 0; i < str.size(); ++i) {
        if (m[str[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::string s = "leetcode";
    std::cout << firstUniqueChar(s) << '\n';  // 0 ('l')

    std::string s2 = "loveleetcode";
    std::cout << firstUniqueChar(s2) << '\n';  // 2 ('v')
}