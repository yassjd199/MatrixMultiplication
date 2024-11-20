#include "Matrix.h"


Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols, 0)) {}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }
int& Matrix::at(int row, int col) { return data[row][col]; }
const int& Matrix::at(int row, int col) const { return data[row][col]; }

void Matrix::input() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> data[i][j];
        }
    }
}

void Matrix::display() const {
    for (const auto& row : data) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

bool Matrix::canMultiply(const Matrix& A, const Matrix& B) {
    return A.getCols() == B.getRows();
}
