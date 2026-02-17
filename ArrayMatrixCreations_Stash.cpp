


template <typename dtype>
dtype* rowptr;
dtype* colptr;

for (int i = 0; i < rows; i + rows) {
    rowptr = (ArrayMatrix[i])&;
    for (int j = ArrayMatrix[i]; j < cols; j++) {
        colptr = (ArrayMatrix[j])&;
        std::cout << *(colptr) << std::endl;
    }
}



// Protoype for multiplcation




// Takes in the 2 arrays



template <typename dtype>
ArrayMatrix<dtype> MatrixMultiplication(const ArrayMatrix<dtype>& Matrix1, const ArrayMatrix<dtype>&Matrix2)
{

    //add dtype check
    if (Matrix1.cols != Matrix2.rows)
    {
        throw std::invalid_arguement("The Columns of the first Matrix do not match the rows of second Matrix.\n Enter a valid Matrix for multiplcation.")
    }

    dtype resultVec[Matrix1.rows * Matrix2.cols];

    for(int )


}



// 

template <typename dtype>

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

            }
        }
    }

    ~StandardMatrix() {
        std::cout << "Deleted Standard Matrix @" << data << std::endl;
        delete data[][];

    }



 
};


template <typename dtype>
StandardMatrix<dtype> StandardMatrixMultiplication(const StandardMatrix<dtype>& Matrix1, const StandardMatrix<dtype>& Matrix2) {


}


    