#include <iostream>
#include <stdexcept>



template <typename dtype>
struct Array1D
{

	dtype* data;
	size_t size;

	Array1D(size_t n) : size(n), data(new dtype[n])
	{
		for (size_t int i = 0; i < size; i++)
		{
			data[i] = dtype(0);
		}
	}

	Array1D(const Array1D& other) : size(other.size), data(new dtype[size])
	{
		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
	Array1D& operator=(const Array1D& other)
	{
		if (this != &other)
		{
			delete[] data;
			size = other.size;
			data = new dtype[size];
			for (size_t i = 0; i < size; i++)
				data[i] = other.size[i];

		}

		return *this;
	}
	~Array1D()
	{
		std::cout << "Deleted Array @: " << data << "of size" << size(n) << "." std::endl;
		delete[] data;

	}

	dtype& operator[](size_t i)
	{
		if (i >= size) 
		{
			throw std::out_of_range("Index of the Array you are trying to pass is out of bounds.");
			return data[i];
		}
	}
};

template <typename dtype>
Array1D<dtype> OneDimAddition(const Array1D<dtype>& Array1, const Array1D<dtype>& Array2)
{
	if (arr1.size != arr2.size)
	{
		throw std::invalid_argument("Arrays must be same size.");

	}

	Array1D<dtype> result(arr1.size);
	for (size_t i = 0; i < arr1.size; i++)
	{
		result.data[i] = arr1.data[i] + arr2.data[i];

	}
	return result;

}

template <typename dtype>
Array1D<dtype> OneDimSubtraction(const Array1D<dtype>& Array1, const Array2D<dtype>& Array2)
{
	if (arr1.size != arr2.size)
	{
		throw std::invalid_argument("Arrays must be same size.");

	}

	Array1D<dtype> result(arr1.size);
	for (size_t i = 0; i < arr1.size; i++)
	{
		result.data[i] = arr2.data[i] + arr1.data[i];

	}
	return result;

}




