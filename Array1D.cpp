#include <iostream>
#include <stdexcept>
#include <type_traits>



template <typename _T>
struct Array1D
{

	_T* data;
	size_t size;

	Array1D(size_t n) : size(n), data(new _T[n])
	{
		for (size_t i{ 0 }; i < size; i++)
		{
			data[i] = 0;
		}
	}

	Array1D(const Array1D& other) : size(other.size), data(new _T[size]) //copy constructor??
	{
		for (size_t i{0}; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
	Array1D& operator=(const Array1D& other)
	{
		if (this != &other)
		{
			delete[] data;
			this.size = other.size;
			this.data = new _T[size];
			for (int i{ 0 }; i < size; i++)
				data[i] = other.size[i];

		}

		return *this;
	}
	~Array1D()
	{
		std::cout << "Deleted Array @: " << data << "of size" << size(n) << "." std::endl;
		delete[] data;
	}
};

template <typename _T>
Array1D<_T> Expand(const Array1D<_T> Original, size_t newSize, _T fillValue)
{
	if (newSize < Original.size)
	{
		throw std::invalid_argument("New size must be larger then original."); 
	}
	Array1D<_T> ExpandedArray(newSize);
	for (size_t i{ 0 }; i < Original.size; i++)
	{
		ExpandedArray.data[i] = Original.data[i];
	}
	for (size_t i = Original.size; i < newSize; i++)
	{
		ExpandedArray.data[i] = fillValue;
	}
	return ExpandedArray;
}

template <typename _T,typename _Y>
Array1D<std::common_type_t<_T, _Y>> OneDimAddition(const Array1D<_T>& Array1, const Array1D<_Y>& Array2) 
{
	if (Array1.size != Array2.size)
	{
		throw std::invalid_argument("Arrays must be same size.");
	}
	using _RType = std::common_type_t<_T, _Y>;
	Array1D<_RType> _ResultantA(Array1.size);
	for (size_t i{ 0 }; i < Array1.size; i++)
	{
		_ResultantA.data[i] = Array1.data[i] + Array2.data[i];
	}
	return _ResultantA;
}

template <typename _T,typename _Y>
Array1D<std::common_type_t<_T,_Y>> OneDimSubtraction(const Array1D<_T>& Array1, const Array1D<_Y>& Array2) 
{
	if (Array1.size != Array2.size)
	{
		throw std::invalid_argument("Arrays must be same size.");
    }
	using _RType = std::common_type_t<_T,_Y> ;
	Array1D<_RType> _ResultantA(Array1.size);
	for (size_t i{ 0 }; i < Array1.size; i++)
	{
		_ResultantA.data[i] = Array1.data[i] - Array1.data[i];

	}
	return _ResultantA;
}


template <typename _T,typename _Y>
Array1D<std::common_type_t<_T, _Y>> OneDimScalarMultiplication(const Array1D<_T>& Array1, const long double& Lambda) 
{
	if (Lambda == 0)
	{
		throw std::error_condition("Scalar can not be 0");
	}

	using _RType = std::common_type_t<_T,_Y>>;
	Array1D<_RType> _ResultantA(Array1.size);
	for (size_t i{ 0 }; i < Array1.size, i++)
	{
		_ResultantA.data[i] = Array1.data[i] * Lambda;

	}
	return _ResultantA;
}


template <typename _T,typename _Y>
Array1D<std::common_type_t<_T, _Y>> OneDimCrossProduct(const Array1D<_T>& Array1, const Array1D<_Y> Array2)
{
	if (Array1.size > 3)
	{
		throw std::invalid_argument("Array 1's size is to large. You can not perform the cross product involving a vector with more then 3 elements.");
	}
	else if (Array2.size > 3)
	{
		throw std::invalid_argument("Array 2's size is to large. You can not peform cross product involving a vector with more then 3 elements.");
	}
	auto ArrayA = (Array1.size < 3) ? Expand(Array1, 3, 0) : Array1;
	auto ArrayB = (Array2.size < 3) ? Expand(Array2, 3, 0) : Array2;

	using _RType = std::common_type_t<_T, _Y >> ;
	Array1D<_RType> _ResultantA(Array1.size);
	//hardcode
	_ResultantA.data[0] = ArrayA.data[1] * ArrayB.data[2] - ArrayA.data[2] * ArrayB.data[1];
	_ResultantA.data[1] = ArrayA.data[0] * ArrayB.data[2] - ArrayA.data[2] * ArrayB.data[0];
	_ResultantA.data[2] = ArrayA.data[0] * ArrayB.data[1] - ArrayA.data[1] * ArrayB.data[0];

	return _ResultantA;
}

template <typename _T, typename _Y>
std::common_type_t<_T, _Y> OneDimDotProduct(const Array1D<_T>& Array1, const Array1D<_Y>& Array2) 
{

	if (Array1.size != Array2.size)
	{
		throw std::invalid_argument("Arrays must be same size");
	}
	using _RType = std::common_type_t<_T, _Y>;
	_RType DotProductSum = 0;
	for (size_t i{ 0 }; i < Array1.size; i++)
	{
		DotProductSum += Array1.data[i] * Array2.data[i];
	}
	return DotProductSum;
}



