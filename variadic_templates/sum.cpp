#include <iostream>

template <typename P>
P sum1(const P& arg1){
    return arg1;
}


template<typename T,typename... Rest>
T sum1(T arg, const Rest&... rest){
    return arg + sum1(rest...); 
}


int main()
{
    std::cout << sum1(2, 3, 4) << "\n";
    std::cout << sum1(2.5, 3.5, 4.5) << "\n";
    std::cout << sum1(std::string("a"),std::string("b"), std::string("c")) << "\n";
}