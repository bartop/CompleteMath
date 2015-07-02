/*
 * Integer.cpp
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#include "Integer.h"
#include "FloatingPoint.h"
#include "../Utility/Numbers.h"
#include <algorithm>
#include <memory>

namespace coma{
namespace numb{

const unsigned char *const Integer::arrayCopy(const unsigned char *const toCopy,
		const unsigned long long size,
		const Endianess endianess){
	unsigned char *copy = new unsigned char[size]{};
	if(endianess == Endianess::Little){
		std::copy(toCopy, toCopy+size, copy);
	}else if(endianess == Endianess::Big){
		std::copy(std::reverse_iterator<const unsigned char *>(toCopy + size),
				std::reverse_iterator<const unsigned char *>(toCopy),
				copy);
	}
	return copy;
}

Integer::Integer(const unsigned char *const numbersArray,
		const unsigned long long arrayLength,
		const Endianess endianess):
	m_size(arrayLength),
	m_integer(arrayCopy(numbersArray, arrayLength, endianess)){}

const unsigned long long Integer::getArraySize() const{
	return m_size;
}

const unsigned char *const Integer::getArray() const{
	return m_integer;
}


const CompareResult Integer::compare(const FloatingPoint *const toCompare) const{
	return invertComparison(toCompare->coma::numb::Comparable<Integer>::compare(this));
}

Number *const Integer::getSum(const FloatingPoint *const toAdd) const{
	return toAdd->coma::numb::Arithmetic<Integer, Number>::getSum(this);
}

Number *const Integer::getDifference(const FloatingPoint *const toSubtract) const{
	return toSubtract->coma::numb::Arithmetic<Integer, Number>::getDifferenceNegation(this);
}

Number *const Integer::getProduct(const FloatingPoint *const toMultiply) const{
	return toMultiply->coma::numb::Arithmetic<Integer, Number>::getProduct(this);
}

Number *const Integer::getQuotient(const FloatingPoint *const toDivide) const{
	return toDivide->coma::numb::Arithmetic<Integer, Number>::getQuotientInverse(this);
}

Number *const Integer::getDifferenceNegation(const FloatingPoint *const minuend) const{
	return minuend->coma::numb::Arithmetic<Integer, Number>::getDifference(this);
}

Number *const Integer::getQuotientInverse(const FloatingPoint *const dividend) const{
	return dividend->coma::numb::Arithmetic<Integer, Number>::getQuotient(this);
}




const CompareResult Integer::compare(const RealNumber *const toCompare) const{
	return invertComparison(toCompare->coma::numb::Comparable<Integer>::compare(this));
}

Number *const Integer::getSum(const RealNumber *const toAdd) const{
	return toAdd->coma::numb::Arithmetic<Integer, Number>::getSum(this);
}

Number *const Integer::getDifference(const RealNumber *const toSubtract) const{
	return toSubtract->coma::numb::Arithmetic<Integer, Number>::getDifferenceNegation(this);
}

Number *const Integer::getProduct(const RealNumber *const toMultiply) const{
	return toMultiply->coma::numb::Arithmetic<Integer, Number>::getProduct(this);
}

Number *const Integer::getQuotient(const RealNumber *const toDivide) const{
	return toDivide->coma::numb::Arithmetic<Integer, Number>::getQuotientInverse(this);
}

Number *const Integer::getDifferenceNegation(const RealNumber *const minuend) const{
	return minuend->coma::numb::Arithmetic<Integer, Number>::getDifference(this);
}

Number *const Integer::getQuotientInverse(const RealNumber *const dividend) const{
	return dividend->coma::numb::Arithmetic<Integer, Number>::getQuotient(this);
}

Integer::~Integer(){
	if(m_integer) delete[] m_integer;
}

}/* namespace numb */
} /* namespace coma */
