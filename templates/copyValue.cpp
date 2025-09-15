#include <iostream>

template <typename T>
T copyValue(const T& value){
    return value;
}

template <typename T>
T* copyValue(T* ptr){
    if(ptr == NULL){
        return nullptr;
    }
    return new T(*ptr);
}

int main(){
    int x = 20;
    int y = copyValue(x);
    std::cout << "x = " << x << " | y = " << y << "\n";
    
    int* p1 = new int(10);
    int* p2 = copyValue(p1);
    std::cout << "*p1 = " << *p1 << " | *p2 = " << *p2 << "\n";
    
    int* p3 = nullptr;
    int* p4 = copyValue(p3);
    std::cout << "p3 = " << p3 << " | p4 = " << p4 << "\n";
    
    delete p1;
    delete p2;
}