# include <iostream>

template <typename T1, typename T2>
std::pair<T1,T2> makePairList(const T1& first, const T2& second){
    return {first, second};
}

template <typename T1, typename T2, typename... Rest>
auto makePairList(const T1& first, const T2& second, const Rest&... rest){
    return std::pair<T1,decltype(makePairList(second, rest...))>(
        first, makePairList(second, rest...));
}

int main(){
    auto pair1 = makePairList(5, 'c');
    auto pair2 = makePairList(5, 'c', 4.32);
    auto pair3 = makePairList(1, 2, 3, 4);
}