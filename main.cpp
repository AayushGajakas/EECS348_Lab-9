#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "matrix.hpp"

template <typename T>
Matrix<T> read_matrix(std::ifstream& in, std::size_t N) {
    std::vector<std::vector<T>> values(N, std::vector<T>(N));
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            in >> values[i][j];
    return Matrix<T>(values);
}

template <typename T>
void run_matrix_program(std::ifstream& in, std::size_t N) {
    Matrix<T> A = read_matrix<T>(in, N);
    Matrix<T> B = read_matrix<T>(in, N);

    std::cout << "Matrix A:\n";
    A.print_matrix();

    std::cout << "\nMatrix B:\n";
    B.print_matrix();

    std::cout << "\nA + B:\n";
    Matrix<T> sum = A + B;
    sum.print_matrix();

    std::cout << "\nA * B:\n";
    Matrix<T> product = A * B;
    product.print_matrix();

    std::cout << "\nMajor diagonal of A: " << A.sum_diagonal_major() << "\n";
    std::cout << "Minor diagonal of A: " << A.sum_diagonal_minor() << "\n";

    std::cout << "\nSwapping rows 0 and 1 in A:\n";
    A.swap_rows(0, 1);
    A.print_matrix();

    std::cout << "\nSwapping columns 0 and 1 in A:\n";
    A.swap_cols(0, 1);
    A.print_matrix();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Failed to open file: " << argv[1] << "\n";
        return 1;
    }

    std::size_t N;
    int dtype;
    infile >> N >> dtype;

    if (dtype == 0) {
        run_matrix_program<int>(infile, N);
    } else if (dtype == 1) {
        run_matrix_program<double>(infile, N);
    } else {
        std::cerr << "Unsupported data type. Use 0 for int or 1 for double.\n";
        return 1;
    }

    return 0;
}
