#include <iostream>
#include <vector>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& vec) {
    std::vector<std::vector<int>> vec1;
    if (vec.empty()) {return vec1;}

    std::vector<int> vec2;
    vec2.push_back(vec[0]);

    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] == vec[i - 1]) {
            vec2.push_back(vec[i]);
        }
        else {
            vec1.push_back(vec2);
            vec2.clear();
            vec2.push_back(vec[i]);
        }
    }
    vec1.push_back(vec2);
    return vec1;
}

int main() {
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};
    std::vector<std::vector<int>> groups = groupAdjacent(vec);

    for (int i = 0; i < groups.size() -1; ++i) {
        std::cout << "{";
        for (int j = 0; j < groups[i].size()-1; ++j) {
            std::cout << groups[i][j] << ",";
        }
        std::cout << groups[i][groups[i].size()-1];
        std::cout << "}\n";
    }
}