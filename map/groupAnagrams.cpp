#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> vec) {
    std::map<std::string, std::vector<std::string>> map;
    for (auto word : vec) {
        std::string s = word;
        std::sort(s.begin(), s.end());
        map[s].push_back(word);
    }
    std::vector<std::vector<std::string>> res;
    for (auto w : map) {
        res.push_back(w.second);
    }
    return res;
}

int main() {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(words);

    for (const auto& group : result) {
        for (const auto& word : group) {
            std::cout << word << " ";
        }
        std::cout << "\n";
    }
}
