#include <iostream>

template <typename T, typename... Args>
T makeObject(Args&&... args){
    return T(std::forward<Args>(args)...);
}

class Person{
public:
    Person(std::string n, int a) : name(std::move(n)), age(a) {}
    
    void print(){
        std::cout << name << " " << age << "\n";
    }
private:
    std::string name;
    int age;
};

int main(){
    auto person = makeObject<Person>("Alice", 25);
    person.print();
}