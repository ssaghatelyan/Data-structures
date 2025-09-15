#include <iostream>

template <typename... Args>
std::string makeSentence(const std::string& first, const Args&... rest){
    std::string sentence = first;
    ((sentence += ' ', sentence += rest), ...);
    sentence += '.';
    return sentence;
}

int main(){
    std::cout << makeSentence(std::string("GNU's"), std::string("Not"), std::string("Unix")) << "\n";
    std::cout << makeSentence(std::string("Hello"), std::string("world")) << "\n";
    
}