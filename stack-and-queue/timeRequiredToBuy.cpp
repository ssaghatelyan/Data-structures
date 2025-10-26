#include <iostream>
#include <queue>
#include <vector>

int timeRequiredToBuy(const std::vector<int>& tickets, int K) {
    std::queue<std::pair<int, int>> q;
    for(int i = 0; i < tickets.size(); ++i) {
        q.push({i, tickets[i]});
    }
    
    int seconds = 0;
    
    while(!q.empty()) {
        std::pair<int, int> p = q.front();
        int i = p.first;
        int rm = p.second;
        q.pop();
        
        rm--;
        seconds++;
        
        if(i == K && rm == 0) {
            return seconds;
        }
        
        if(rm > 0) {
            q.push({i, rm});
        }
    }
    return seconds;
}

int main() {
    std::vector<int> tickets1 = {2, 3, 2};
    std::cout << timeRequiredToBuy(tickets1, 2) << '\n';  // 6

    std::vector<int> tickets2 = {5, 1, 1, 1};
    std::cout << timeRequiredToBuy(tickets2, 0) << '\n';  // 8
}
