#include <iostream>
#include <map>
#include <vector>

std::map<char, std::vector<std::string>> groupByFirstChar(const std::vector<std::string>& vec) {
    std::map<char, std::vector<std::string>> res;
    for (auto x : vec) {
        char key = x[0];
        res[key].push_back(x);
    }
    return res;
}

int main() {
    std::vector<std::string> words = {"apple", "banana", "apricot", "cherry", "avocado"};
    auto result = groupByFirstChar(words);
    // result: {'a': ["apple", "apricot", "avocado"], 'b': ["banana"], 'c': ["cherry"]}
    for (const auto& pair : result) {
        std::cout << pair.first << " : ";
        for (const auto& word : pair.second) {
            std::cout << word << " ";
        }
        std::cout << "\n";
    }
}