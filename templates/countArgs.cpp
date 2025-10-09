#include <iostream>

template <typename P>
int countArgs(const P&){
    return 1;
}


template<typename T,typename... Rest>
T countArgs(T first, const Rest&... rest){
    return 1 + countArgs(rest...); 
}


int main()
{
    std::cout << countArgs(2, 3, 4, 5) << "\n";
    std::cout << countArgs(2.5, 35.14, 4.8) << "\n";
}