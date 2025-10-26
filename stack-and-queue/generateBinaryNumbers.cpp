#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::vector<std::string> generateBinaryNumbers(int N) {
    std::vector<std::string> result;
    std::queue<std::string> q;
    
    q.push("1");
    
    for(int i = 0; i < N; ++i) {
        std::string curr = q.front();
        q.pop();
        
        result.push_back(curr);
        
        q.push(curr + "0");
        q.push(curr + "1");
    }
    
    return result;
}

int main(){
    auto result = generateBinaryNumbers(5);

    std::cout << "result: {";
    for(int  i = 0; i < result.size() - 1; ++i) {
        std::cout << "\"" << result[i] << "\", ";
    }
    std::cout << "\"" << result[result.size()-1] << "\"}";
    std::cout << "\n";
}