// 1. Constructor chaining construction
// 2. Fix all resultants in order they take 2 parameters that can be used in constructor chaining construction
//  > Specific Constructor possiblle for _ResultMatrix 
// 3. Fix Scalar Multi
// 4. Create necessary operator overloads (req research for what i will do)
// 5. Do memory clenup


#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <type_traits>

/** Tmeplate of _T */
template <typename _T>
struct Matrix // struct Matrix acts as a 2D Matrtix that is in the format as flattened 1D C-Style Array
{
public:
    
    
    const _T* data; // create data pointer fo find heap allocated array
    _T* rowptr; //create  Matrix rowptr of type _T (not used currently)
    _T* colptr; // create Matrix colptr of type _T (not used currently)
    const size_t size; // overall CAPACITY of the Matrix
    const size_t _rows; //create Matrix rows attribute
    const size_t _columns; // Create Matrix cols attribtues
    size_t ObjectCounter; // Keeps track of objects (work in Progress)

    // Need to create multple constructrors and use chaining
    /**
     @parameter: _m row count 
     @parameter: n col count
     @parameter: _orig_ptr , A pre-existing pointer to an array -> Must Check 1. Array is of datatype & More (tbd)
     @parameter: _orig_Matrix ; A pre-existing ARRAY. Passed via Reference or Direct Init (Allows for manual declarations) -> Must Check Array is of datatype & More (tbd)
    */

    // BLUEPRINT CONSTRUCTOR --- DO NOT TAKE SERIOUSLY
    Matrix(size_t _m, size_t _n, ) : _rows(_m), _columns(_n), size(_m * _n), data(new _info[_m * _n])
    {
        for (int i = 0; i < size; i++)
        {
             data[i] = 0;
        }
        ObjectCounter++;
 
    }

    // FIX DESTRUCTOR
    ~Matrix()
    {
        std::cout << "Deleted Matrix @:" << data << "of size" << size(n) << std::endl;
        delete data[];
        ObjectCounter--;
    }


    

    
};


template <typename _T,typename _Y>
Matrix<std::common_type_t<_T,_Y>> MatrixAddition(const Matrix<_T>& Matrix1, const Matrix<_Y>& Matrix2)
{
    if (Matrix1._rows != Matrix2._rows)
    {
        throw std::invalid_argument("Matrices do not have same number of _rows");
    }
    else if (Matrix1._columns != Matrix2._columns)
    {
        throw std::invalid_argument("Matrices do not have same number of columns.");
    }

    using _RType = std::common_type_t<_T, _Y>;
    Matrix<_RType> _ResultantM(Matrix1.size);

    for (int i = 0; i < Matrix1.size; i++)
    {
        _ResultantM.data[i] = Matrix1.data[i] + Matrix2.data[i];

    }
    return _ResultantM;
}
template <typename _T,typename _Y>
Matrix<std::common_type_t<_T,_Y>> MatrixSubtraction(const Matrix<_T>& Matrix1, const Matrix<_Y>& Matrix2)
{   
    /** Opeartion Checks */
    if (Matrix1._rows != Matrix2._rows)
    {
        throw std::invalid_argument("Matrices do not have same number of _rows");
    }
    else if (Matrix1._columns != Matrix2._columns)
    {
        throw std::invalid_argument("Matrices do not have same number of columns.");
    }

    /** Shared Type Conversion */
    using _RType = std::common_type_t<_T, _Y>;
    Matrix<_RType> _ResultantM(Matrix1.size);

    /** Mathematical Implmentation */
    for (int i = 0; i < Matrix1.size; i++)
    {
        _ResultantM.data[i] = Matrix1.data[i] - Matrix2.data[i];

    }
    return _ResultantM;
}

template <typename _T>
Matrix<std::common_type_t<_T,_Y>> MatrixScalarMulti(constexpr Matrix<_T>& Matrix1, const long double scalar) 
{
    /** Opeartion Checks */
    if (scalar != long double)
    {
        throw std::invalid_argument("Scalar is not a valid type. Please enter a valid scalar.");
    }
    /** Shared Type Conversion */

    
    /** Mathematical Implmentation */
    for(int i = 0; i < Matrix1.size; i++)
    {
        _ResultantM.data[i] = scalar * Matrix1.data[i];
    }
    return _ResultantM;
}




template <typename _T,typename _Y> 
Matrix<std::common_type_t<_T,_Y>> MatrixMultiplication(const Matrix<_T>& Matrix1, const Matrix<_T>& Matrix2)
{
    /** Operation Checks */
    if (Matrix1._columns != Matrix2._rows)
    {
        throw std::invalid_argument("The Columns of the first Matrix do not match the _rows of second Matrix.\n Enter a valid Matrix for multiplcation.");
    }
    /** Shared Type Conversion */
    using _RType = std::common_type_t<_T, _Y>;
    Matrix<_RType> _ResultantM(Matrix1._rows * Matrix2._columns);
    /** Math Implementation */

    /** Overall loop that sections the Resultant Matrix over its size that is given by the m x p */
    for (size_t i = 0; i < Matrix1._rows; i++)      
    {
        for (size_t j = 0; j < Matrix2._columns; j++) 
        {
            _RType _vecDot = 0;
            for (size_t k = 0; k < Matrix1._columns; k++)  
            
                _vecDot += static_cast<_RType>(Matrix1.data[i * Matrix1._columns + k]) * static_cast<_RType>(Matrix2.data[k * Matrix2._columns + j]);
            }
            _ResultantM.data[i * Matrix2._columns + j] = sum;
        }
    }
    return _ResultantM;
}
    


