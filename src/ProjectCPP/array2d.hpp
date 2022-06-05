#include <vector>

#include "array2d.h"
#include <iostream>


namespace math
{
	template <typename T>
	const unsigned int Array2D<T>::getWidth() const { return width; }
	template <typename T>
	const unsigned int Array2D<T>::getHeight() const { return height; }

	template <typename T>
	T * Array2D<T>::getRawDataPtr() { return &buffer[0]; }

	template <typename T>
	void Array2D<T>::setData(const T*const& data_ptr) {
		unsigned int size = width * height;
		if (buffer.size() != 0) buffer.clear();
		buffer.reserve(size);
		for (int i = 0; i < size; i++)
			buffer.push_back(data_ptr == NULL ? 0 : data_ptr[i]);
	}

	template <typename T>
	T & Array2D<T>::operator () (unsigned int x, unsigned int y) {
		return buffer[y * width + x];
	}


	template <typename T>
	Array2D<T>::Array2D(unsigned int width, unsigned int height, const T * data_ptr) {
		(*this).width = width;
		(*this).height = height;
		setData(data_ptr);
	}

	template <typename T>
	Array2D<T>::Array2D(const Array2D& src) {
		width = src.width;
		height = src.height;
		buffer.reserve(width*height);
		for (T i : src.buffer) {
			buffer.push_back(i);
		}
	}



	template <typename T>
	Array2D<T>::~Array2D() {}

	template <typename T>
	Array2D<T>& Array2D<T>::operator = (const Array2D& right) {
		width = right.width;
		height = right.height;
		buffer.reserve(width * height);
		memcpy(&buffer[0], &right.buffer[0], (width * height) * sizeof(T));
		return *this;
	}

}