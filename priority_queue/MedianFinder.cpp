#include <iostream>
#include <queue>

class MedianFinder {
private:
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;
    
public:
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    std::cout << mf.findMedian() << '\n';  // 1.5
    mf.addNum(3);
    std::cout << mf.findMedian() << '\n';  // 2.0
}
