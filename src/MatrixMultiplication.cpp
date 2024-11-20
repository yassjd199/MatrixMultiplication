#include "MatrixMultiplication.h"
#include <thread>


MatrixMultiplication::MatrixMultiplication(int threads) : numThreads(threads) {}

void multiplyRowRange(const Matrix& A, const Matrix& B, Matrix& C, int rowStart, int rowEnd) {
    for (int i = rowStart; i < rowEnd; ++i) {
        for (int j = 0; j < B.getCols(); ++j) {
            C.at(i, j) = 0;
            for (int k = 0; k < A.getCols(); ++k) {
                C.at(i, j) += A.at(i, k) * B.at(k, j);
            }
        }
    }
}

Matrix MatrixMultiplication::multiply(const Matrix& A, const Matrix& B) {
    if (!Matrix::canMultiply(A, B)) {
        throw std::invalid_argument("Matrix dimensions are incompatible for multiplication.");
    }

    int rowsA = A.getRows();
    int colsB = B.getCols();
    Matrix C(rowsA, colsB);

    int rowsPerThread = (rowsA + numThreads - 1) / numThreads;
    std::vector<std::thread> threads;

    for (int t = 0; t < numThreads; ++t) {
        int rowStart = t * rowsPerThread;
        int rowEnd = std::min(rowStart + rowsPerThread, rowsA);

        threads.emplace_back(multiplyRowRange, std::cref(A), std::cref(B), std::ref(C), rowStart, rowEnd);
    }

    for (auto& th : threads) {
        th.join();
    }

    return C;
}
