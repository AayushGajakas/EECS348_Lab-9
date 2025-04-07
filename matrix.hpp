#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <iostream>
#include <stdexcept>

class Matrix {
public:
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<int>> nums);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, int n);
    int get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;

private:
    std::vector<std::vector<int>> data;
    std::size_t size;
};

// Constructor for empty NxN matrix
Matrix::Matrix(std::size_t N) : size(N), data(N, std::vector<int>(N, 0)) {}

// Constructor from 2D vector
Matrix::Matrix(std::vector<std::vector<int>> nums) {
    if (nums.empty() || nums.size() != nums[0].size())
        throw std::invalid_argument("Matrix must be square.");

    size = nums.size();
    data = nums;
}

// Matrix addition
Matrix Matrix::operator+(const Matrix &rhs) const {
    if (size != rhs.size)
        throw std::invalid_argument("Matrix sizes must match for addition.");

    Matrix result(size);
    for (std::size_t i = 0; i < size; ++i)
        for (std::size_t j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] + rhs.data[i][j];
    return result;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix &rhs) const {
    if (size != rhs.size)
        throw std::invalid_argument("Matrix sizes must match for multiplication.");

    Matrix result(size);
    for (std::size_t i = 0; i < size; ++i)
        for (std::size_t j = 0; j < size; ++j)
            for (std::size_t k = 0; k < size; ++k)
                result.data[i][j] += data[i][k] * rhs.data[k][j];
    return result;
}

// Set value at (i, j)
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= size || j >= size)
        throw std::out_of_range("Index out of bounds.");
    data[i][j] = n;
}

// Get value at (i, j)
int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= size || j >= size)
        throw std::out_of_range("Index out of bounds.");
    return data[i][j];
}

// Get size of the matrix
int Matrix::get_size() const {
    return static_cast<int>(size);
}

// Sum of major (top-left to bottom-right) diagonal
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i)
        sum += data[i][i];
    return sum;
}

// Sum of minor (top-right to bottom-left) diagonal
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i)
        sum += data[i][size - i - 1];
    return sum;
}

// Swap two rows
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= size || r2 >= size)
        throw std::out_of_range("Row index out of bounds.");
    std::swap(data[r1], data[r2]);
}

// Swap two columns
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= size || c2 >= size)
        throw std::out_of_range("Column index out of bounds.");
    for (std::size_t i = 0; i < size; ++i)
        std::swap(data[i][c1], data[i][c2]);
}

// Print matrix
void Matrix::print_matrix() const {
    for (const auto& row : data) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
}
#endif // __MATRIX_HPP__
