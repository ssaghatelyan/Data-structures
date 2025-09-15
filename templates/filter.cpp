#include <iostream>

bool isEven(const int& x){
    return x % 2 == 0;
}

bool isNegative(const double& x) {
    return x < 0;
}

bool academy(const std::string w) {
    if(w == "academy"){
        return true;
    };
    return false;
}


template <typename T, typename P>
void filter(T* array,int size, P pred){
    T arr2[100]{};
    int j = 0;
    for(int i = 0;i < size;i++){
        if(pred(array[i])){
            arr2[j] = array[i];
            std::cout << arr2[j] << " ";
            j++;
        }
    }
    
}


int main()
{
    int arr[5] = {1, 2, 2, 5, 10};
    double arr1[3] = {15.2, 0, -3.5};
    std::string arr2[4] = {"Hello", "sun", "academy", "Dog"};
    filter<int>(arr,5,isEven);
    std::cout << std::endl;
    filter<double>(arr1, 3, isNegative);
    std::cout << std::endl;
    filter<std::string>(arr2, 4, academy);
    std::cout << std::endl;
    return 0;
} 