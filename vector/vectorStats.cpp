#include <iostream>
#include <vector>
#include <algorithm>

class VectorStats {
public:
    VectorStats(const std::vector<double>& a) : v(a) {}

    double mean() {
        double s = 0;
        for (double x : v) { s += x;}
        if (v.empty()) {
            return 0;
        }
        return s / v.size();
    }

    double median() {
        if (v.empty()) return 0;
        std::vector<double> v1 = v;
        std::sort(v1.begin(), v1.end());
        int n = v1.size();
        if (n % 2 == 0) {
            return (v1[n/2 - 1] + v1[n/2]) / 2;
        }
        return v1[n/2];
    }

    void addValue(double x) { v.push_back(x); }

    void removeValue(double x) {
        for (auto i = v.begin(); i != v.end(); ++i) {
            if (*i == x) { 
                v.erase(i); break; 
            }
        }
    }

private:
    std::vector<double> v;
};

int main() {
    VectorStats stats({1,2,3,4});
    std::cout << stats.mean() << " " << stats.median() << "\n";
    stats.addValue(5);
    stats.removeValue(2);
    std::cout << stats.mean() << " " << stats.median() << "\n";
}