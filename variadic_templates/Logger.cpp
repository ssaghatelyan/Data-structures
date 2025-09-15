# include <iostream>

class Logger{
public:
    Logger(int spaces){
        count = spaces;
    }
    
    template <typename... Args>
    void log(const Args&... args){
        (printOne(args), ...);
    }
private:
    int count;
    template <typename T>
    void printOne(const T& value){
        for(int i = 0; i < count; i++){
            std::cout << " ";
        }
        std::cout << value << "\n";
    }
};

int main(){
    Logger logger(4);
    logger.log("Hello", 42, 3.14, 'A');
}