#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

#include "Matrix.h"
#include <vector>

class MatrixMultiplication {
private:
    int numThreads;

public:
    explicit MatrixMultiplication(int threads);

    Matrix multiply(const Matrix& A, const Matrix& B);
};

#endif // MATRIX_MULTIPLICATION_H
