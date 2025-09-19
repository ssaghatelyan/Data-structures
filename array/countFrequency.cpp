#include <iostream>
#include <array>

template <size_t N>
std::array<int, 256> countFrequency(const std::array<char, N>& arr){
    std::array<int, 256> freq{};
    for(int i=0;i<arr.size();++i){
        freq[static_cast<unsigned char>(arr[i])]++;
    }
    return freq;
}

int main(){
    std::array<char, 5> text = {'h', 'e', 'l', 'l', 'o'};
    auto freq = countFrequency<5>(text);
    std::cout << freq['h'] << " " << freq['e'] << " " << freq['l'] << " " << freq['o'] << "\n"; 
}