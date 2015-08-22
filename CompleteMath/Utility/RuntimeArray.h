/*
 * RuntimeArray.h
 *
 *  Created on: 16 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef UTILITY_RUNTIMEARRAY_H_
#define UTILITY_RUNTIMEARRAY_H_

#include <algorithm>
#include <type_traits>

namespace coma {
namespace util {

/**
 * @brief
 * 	Array with size defined at runtime.
 */
template<class T>
class RuntimeArray {
public:
	using iterator = class CppIterator{
	public:
		using DifferenceType = decltype(static_cast<T *>(1) - nullptr);
		using size_t = std::size_t;

		CppIterator() noexcept = default;
		CppIterator(const CppIterator &toCopy) noexcept = default;
		CppIterator(CppIterator &&toMove) noexcept = default;
		~CppIterator() noexcept = default;
		CppIterator &operator=(const CppIterator &toCopy) noexcept = default;
		CppIterator &operator=(CppIterator &&toMove) noexcept = default;
		T &operator*(){ return *m_current; }
		constexpr const T &operator*() const{ return *m_current; }
		T &operator[](size_t position){ return m_current[position]; }
		const T &operator[](size_t position) const{ return m_current[position]; }
		CppIterator &operator++(){
			++m_current;
			return *this;
		}
		CppIterator operator++(int){
			auto tmp = *this;
			++*this;
			return tmp;
		}
		CppIterator &operator--(){
			--m_current;
			return *this;
		}
		CppIterator operator--(int){
			auto tmp = *this;
			--*this;
			return tmp;
		}
		CppIterator &operator+=(unsigned displacement){
			m_current += displacement;
			return *this;
		}
		CppIterator &operator-=(unsigned displacement){
			m_current -= displacement;
			return *this;
		}
		CppIterator operator+(DifferenceType displacement) const{ return *this += displacement; }
		CppIterator operator-(DifferenceType displacement) const{ return *this -= displacement; }
		DifferenceType operator-(const CppIterator &rhs) const{ return m_current - rhs.m_current; }
		T *operator->(){ return m_current; }
		const T *operator->() const{ return m_current; }
		bool operator==(const CppIterator &rhs) const noexcept{ return m_current == rhs.m_current; }
		bool operator!=(const CppIterator &rhs) const noexcept{ return m_current != rhs.m_current; }
		bool operator<(const CppIterator &rhs) const noexcept{ return m_current < rhs.m_current; }
		bool operator>(const CppIterator &rhs) const noexcept{ return m_current > rhs.m_current; }
		bool operator>=(const CppIterator &rhs) const noexcept{ return m_current >= rhs.m_current; }
		bool operator<=(const CppIterator &rhs) const noexcept{ return m_current <= rhs.m_current; }

		void setAtBeginning(const RuntimeArray &array){ m_current = array.m_array; }
		void setAtEnd(const RuntimeArray &array){ m_current = array.m_array + array.m_size; }
		void setAtPosition(const RuntimeArray &array, size_t position){ m_current = array.m_array + position; }
	private:
		T *m_current = nullptr;
	};
	using const_iterator = typename RuntimeArray<const std::decay_t<T> >::iterator;
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
	explicit RuntimeArray(size_t size, const T filler = T()) : m_size{size}, m_array{size ? new T[size]{} : nullptr}{
		if(filler != T() && m_array && m_size) std::fill_n(m_array, size, filler);
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
	RuntimeArray(const T *array, size_t size) : RuntimeArray{size}{
		if(m_size && m_array) std::copy(array, array + size, m_array);

	}

	/**
	 * @brief
	 * 	Simple copy constructor.
	 *
	 * @param array
	 * 	Auto-array to be copied.
	 */
	RuntimeArray(const RuntimeArray &array) : RuntimeArray{ array.cStyleArray(), array.length()}{}

	/**
	 * @brief
	 * 	Simple move constructor.
	 *
	 * @param array
	 * 	Array to move.
	 */
	RuntimeArray(RuntimeArray &&array) : m_array{array.m_array}, m_size{array.m_size}{
		array.m_array = nullptr;
	}

	/**
	 * @brief
	 * 	Destructor freeing memory.
	 */
	~RuntimeArray(){ if(m_array) delete[] m_array; }

	/**
	 * @brief
	 * 	Returns c-style array stored inside object.
	 *
	 * @return
	 * 	Pointer to c-style array stored in object.
	 */
	const T *cStyleArray() const noexcept{ return m_array; }

	/**
	 * @brief
	 * 	Returns size of array.
	 *
	 * @return
	 * 	Size of auto-array.
	 */
	size_t length() const noexcept{ return m_size; }

	/**
	 * @brief
	 * 	Method used to access array elements.
	 *
	 * @param index
	 * 	Index of desired element.
	 *
	 * @return
	 * 	Element at given index.
	 */
	const T &operator[](size_t index) const {
		if (index >= m_size) throw 2;
		return m_array[index];
	}

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
	T &operator[](size_t index){
		if (index >= m_size) throw 2;
		return m_array[index];
	}

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
	 * 	CppIterator pointing at first element.
	 */
	iterator begin() noexcept{
		iterator it{};
		it.setAtBeginning(*this);
		return it;
	}

	/**
	 * @brief
	 * 	Function returning simplified begin iterator.
	 *
	 * @return
	 * 	CppIterator pointing at first element.
	 */
	const_iterator begin() const noexcept{ return m_array; }

	/**
	 * @brief
	 * 	Function returning simplified end iterator.
	 *
	 * @return
	 * 	CppIterator pointing at element behind last one.
	 */
	iterator end() noexcept{
		iterator it{};
		it.setAtEnd(*this);
		return it;
	}

	/**
	 * @brief
	 * 	Function returning simplified end iterator.
	 *
	 * @return
	 * 	CppIterator pointing at element behind last one.
	 */
	const_iterator end() const noexcept{ return m_array + m_size; }

private:
	unsigned long long m_size = 0;
	T *m_array = nullptr;
};

} /* namespace util */
} /* namespace coma */

#endif /* UTILITY_RUNTIMEARRAY_H_ */
