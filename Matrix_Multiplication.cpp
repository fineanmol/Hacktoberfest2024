#include <iostream>
#include <vector>

// Function to perform matrix multiplication
std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();
    
    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;
    
    std::cout << "Enter the dimensions of the first matrix (rows columns): ";
    std::cin >> rows1 >> cols1;
    
    std::cout << "Enter the dimensions of the second matrix (rows columns): ";
    std::cin >> rows2 >> cols2;
    
    if (cols1 != rows2) {
        std::cout << "Matrix multiplication is not possible with these dimensions." << std::endl;
        return 1;
    }
    
    std::cout << "Enter the elements of the first matrix:" << std::endl;
    std::vector<std::vector<int>> matrix1(rows1, std::vector<int>(cols1));
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            std::cin >> matrix1[i][j];
        }
    }
    
    std::cout << "Enter the elements of the second matrix:" << std::endl;
    std::vector<std::vector<int>> matrix2(rows2, std::vector<int>(cols2));
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            std::cin >> matrix2[i][j];
        }
    }
    
    std::vector<std::vector<int>> result = matrixMultiply(matrix1, matrix2);
    
    std::cout << "The result of matrix multiplication is:" << std::endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
