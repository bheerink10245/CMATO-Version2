#include <iostream>
#include <vector>

template <typename dtype>
struct Matrix_Base
{
    dtype* data;
    dtype* rowptr;
    dtype* colptr;
    size_t size;

    Matrix_Base(size_t m, size_t n) :  size(n * m), data(new dtype[m * n])
    {
        for(int i = 0; i < size; i++)
        {
            data[i] = 0
        } 
    }

    
}