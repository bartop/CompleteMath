/*
 * RuntimeArray.h
 *
 *  Created on: 16 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef UTILITY_RUNTIMEARRAY_H_
#define UTILITY_RUNTIMEARRAY_H_

#include <algorithm>

namespace coma {
namespace util {

/**
 * @brief
 * 	Array with size defined at runtime.
 */
template<class T>
class RuntimeArray {
	const unsigned long long m_size = 0;
	T *m_array = nullptr;

public:
	typedef T *iterator;
	typedef const T *const_iterator;
	/**
 	 * @brief
 	 * 	Constructs auto-array of given size.
 	 *
 	 * @param size
 	 * 	Size of constructed array.
 	 *
 	 * @param filler
 	 * 	Default value of array elements.
 	 */
	explicit RuntimeArray(const unsigned long long size, const T filler = T()) : m_size{size}, m_array{new T[size]{}}{
		if(filler != T()) std::fill_n(m_array, size, filler);
	}

	/**
	 * @brief
	 * 	Constructs auto-array with given C-style array.
	 *
	 * @param array
	 *	Array with which auto-array is initialized.
	 *
	 * @param size
	 *	Size of given array.
	 */
	RuntimeArray(const T *array, const unsigned long long size) : RuntimeArray{size}{
		std::copy(array, array + size, m_array);
	}

	/**
	 * @brief
	 * 	Simple copy constructor.
	 *
	 * @param array
	 * 	Auto-array to be copied.
	 */
	RuntimeArray(const RuntimeArray &array) : RuntimeArray{ array.begin(), array.length()}{}

	/**
	 * @brief
	 * 	Returns size of array.
	 *
	 * @return
	 * 	Size of auto-array.
	 */
	const unsigned long long length() const { return m_size; }

	/**
	 * @brief
	 * 	Method used to access array elements.
	 *
	 * @param index
	 * 	Index of desired element.
	 *
	 * @return
	 * 	Element at given index.
	 *
	 */
	const T &operator[](const unsigned long long index) const {
		if (index >= m_size) throw 2;
		return m_array[index]; }

	/**
	 * @brief
	 * 	Method used to access array elements.
	 *
	 * @param index
	 * 	Index of desired element.
	 *
	 * @return
	 * 	Element at given index.
	 *
	 */
	T &operator[](const unsigned long long index){
		if (index >= m_size) throw 2;
		return m_array[index]; }

	/**
	 * @brief
	 * 	Function used to get first array element.
	 *
	 * @return
	 * 	First array element.
	 */
	const T &operator*() const{ return *m_array; }

	/**
	 * @brief
	 * 	Function used to get first array element.
	 *
	 * @return
	 * 	First array element.
	 */
	T &operator*(){ return *m_array; }

	/**
	 * @brief
	 * 	Function returning simplified begin iterator.
	 *
	 * @return
	 * 	Iterator pointing at first element.
	 */
	iterator begin(){ return m_array; }

	/**
	 * @brief
	 * 	Function returning simplified begin iterator.
	 *
	 * @return
	 * 	Iterator pointing at first element.
	 */
	const_iterator begin() const{ return m_array; }

	/**
	 * @brief
	 * 	Function returning simplified end iterator.
	 *
	 * @return
	 * 	Iterator pointing at element behind last one.
	 */
	iterator end(){ return m_array + m_size; }

	/**
	 * @brief
	 * 	Function returning simplified end iterator.
	 *
	 * @return
	 * 	Iterator pointing at element behind last one.
	 */
	const_iterator end() const { return m_array + m_size; }

	/**
	 * @brief
	 * 	Destructor freeing memory.
	 */
	~RuntimeArray(){ if(m_array) delete[] m_array; }
};

} /* namespace util */
} /* namespace coma */

#endif /* UTILITY_RUNTIMEARRAY_H_ */
