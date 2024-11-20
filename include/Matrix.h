#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols);

    int getRows() const;
    int getCols() const;
    int& at(int row, int col);
    const int& at(int row, int col) const;

    void input();
    void display() const;

    static bool canMultiply(const Matrix& A, const Matrix& B);
};

#endif // MATRIX_H
