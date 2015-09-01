/*
 * Iterator.h
 *
 *  Created on: 26 sie 2015
 *      Author: Bartosz Miera
 */

#ifndef TECHNICAL_ITERATOR_H_
#define TECHNICAL_ITERATOR_H_

#include <iterator>
#include <type_traits>

namespace coma {
namespace tech {

template<class T, class = int>
struct isIterable : std::false_type{};

template<class T>
struct isIterable<T, decltype((void) T::begin, (void) T::end, 0)> : std::true_type{};

template<class T, bool = std::is_same<typename std::iterator_traits<T>::iterator_category, std::input_iterator_tag>()
		|| std::is_base_of<std::input_iterator_tag, typename std::iterator_traits<T>::iterator_category>() >
struct isInputIterator : std::false_type{};

template<class T>
struct isInputIterator<T, true> : std::true_type{};

template<class T, bool = std::is_same<typename std::iterator_traits<T>::iterator_category, std::output_iterator_tag>()
		|| std::is_base_of<std::output_iterator_tag, typename std::iterator_traits<T>::iterator_category>() >
struct isOutputIterator : std::false_type{};

template<class T>
struct isOutputIterator<T, true> : std::true_type{};

template<class T, bool = std::is_same<typename std::iterator_traits<T>::iterator_category, std::forward_iterator_tag>() >
struct isForwardIterator : std::false_type{};

template<class T>
struct isForwardIterator<T, true> : std::true_type{};

template<class T, bool = std::is_same<typename std::iterator_traits<T>::iterator_category, std::bidirectional_iterator_tag>() >
struct isBidirectionalIterator : std::false_type{};

template<class T>
struct isBidirectionalIterator<T, true> : std::true_type{};

template<class T, bool = std::is_same<typename std::iterator_traits<T>::iterator_category, std::random_access_iterator_tag>() >
struct isRandomAccessIterator : std::false_type{};

template<class T>
struct isRandomAccessIterator<T, true> : std::true_type{};

template<class CategoryTag, class Value, class Pointer = Value *, class Reference = Value &>
struct Iterator : std::iterator<CategoryTag, Value, ptrdiff_t, Pointer, Reference>{
	using ValueType = typename std::iterator<CategoryTag, Value, ptrdiff_t, Pointer, Reference>::value_type;
	using PointerType = typename std::iterator<CategoryTag, Value, ptrdiff_t, Pointer, Reference>::pointer;
	using ReferenceType = typename std::iterator<CategoryTag, Value, ptrdiff_t, Pointer, Reference>::reference;
	using DifferenceType = typename std::iterator<CategoryTag, Value, ptrdiff_t, Pointer, Reference>::difference_type;
};

}  // namespace tech
}  // namespace coma

#endif /* TECHNICAL_ITERATOR_H_ */
