#include <iostream>
#include <map>

std::map<std::string, int> mergeMaps(const std::map<std::string, int>& m1, const std::map<std::string, int>& m2) {
    std::map<std::string, int> res = m1;
    for (auto x : m2) {
        res[x.first] += x.second;
    }
    return res;
}

int main() {
    std::map<std::string, int> map1 = {{"a", 1}, {"b", 2}, {"c", 3}};
    std::map<std::string, int> map2 = {{"b", 3}, {"c", 4}, {"d", 5}};
    auto result = mergeMaps(map1, map2);
    // result: {{"a", 1}, {"b", 5}, {"c", 7}, {"d", 5}}
    for (auto x : result) {
        std::cout << x.first << " : " <<  x.second << "\n";
    }
}