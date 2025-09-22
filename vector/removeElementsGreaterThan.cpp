#include <iostream>
#include <vector>

int removeElementsGreaterThan(std::vector<int>& vec, int limit){
    int count = 0;
    while(!vec.empty() && vec.back() > limit){
        vec.pop_back();
        count++;
    }
    return count;
}

int main(){
    std::vector<int> vec = {1, 3, 5, 7, 9};
    int count = removeElementsGreaterThan(vec, 5);
    std::cout << count << std::endl;
}