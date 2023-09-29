#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <cstddef>

template<typename T>
class Array
{
public:
	Array(void): _data(NULL), _size(0) {};
	Array(unsigned int n)
	{
		_data = new T[n];
		_size = n;
		for (unsigned int i = 0; i < n; i++)
			_data[i] = T();
	}
	Array(const Array& other)
	{
		_data = NULL;
		*this = other;
	}
	~Array(void) { delete[] _data; }

	Array&	operator=(const Array& other)
	{
		if (this != &other)
		{
			if (_data != NULL)
				delete[] _data;
			_size = other._size;
			_data = new T[other._size];
			for (unsigned int i = 0; i < other._size; i++)
				_data[i] = other._data[i];
		}
		return (*this);
	}

	T&	operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range("Index out of range");
		return (_data[index]);
	}

	unsigned int	size(void) { return (_size); }


private:
	T*				_data;
	unsigned int	_size;
};

#endif
