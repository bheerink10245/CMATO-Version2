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