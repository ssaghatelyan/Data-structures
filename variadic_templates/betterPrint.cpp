#include <iostream>

template <typename T>
void foo(T& value){
    std::cout << value << " [lvalue]\n";
}

template <typename T>
void foo(T&& value){
    std::cout << value << " [rvalue]\n";
}

template <typename... Args>
void betterPrint(Args&&... args){
    (foo(std::forward<Args>(args)), ...);
}

int main(){
    int x = 42;
    betterPrint(x, 100, "hello");
}