#include <iostream>
#include <stdexcept>
#include <type_traits>


struct StandardMatrix {
    dtype* data;
    size_t rowNum;
    size_t colNum;
    size_t rows;
    size_t cols;



    StandardMatrix(size_t m, size_t n) : rows(m), cols(n), int size(m* n), data(new dataMatrix[m][n])
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; i < cols; j++) {
                data[i][j] = 0;



    