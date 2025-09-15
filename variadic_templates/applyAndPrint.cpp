# include <iostream>

template <typename T, typename... Args>
void applyAndPrint(T function, const Args&... args){
    ((std::cout << function(args) << "\n"),...);
}

int square(int x){
    return x * x;
}

int main(){
    applyAndPrint(square, 2, 3, 4, 5);
}