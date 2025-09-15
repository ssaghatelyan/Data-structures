#include <iostream>


template <typename T1, typename T2>
class Pair{
public:
    Pair(T1 f, T2 s) : first(f), second(s){}
    void print(){
        std::cout << first << " " << second << std::endl;
    }
private:
    T1 first;
    T2 second;
};


int main()
{
    Pair<int, double> p1(2025, 8.9);
    p1.print();
    Pair<std::string, int> p2("RAU", 2);
    p2.print();
    return 0;
} 