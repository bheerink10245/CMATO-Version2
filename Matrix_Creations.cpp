#include <iostream>
#include <vector>
#include <stdexcept>

template <typename dtype>
struct Matrix_Base
{
    dtype* data;
    dtype* rowptr;
    dtype* colptr;
    size_t size;
    size_t rows;
    size_t cols;


    Matrix_Base(size_t m, size_t n) :  rows(m), cols(n), size(n * m), data(new dtype[m * n])
    {
        for(int i = 0; i < size; i++)
        {
            data[i] = 0;
        } 
    }

    Matrix_Base& opreator=(const Matrix_Base& other)
    {
        if(this != &other)
        {
            delete [] data;
            size = other.size;
            data = new dtype[size];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = other.size[i];
            }

            return *this;
        }
    ~Matrix_Base()
    {
        std::cout << "Deleted Matrix @:" << data << "of size" << size(n) << std::endl;
        delete data[];
    }


    }

    
};

// This means that they must have the same numbers of rows and columns.
// So, for instance, a 2 × 3 matrix can be added to another 2 × 3 matrix; it could *not* be added to a 3 × 2 matrix.


// 

template <typename dtype>
Matrix_Base<dtype> MatrixAddition(const Matrix_Base<dtype>& Matrix1, const Matrix_Base<dtype>& Matrix2)
{
    if (Matrix1.rows != Matrix2.rows)
    {
        throw std::invalid_argument("Matrices do not have same number of rows");
    }
    if (Matrix1.cols != Matrix2.cols)
    {
        thorw std::invalid_argument("Matrices do not have same number of columns.");
    }

}