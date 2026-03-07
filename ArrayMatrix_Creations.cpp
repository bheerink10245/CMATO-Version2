
// Creating ArrayMatrix, goonna do 2D after. Doing both first
// COnstructors are currently crap :/ 

#include <iostream>
#include <stdexcept>

template <typename dtype>
struct ArrayMatrix
{
public:

    dtype* data;
    constexpr dtype* rowptr;
    constexpr dtypee* colptr;
    size_t size;
    size_t rows;
    size_t cols;


    ArrayMatrix(size_t m, size_t n) : rows(m), cols(n), size(m * n), data(new [])
    {
        for(int i = 0; i < size; i++)
        {
             data[i] = 0;
        } 
    }

    ArrayMatrix& operator=(const ArrayMatrix& other)
    {
        if(this != &other)
        {
            delete [] data;
            const size = other.size;
            constexpr data = new dtype[size];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = other.size[i];
            }

            return *this;
        }
    ~ArrayMatrix()
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
ArrayMatrix<dtype> MatrixAddition(const ArrayMatrix<dtype>& Matrix1, const ArrayMatrix<dtype>& Matrix2)
{
    if (Matrix1.rows != Matrix2.rows)
    {
        throw std::invalid_argument("Matrices do not have same number of rows");
    }
    else if (Matrix1.cols != Matrix2.cols)
    {
        throw std::invalid_argument("Matrices do not have same number of columns.");
    }

    dtype resultVec[Matrix1.size];https://open.spotify.com/track/577YBGuskWkVDCxZrLRB4v

    for (int i = 0; i < Matrix1.size; i++)
    {
        resultVec[i] = Matrix1[i] + Matrix2[i];

    }
    return resultVec;
}
template <typename dtype>
ArrayMatrix<dtype> MatrixSubtraction(const ArrayMatrix<dtype>& Matrix1, const ArrayMatrix<dtype>& Matrix2)
{
    if (Matrix1.rows != Matrix2.rows)
    {
        throw std::invalid_argument("Matrices do not have same number of rows");
    }
    else if (Matrix1.cols != Matrix2.cols)
    {
        throw std::invalid_argument("Matrices do not have same number of columns.");
    }

    auto resultVec[Matrix1.size];

    for (int i = 0; i < Matrix1.size; i++)
    {
        resultVec[i] = Matrix1[i] - Matrix2[i];

    }
    return resultVec;
}

template <typename dtype>
ArrayMatrix<dtype> MatrixScalarMulti(constexpr ArrayMatrix<dtype>& Matrix, const long double scalar) 
{
    auto resultVec[Matrix.size];
    if (scalar != long double)
    {
        throw std::invalid_argument("Scalar is not a valid type. Please enter a valid scalar.");
    }

    for(int i = 0; i < Matrix; i++)
    {
        resultVec[i] = scalar * Matrix[i];
    }
    return resultVec;
}

template <typename dtype> 
ArrayMatrix<dtype> MatrixMultiplication(constexpr ArrayMatrix<dtype>& Matrix1, constexpr ArrayMatrix<dtype>& Matrix2)
{
    if (Matrix1.cols != Matrix2.rows)
    {
        throw std::invalid_arguement("The Columns of the first Matrix do not match the rows of second Matrix.\n Enter a valid Matrix for multiplcation.")
    }
    




    
   
}


