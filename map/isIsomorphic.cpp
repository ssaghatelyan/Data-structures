#include <iostream>
#include <string>
#include <map>

bool isIsomorphic(const std::string& s1, const std::string& s2) {
    if (s1.size() != s2.size()) return false;

    std::map<char, char> m1, m2;

    for (int i = 0; i < s1.size(); ++i) {
        if (m1[s1[i]] && m1[s1[i]] != s2[i]) return false;
        if (m2[s2[i]] && m2[s2[i]] != s1[i]) return false;
        m1[s1[i]] = s2[i];
        m2[s2[i]] = s1[i];
    }

    return true;
}

int main() {
    std::cout << isIsomorphic("egg", "add") << "\n";     // 1
    std::cout << isIsomorphic("foo", "bar") << "\n";     // 0
    std::cout << isIsomorphic("paper", "title") << "\n"; // 1
}