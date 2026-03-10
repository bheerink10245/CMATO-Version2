#include <iostream>
#include <stdexcept>
#include <type_traits>



template <typename dtype>
struct Array1D
{

	dtype* data;
	size_t size;

	Array1D(size_t n) : size(n), data(new dtype[n])
	{
		for (size_t i{ 0 }; i < size; i++)
		{
			data[i] = 0;
		}
	}

	Array1D(const Array1D& other) : size(other.size), data(new dtype[size]) //copy constructor??
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
			this.data = new dtype[size];
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


template <typename dtype,typename Utype>
Array1D<std::common_type_t<dtype, Utype>> OneDimAddition(const Array1D<dtype>& Array1, const Array1D<Utype>& Array2) 
{
	if (Array1.size != Array2.size)
	{
		throw std::invalid_argument("Arrays must be same size.");
	}
	using Result_Type = std::common_type_t<dtype, Utype>;
	Array1D<Result_Type> ResultantArray(Array1.size);
	for (size_t i{ 0 }; i < Array1.size; i++)
	{
		ResultantArray.data[i] = Array1.data[i] + Array2.data[i];
	}
	return ResultantArray;
}

template <typename dtype,typename Utype>
Array1D<std::common_type_t<dtype,Utype>> OneDimSubtraction(const Array1D<dtype>& Array1, const Array1D<Utype>& Array2) 
{
	if (Array1.size != Array2.size)
	{
		throw std::invalid_argument("Arrays must be same size.");
    }
	using Result_Type = std::common_type_t<dtype,Utype> ;
	Array1D<Result_Type> ResultantArray(Array1.size);
	for (size_t i{ 0 }; i < Array1.size; i++)
	{
		ResultantArray.data[i] = Array1.data[i] - Array1.data[i];

	}
	return ResultantArray;
}


template <typename dtype,typename Utype>
Array1D<std::common_type_t<dtype, Utype>> OneDimScalarMultiplication(const Array1D<dtype>& Array1, const long double& Lambda) 
{
	if (Lambda == 0)
	{
		throw std::error_condition("Scalar can not be 0");
	}

	using Result_Type = std::common_type_t<dtype,Utype>>;
	Array1D<Result_Type> ResultantArray(Array1.size);
	for (size_t i{ 0 }; i < Array1.size, i++)
	{
		ResultantArray.data[i] = Array1.data[i] * Lambda;

	}
	return ResultantArray;
}


template <typename dtype,typename Utype>
Array1D<std::common_type_t<dtype, Utype>> OneDimCrossProduct(const Array1D<dtype>& Array1, const Array1D<Utype> Array2)
{
	if (Array1.size != Array2.size)
	{
		throw std::invalid_argument("Arrays must be same size.");
	}
	using Result_Type = std::common_type_t<dtype, Utype >> ;
	Array1D<Result_Type> ResultantArray(Array1.size); 
	for (size_t i{ 0 }; i < Array1.size; i++)
	{
		//idk the fucking math
	}
}


template <typename dtype, typename Utype>
std::common_type_t<dtype, Utype> OneDimDotProduct(const Array1D<dtype>& Array1, const Array1D<Utype>& Array2) 
{

	if (Array1.size != Array2.size)
	{
		throw std::invalid_argument("Arrays must be same size");
	}
	using Result_Type = std::common_type_t<dtype, Utype>;
	Result_Type DotProductSum = 0;
	for (size_t i{ 0 }; i < Array1.size; i++)
	{
		DotProductSum += Array1[i] * Array2[i];
	}
	return DotProductSum;
}

