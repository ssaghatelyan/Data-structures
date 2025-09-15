#include <iostream>

template <typename T, int N>
class FixedArray{
public:
    void set(int index, T value){
        if(index < 0 || index >= N){
            return;
        }
        arr[index] = value;
    } 
    
    T get(int index, T value){
        if(index >= 0 && index < N){
            return arr[index];
        }
        return T();
    } 
    
    int size(){
        return N;
    }
    
    void print(){
        for(int i=0; i<N; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
private:
    T arr[N]{};
};

int main(){
    FixedArray<int, 3> arr1;
    arr1.set(0, 4);
    arr1.set(1, 10);
    arr1.set(2, 16);
    arr1.print();
    
    FixedArray<double, 4> arr2;
    arr2.set(0, 1.1);
    arr2.set(1, 2.2);
    arr2.set(2, 3.3);
    arr2.set(3, 4.4);
    arr2.print();
    
    FixedArray<std::string, 2> arr3;
    arr3.set(0, "Hi,");
    arr3.set(1, "everyone");
    arr3.print();
}