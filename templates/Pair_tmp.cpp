#include <iostream>

template <typename T1, typename T2>
class Pair{
public:
    Pair(T1 x, T2 y) : first(x), second(y) {}
    
    void print(){
        std::cout << "Pair: " << first << "," << second << "\n";
    }
    
private:
    T1 first;
    T2 second;
};

template <typename T>
class Pair<T, T>{
public:
    Pair(T x, T y) : first(x), second(y) {}
    
    void print(){
        std::cout << "Pair of identical types: " << first << "," << second << "\n";
    }
    
private:
    T first;
    T second;
};

int main(){
    Pair<int, double> p1(10, 2.5);
    p1.print();
    Pair<std::string, int> p2("September", 2025);
    p2.print();
    Pair<char, double> p3('a', 7.2);
    p3.print();
    Pair<int, int> p4(9, 9);
    p4.print();
}