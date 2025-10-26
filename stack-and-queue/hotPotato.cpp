#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::string hotPotato(std::vector<std::string>& players, int K) {
    std::queue<std::string> q;
    
    for(auto& name : players) {
        q.push(name);
    }
    
    while(q.size() > 1) {
        for(int i = 0; i < K; ++i) {
            std::string front  = q.front();
            q.push(front);
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

int main() {
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    std::cout << "Winner: " << hotPotato(players, 7) << '\n';
    return 0;
}