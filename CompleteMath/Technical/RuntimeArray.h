/*
 * RuntimeArray.h
 *
 *  Created on: 16 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef UTILITY_RUNTIMEARRAY_H_
#define UTILITY_RUNTIMEARRAY_H_

#include <algorithm>
#include <initializer_list>
#include <iterator>

#include "../defines.h"
#include "Iterator.h"
#include "TypeTraits.h"

namespace coma {
namespace tech {

//Forward declarations of classes
template<class T>
class RuntimeArray;

template<class T>
class RuntimeArrayIterator;

template<class T>
class RuntimeArrayConstantIterator;

//----------------------------------------------------------------------------------------------------------
//Forward declarations of functions
template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
Iterator &operator+=(
		Iterator &lhs,
		typename Iterator::DifferenceType rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
Iterator &operator-=(
		Iterator &lhs,
		typename Iterator::DifferenceType rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
Iterator operator+(
		const Iterator &lhs,
		typename Iterator::DifferenceType rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
Iterator operator-(
		const Iterator &lhs,
		typename Iterator::DifferenceType rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
typename Iterator::DifferenceType operator-(
		const Iterator &lhs,
		const Iterator &rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
bool operator==(
		const Iterator &lhs,
		const Iterator &rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
bool operator!=(
		const Iterator &lhs,
		const Iterator &rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
bool operator>(
		const Iterator &lhs,
		const Iterator &rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
bool operator<(
		const Iterator &lhs,
		const Iterator &rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
bool operator>=(
		const Iterator &lhs,
		const Iterator &rhs);

template<class Iterator, class = std::enable_if_t<isSpecialization<Iterator, RuntimeArrayIterator>()
		|| isSpecialization<Iterator, RuntimeArrayConstantIterator>() > >
bool operator<=(
		const Iterator &lhs,
		const Iterator &rhs);

//--------------------------------------------------------------------------------------------------------
//Definitions
/**
 * @brief
 * 	Iterator for RuntimeArray.
 */
template<class T>
class RuntimeArrayIterator :
	public Iterator<std::random_access_iterator_tag, T>{
public:
	//Typedefs
	using Container = RuntimeArray<T>;
	using Base = Iterator<std::random_access_iterator_tag, T>;

	//Friends
	friend RuntimeArrayIterator<T> &operator+=<RuntimeArrayIterator<T> >(
			RuntimeArrayIterator<T> &lhs,
			typename Base::DifferenceType rhs);

	friend RuntimeArrayIterator<T> &operator-=<RuntimeArrayIterator<T> >(
			RuntimeArrayIterator<T> &lhs,
			typename Base::DifferenceType rhs);

	friend RuntimeArrayIterator<T> operator+<RuntimeArrayIterator<T> >(
			const RuntimeArrayIterator<T> &lhs,
			typename Base::DifferenceType rhs);

	friend RuntimeArrayIterator<T> operator-<RuntimeArrayIterator<T> >(
			const RuntimeArrayIterator<T> &lhs,
			typename Base::DifferenceType rhs);

	friend typename Base::DifferenceType operator-<RuntimeArrayIterator<T> >(
			const RuntimeArrayIterator<T> &lhs,
			const RuntimeArrayIterator<T> &rhs);

	friend bool operator==<RuntimeArrayIterator<T> >(
		const RuntimeArrayIterator<T> &lhs,
		const RuntimeArrayIterator<T> &rhs);

	friend bool operator!=<RuntimeArrayIterator<T> >(
		const RuntimeArrayIterator<T> &lhs,
		const RuntimeArrayIterator<T> &rhs);

	friend bool operator><RuntimeArrayIterator<T> >(
		const RuntimeArrayIterator<T> &lhs,
		const RuntimeArrayIterator<T> &rhs);

	friend bool operator< <RuntimeArrayIterator<T> >(
		const RuntimeArrayIterator<T> &lhs,
		const RuntimeArrayIterator<T> &rhs);

	friend bool operator<=<RuntimeArrayIterator<T> >(
		const RuntimeArrayIterator<T> &lhs,
		const RuntimeArrayIterator<T> &rhs);

	friend bool operator>=<RuntimeArrayIterator<T> >(
		const RuntimeArrayIterator<T> &lhs,
		const RuntimeArrayIterator<T> &rhs);

	//Methods
	/**
	 * @brief
	 * 	Default constructor.
	 */
	RuntimeArrayIterator() = default;

	/**
	 * @brief
	 * 	Default copy constructor.
	 *
	 * @param rhs
	 * 	Object to copy.
	 */
	RuntimeArrayIterator(const RuntimeArrayIterator &rhs) = default;

	/**
	 * @brief
	 * 	Default move constructor.
	 *
	 * @param rhs
	 * 	Object to move.
	 */
	RuntimeArrayIterator(RuntimeArrayIterator &&rhs) = default;

	/**
	 * @brief
	 * 	Default assignment operator.
	 *
	 * @param rhs
	 * 	Object to assign.
	 *
	 * @return
	 * 	Reference to @c *this after assignment.
	 */
	RuntimeArrayIterator &operator=(const RuntimeArrayIterator &rhs) = default;

	/**
	 * @brief
	 * 	Default move assignment operator.
	 *
	 * @param rhs
	 * 	Object to assign.
	 *
	 * @return
	 * 	Reference to @c *this after assignment.
	 */
	RuntimeArrayIterator &operator=(RuntimeArrayIterator &&rhs) = default;

	/**
	 * @brief
	 * 	Dereference current object.
	 *
	 * @return
	 * 	Reference to pointed object.
	 */
	typename Base::ReferenceType operator*(){ return *m_current; }

	/**
	 * @brief
	 * 	Dereference current object as constant.
	 *
	 * @return
	 * 	Reference to constant pointed object.
	 */
	const typename Base::ReferenceType operator*() const { return *m_current; }

	/**
	 * @brief
	 * 	Use -> operator on pointed object.
	 *
	 * @return
	 * 	Pointer to stored object.
	 */
	typename Base::PointerType operator->(){ return m_current; }

	/**
	 * @brief
	 * 	Use -> operator on constant pointed object.
	 *
	 * @return
	 * 	Pointer to constant stored object.
	 */
	const typename Base::PointerType operator->() const{ return m_current; }

	/**
	 * @brief
	 * 	Get reference of object stored @a index away.
	 *
	 * @param index
	 * 	Relative position of object desired to dereference. Index can be negative!
	 *
	 * @return
	 * 	Reference to object stored @a index positions from current.
	 */
	typename Base::ReferenceType operator[](typename Base::DifferenceType index){ return m_current[index]; }

	/**
	 * @brief
	 * 	Get reference of object stored @a index away.
	 *
	 * @param index
	 * 	Relative position of object desired to dereference. Index can be negative!
	 *
	 * @return
	 * 	Reference to object stored @a index positions from current.
	 */
	const typename Base::ReferenceType operator[](typename Base::DifferenceType index) const{ return m_current[index]; }

	/**
	 * @brief
	 * 	Moves to next object, returns reference after incrementation.
	 *
	 * @return
	 * 	Reference to iterator after incrementation.
	 */
	RuntimeArrayIterator &operator++(){
		++m_current;
		return *this;
	}

	/**
	 * @brief
	 * 	Returns current iterator, then moves to next object.
	 *
	 * @param dummy
	 * 	Dummy argument.
	 *
	 * @return
	 * 	Iterator before incrementation.
	 */
	RuntimeArrayIterator operator++(int dummy){
		auto tmp = *this;
		++m_current;
		return tmp;
	}

	/**
	 * @brief
	 * 	Moves to previous object, returns reference after decrementation.
	 *
	 * @return
	 * 	Reference to iterator after decrementation.
	 */
	RuntimeArrayIterator &operator--(){
		--m_current;
		return *this;
	}

	/**
	 * @brief
	 * 	Returns current iterator, then moves to previous object.
	 *
	 * @param dummy
	 * 	Dummy argument.
	 *
	 * @return
	 * 	Iterator before decrementation.
	 */
	RuntimeArrayIterator operator--(int dummy){
		auto tmp = *this;
		--m_current;
		return tmp;
	}

	/**
	 * @brief
	 * 	Sets position of iterator at beginning of given array.
	 *
	 * @param array
	 * 	RuntimeArray to iterate.
	 */
	void setAtBeginning(const RuntimeArray<T> &array);//Defined later

	/**
	 * @brief
	 * 	Sets position of iterator at end of given array.
	 *
	 * @param array
	 * 	RuntimeArray to iterate.
	 */
	void setAtEnd(const RuntimeArray<T> &array);//Defined later

private:
	/**
	 * @brief
	 * 	Pointer storing current object.
	 */
	typename Base::PointerType m_current = nullptr;
};

/**
 * @brief
 * 	ConstantIterator for RuntimeArray.
 */
template<class T>
class RuntimeArrayConstantIterator :
	public Iterator<std::random_access_iterator_tag, T, const T *, const T &>{
public:
	//Typedefs
	using Container = RuntimeArray<T>;
	using Base = Iterator<std::random_access_iterator_tag, T, const T *, const T &>;

	//Friends
	friend RuntimeArrayConstantIterator<T> &operator+=<RuntimeArrayConstantIterator<T> >(
			RuntimeArrayConstantIterator<T> &lhs,
			typename Base::DifferenceType rhs);

	friend RuntimeArrayConstantIterator<T> &operator-=<RuntimeArrayConstantIterator<T> >(
			RuntimeArrayConstantIterator<T> &lhs,
			typename Base::DifferenceType rhs);

	friend RuntimeArrayConstantIterator<T> operator+<RuntimeArrayConstantIterator<T> >(
			const RuntimeArrayConstantIterator<T> &lhs,
			typename Base::DifferenceType rhs);

	friend RuntimeArrayConstantIterator<T> operator-<RuntimeArrayConstantIterator<T> >(
			const RuntimeArrayConstantIterator<T> &lhs,
			typename Base::DifferenceType rhs);

	friend typename Base::DifferenceType operator-<RuntimeArrayConstantIterator<T> >(
			const RuntimeArrayConstantIterator<T> &lhs,
			const RuntimeArrayConstantIterator<T> &rhs);

	friend bool operator==<RuntimeArrayConstantIterator<T> >(
		const RuntimeArrayConstantIterator<T> &lhs,
		const RuntimeArrayConstantIterator<T> &rhs);

	friend bool operator!=<RuntimeArrayConstantIterator<T> >(
		const RuntimeArrayConstantIterator<T> &lhs,
		const RuntimeArrayConstantIterator<T> &rhs);

	friend bool operator> <RuntimeArrayConstantIterator<T> >(
		const RuntimeArrayConstantIterator<T> &lhs,
		const RuntimeArrayConstantIterator<T> &rhs);

	friend bool operator< <RuntimeArrayConstantIterator<T> >(
		const RuntimeArrayConstantIterator<T> &lhs,
		const RuntimeArrayConstantIterator<T> &rhs);

	friend bool operator>=<RuntimeArrayConstantIterator<T> >(
		const RuntimeArrayConstantIterator<T> &lhs,
		const RuntimeArrayConstantIterator<T> &rhs);

	friend bool operator<=<RuntimeArrayConstantIterator<T> >(
		const RuntimeArrayConstantIterator<T> &lhs,
		const RuntimeArrayConstantIterator<T> &rhs);

	//Methods
	/**
	 * @brief
	 * 	Default constructor.
	 */
	RuntimeArrayConstantIterator() = default;

	/**
	 * @brief
	 * 	Default copy constructor.
	 *
	 * @param rhs
	 * 	Object to copy.
	 */
	RuntimeArrayConstantIterator(const RuntimeArrayConstantIterator &rhs) = default;

	/**
	 * @brief
	 * 	Default move constructor.
	 *
	 * @param rhs
	 * 	Object to move.
	 */
	RuntimeArrayConstantIterator(RuntimeArrayConstantIterator &&rhs) = default;

	/**
	 * @brief
	 * 	Conversion constructor from non-constant iterator.
	 *
	 * @param rhs
	 * 	Iterator to convert to constant one.
	 */
	RuntimeArrayConstantIterator(const RuntimeArrayIterator<T> &rhs) : m_current{rhs.m_current}{}

	/**
	 * @brief
	 * 	Move conversion constructor from non-constant iterator.
	 *
	 * @param rhs
	 * 	Iterator to convert to constant one.
	 */
	RuntimeArrayConstantIterator(RuntimeArrayIterator<T> &&rhs) : m_current{std::move(rhs.m_current)}{}

	/**
	 * @brief
	 * 	Default assignment operator.
	 *
	 * @param rhs
	 * 	Object to assign.
	 *
	 * @return
	 * 	Reference to @c *this after assignment.
	 */
	RuntimeArrayConstantIterator &operator=(const RuntimeArrayConstantIterator &rhs) = default;

	/**
	 * @brief
	 * 	Default move assignment operator.
	 *
	 * @param rhs
	 * 	Object to assign.
	 *
	 * @return
	 * 	Reference to @c *this after assignment.
	 */
	RuntimeArrayConstantIterator &operator=(RuntimeArrayConstantIterator &&rhs) = default;

	/**
	 * @brief
	 * 	Converting assignment operator.
	 *
	 * @param rhs
	 * 	Non-const iterator to assign.
	 *
	 * @return
	 * 	Iterator after assignment.
	 */
	RuntimeArrayConstantIterator &operator=(const RuntimeArrayIterator<T> &rhs){
		m_current = rhs.m_current;
		return *this;
	}

	/**
	 * @brief
	 * 	Converting move assignment operator.
	 *
	 * @param rhs
	 * 	Non-const iterator to assign.
	 *
	 * @return
	 * 	Iterator after assignment.
	 */
	RuntimeArrayConstantIterator &operator=(RuntimeArrayIterator<T> &&rhs){
		m_current = std::move(rhs.m_current);
		return *this;
	}

	/**
	 * @brief
	 * 	Dereference current object.
	 *
	 * @return
	 * 	Reference to pointed object.
	 */
	typename Base::ReferenceType operator*() const{ return *m_current; }

	/**
	 * @brief
	 * 	Uses -> operator on pointed object.
	 *
	 * @return
	 * 	Pointer to stored object.
	 */
	typename Base::PointerType operator->() const{ return m_current; }

	/**
	 * @brief
	 * 	Get reference of object stored @a index away.
	 *
	 * @param index
	 * 	Relative position of object desired to dereference. Index can be negative!
	 *
	 * @return
	 * 	Reference to object stored @a index positions from current.
	 */
	typename Base::ReferenceType operator[](typename Base::DifferenceType index) const{ return m_current[index]; }

	/**
	 * @brief
	 * 	Moves to next object, returns reference after incrementation.
	 *
	 * @return
	 * 	Reference to iterator after incrementation.
	 */
	RuntimeArrayConstantIterator &operator++(){
		++m_current;
		return *this;
	}

	/**
	 * @brief
	 * 	Returns current iterator, then moves to next object.
	 *
	 * @param dummy
	 * 	Dummy argument.
	 *
	 * @return
	 * 	Iterator before incrementation.
	 */
	RuntimeArrayConstantIterator operator++(int dummy){
		auto tmp = *this;
		++m_current;
		return tmp;
	}

	/**
	 * @brief
	 * 	Moves to previous object, returns reference after decrementation.
	 *
	 * @return
	 * 	Reference to iterator after decrementation.
	 */
	RuntimeArrayConstantIterator &operator--(){
		--m_current;
		return *this;
	}

	/**
	 * @brief
	 * 	Returns current iterator, then moves to previous object.
	 *
	 * @param dummy
	 * 	Dummy argument.
	 *
	 * @return
	 * 	Iterator before decrementation.
	 */
	RuntimeArrayConstantIterator operator--(int dummy){
		auto tmp = *this;
		--m_current;
		return tmp;
	}

	/**
	 * @brief
	 * 	Sets position of iterator at beginning of given array.
	 *
	 * @param array
	 * 	RuntimeArray to iterate.
	 */
	void setAtBeginning(const RuntimeArray<T> &array);

	/**
	 * @brief
	 * 	Sets position of iterator at end of given array.
	 *
	 * @param array
	 * 	RuntimeArray to iterate.
	 */
	void setAtEnd(const RuntimeArray<T> &array);

private:
	/**
	 * @brief
	 * 	Pointer storing current object.
	 */
	typename Base::PointerType m_current = nullptr;
};

/**
 * @brief
 * 	Array with size defined at runtime.
 */
template<class T>
class RuntimeArray {
public:
	friend RuntimeArrayIterator<T>;
	friend RuntimeArrayConstantIterator<T>;

	using Iterator = RuntimeArrayIterator<T>;
	using ConstantIterator = RuntimeArrayConstantIterator<T>;

	/**
	 * @brief
	 * 	Constructs array from initializer list.
	 *
	 * @param initializer
	 * 	Initializer list from which array is to be constructed.
	 */
	RuntimeArray(const std::initializer_list<T> &initializer) : RuntimeArray(initializer.size()){
		std::copy(initializer.begin(), initializer.end(), begin());
	}

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
	RuntimeArray(const T *array, size_t size) : RuntimeArray(size){
		if(m_size && m_array) std::copy(array, array + size, m_array);
	}

	/**
	 * @brief
	 * 	Simple copy constructor.
	 *
	 * @param array
	 * 	Auto-array to be copied.
	 */
	RuntimeArray(const RuntimeArray &array) : RuntimeArray(array.cStyleArray(), array.length()){}

	/**
	 * @brief
	 * 	Simple move constructor.
	 *
	 * @param array
	 * 	Array to move.
	 */
	RuntimeArray(RuntimeArray &&array) : m_size{array.m_size}, m_array{array.m_array}{
		array.m_array = nullptr;
	}

	/**
	 * @brief
	 * 	Destructor freeing memory.
	 */
	~RuntimeArray() noexcept{ if(m_array) delete[] m_array; }

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
	 * 	Function returning begin iterator.
	 *
	 * @return
	 * 	Iterator pointing at first element.
	 */
	Iterator begin() noexcept{
		Iterator it{};
		it.setAtBeginning(*this);
		return it;
	}

	/**
	 * @brief
	 * 	Function returning begin iterator.
	 *
	 * @return
	 * 	Iterator pointing at first element.
	 */
	ConstantIterator begin() const noexcept{
		ConstantIterator it{};
		it.setAtBeginning(*this);
		return it;
	}

	/**
	 * @brief
	 * 	Function returning end iterator.
	 *
	 * @return
	 * 	Iterator pointing at element behind last one.
	 */
	Iterator end() noexcept{
		Iterator it{};
		it.setAtEnd(*this);
		return it;
	}

	/**
	 * @brief
	 * 	Function returning end iterator.
	 *
	 * @return
	 * 	Iterator pointing at element behind last one.
	 */
	ConstantIterator end() const noexcept{
		ConstantIterator it{};
		it.setAtEnd(*this);
		return it;
	}
private:
	/**
	 * @brief
	 * 	Size of stored array.
	 */
	size_t m_size = 0;

	/**
	 * @brief
	 * 	Pointer to stored array.
	 */
	T *m_array = nullptr;
};

template<class T>
void RuntimeArrayIterator<T>::setAtBeginning(const RuntimeArray<T> &array){
	m_current = array.m_array;
}

template<class T>
void RuntimeArrayIterator<T>::setAtEnd(const RuntimeArray<T> &array){
	m_current = array.m_array + array.m_size;
}

template<class T>
void RuntimeArrayConstantIterator<T>::setAtBeginning(
		const RuntimeArray<T> &array){
	m_current = array.m_array;
}

template<class T>
void RuntimeArrayConstantIterator<T>::setAtEnd(
		const RuntimeArray<T> &array){
	m_current = array.m_array + array.m_size;
}

//Definitions of forward declared functions
template<class Iterator, class>
Iterator &operator+=(
		Iterator &lhs,
		typename Iterator::DifferenceType rhs){
	lhs.m_current += rhs;
	return lhs;
}

template<class Iterator, class>
Iterator &operator-=(
		Iterator &lhs,
		typename Iterator::DifferenceType rhs){
	lhs.m_current -= rhs;
	return lhs;
}

template<class Iterator, class>
Iterator operator+(
		const Iterator &lhs,
		typename Iterator::DifferenceType rhs){
	auto tmp = lhs;
	return lhs += rhs;
}

template<class Iterator, class>
Iterator operator-(
		const Iterator &lhs,
		typename Iterator::DifferenceType rhs){
	auto tmp = lhs;
	return lhs -= rhs;
}

template<class Iterator, class>
typename Iterator::DifferenceType operator-(
		const Iterator &lhs,
		const Iterator &rhs){
	return lhs.m_current - rhs.m_current;
}

template<class Iterator, class>
bool operator==(
		const Iterator &lhs,
		const Iterator &rhs){
	return lhs.m_current == rhs.m_current;
}

template<class Iterator, class>
bool operator!=(
		const Iterator &lhs,
		const Iterator &rhs){
	return lhs.m_current != rhs.m_current;
}

template<class Iterator, class>
bool operator>(
		const Iterator &lhs,
		const Iterator &rhs){
	return lhs.m_current > rhs.m_current;
}

template<class Iterator, class>
bool operator<(
		const Iterator &lhs,
		const Iterator &rhs){
	return lhs.m_current < rhs.m_current;
}

template<class Iterator, class>
bool operator>=(
		const Iterator &lhs,
		const Iterator &rhs){
	return lhs.m_current >= rhs.m_current;
}

template<class Iterator, class>
bool operator<=(
		const Iterator &lhs,
		const Iterator &rhs){
	return lhs.m_current <= rhs.m_current;
}

} /* namespace tech */
} /* namespace coma */

#endif /* UTILITY_RUNTIMEARRAY_H_ */
