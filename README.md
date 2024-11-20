
```markdown
# Matrix Multiplication with Multithreading

This project demonstrates the implementation of matrix multiplication using multithreading in C++. The goal is to leverage the power of multiple CPU cores to speed up the matrix multiplication process for larger matrices.

## Project Overview

The project consists of two primary classes:
- **Matrix**: Represents a matrix and provides utility functions for matrix operations.
- **MatrixMultiplication**: Handles the logic for matrix multiplication, including multithreading to distribute the computation across multiple threads.

The program supports user-defined matrix dimensions and automatically determines the number of threads to utilize based on the system's hardware capabilities.

## Compilation and Setup

### Requirements
- A C++ compiler (e.g., g++ or clang++)
- CMake for building the project

### Build Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/yassjd199/MatrixMultiplication.git
   cd MatrixMultiplication
   ```

2. Create a build directory and compile the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

### Running the Program

After building the project, you can run the matrix multiplication program with any desired matrix dimensions. The number of threads used for computation can be specified based on the system's CPU capabilities.

To run the program, use the following command:
```bash
./matrix_multiplication 
```
Input Format :

number of rows of A  number of columns of A

A[0][0] A[0][1].......
A[1][0] A[0][1].......

number of rows of B  number of columns of B

B[0][0] B[0][1].......
B[1][0] B[0][1].......




The program will automatically decide on the number of threads based on your system's capabilities.

## Performance Insights

### Speedup with Multithreading

The following results were observed while running matrix multiplication on a **1000x1000 matrix** using both a single thread and multiple threads (12 threads, which is the maximum supported by the system):

- **Single-threaded (1 thread):**
  - **Real time**: 10.765s
  - **User time**: 10.751s
  - **System time**: 0.010s

- **Multithreaded (12 threads):**
  - **Real time**: 2.576s
  - **User time**: 22.687s
  - **System time**: 0.036s

### Performance Analysis

- **Speedup Factor**: 
  The multithreaded version achieved a speedup of approximately **4.18x** compared to the single-threaded implementation. This shows a substantial reduction in wall-clock time due to the concurrent execution of multiple threads.

- **Efficiency per Thread**: 
  The efficiency of each thread, considering the ideal scenario (linear scaling with number of threads), is about **34.8%**. This is a typical result due to factors like thread management overhead and diminishing returns when the number of threads exceeds the number of CPU cores.

### Observations

- **Multithreading** significantly reduces the execution time for larger matrices, especially when utilizing the maximum number of available CPU threads.
- The **single-threaded execution** is noticeably slower due to the sequential nature of the computation, where the full matrix multiplication occurs on a single core.
- As the matrix size grows, the performance improvement with multithreading becomes more evident.
- For smaller matrices, the overhead from managing multiple threads may outweigh the performance benefits, but for larger matrices (e.g., \(1000 \times 1000\)), the improvements are substantial.

## Conclusion

This project demonstrates how multithreading can significantly enhance the performance of computationally intensive tasks such as matrix multiplication. The results show that using the maximum number of available CPU threads can lead to impressive speedups, especially for large matrices. However, the scaling performance will vary based on system architecture and the size of the matrices.
```

