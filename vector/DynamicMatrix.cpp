#include <iostream>
#include <vector>

class DynamicMatrix {
public:
    DynamicMatrix(int rows, int cols) {
        matrix.resize(rows, std::vector<int>(cols, 0));
    }
    
    int getElement(int row, int col) {
        return matrix[row][col];
    }
    
    void setElement(int row, int col, int value) {
        matrix[row][col] = value;
    }
    
    void addRow() {
        if(matrix.empty()){
            matrix.push_back({0});
        }
        else{
            matrix.push_back(std::vector<int>(matrix[0].size(), 0));
        }
    }
    
    void addCol() {
        if(matrix.empty()){
            matrix.push_back({0});
        }
        else{
            for(auto& row : matrix){
                row.push_back({0});
            }
        }
    }
    
     void print() const {
        for (const auto& row : matrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }
    
private:
    std::vector<std::vector<int>> matrix;
};

int main(){
    DynamicMatrix matrix(3, 3);
    matrix.setElement(1, 1, 42);
    matrix.addRow();
    matrix.addCol();
    matrix.print();
}