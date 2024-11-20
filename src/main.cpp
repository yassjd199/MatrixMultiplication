#include "Matrix.h"
#include "MatrixMultiplication.h"
#include <iostream>
#include <thread>



void fillRandom(Matrix& matrix) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            matrix.at(i, j) = rand() % 100;
        }
    }
}

int main() {
    Matrix A(1000, 1000), B(1000, 1000);
    fillRandom(A);
    fillRandom(B);


    // std::cin >> rowsA >> colsA;
    // Matrix A(rowsA, colsA);
    // A.input();
    // std::cin >> rowsB >> colsB;
    // Matrix B(rowsB, colsB);
    // B.input();
    std::cout << std::min(1000, (int)std::thread::hardware_concurrency()) << std::endl;

    try {
        MatrixMultiplication mm(std::min(1, (int)std::thread::hardware_concurrency()));
        Matrix C = mm.multiply(A, B);

        //C.display();
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
