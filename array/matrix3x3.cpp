#include <iostream>
#include <array>

class Matrix3x3{
public:
    Matrix3x3(int a00, int a01, int a02,
              int a10, int a11, int a12,
              int a20, int a21, int a22) {
            m = {{{a00, a01, a02},
                {a10, a11, a12},
                {a20, a21, a22}}};
    }
    
    int getElement(int row, int col){
        return m[row][col];
    }
    
    void setElement(int row, int col, int value){
        m[row][col] = value;
    }
    
    void transpose(){
        for(int i=0; i<3; i++){
            for(int j=i+1; j<3;j++){
                std::swap(m[i][j], m[j][i]);
            }
        }
    }
    
    void print(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3;j++){
                std::cout << m[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
    std::array<int, 3>& operator[](int row) { 
        return m[row]; 
    }
private:
    std::array<std::array<int, 3>, 3> m;
};

int main(){
    Matrix3x3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
    m.print();
    m.transpose();
    m.print();
    std::cout << m[0][0];
}