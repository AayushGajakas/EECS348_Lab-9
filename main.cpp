#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "matrix.hpp"

Matrix read_matrix(std::ifstream& in, std::size_t N) {
    std::vector<std::vector<int>> values(N, std::vector<int>(N));
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            in >> values[i][j];
    return Matrix(values);
}

int main() {
    std::size_t N;
    int dtype;
    std::string filename;

    // Step 1: Get user input
    std::cout << "Enter matrix size and data type (0 for int, 1 for double): ";
    std::cin >> N >> dtype;

    if (dtype != 0) {
        std::cerr << "Only int (0) is supported in this version.\n";
        return 1;
    }

    std::cout << "Enter filename to load matrices from: ";
    std::cin >> filename;

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return 1;
    }

    // Step 2: Read two matrices back-to-back
    Matrix A = read_matrix(infile, N);
    Matrix B = read_matrix(infile, N);

    // Step 3: Perform matrix operations
    std::cout << "\nMatrix A:\n";
    A.print_matrix();

    std::cout << "\nMatrix B:\n";
    B.print_matrix();

    std::cout << "\nA + B:\n";
    Matrix sum = A + B;
    sum.print_matrix();

    std::cout << "\nA * B:\n";
    Matrix product = A * B;
    product.print_matrix();

    std::cout << "\nMajor diagonal of A: " << A.sum_diagonal_major() << "\n";
    std::cout << "Minor diagonal of A: " << A.sum_diagonal_minor() << "\n";

    std::cout << "\nSwapping rows 0 and 1 in A:\n";
    A.swap_rows(0, 1);
    A.print_matrix();

    std::cout << "\nSwapping columns 0 and 1 in A:\n";
    A.swap_cols(0, 1);
    A.print_matrix();

    return 0;
}
