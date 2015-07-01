/*
 * RealNumber.cpp
 *
 *  Created on: 1 lip 2015
 *      Author: Bartosz Miera
 */

#include "RealNumber.h"
#include "Complex.h"

namespace coma {
namespace numb {

Number *const RealNumber::getSum(const Number *const toAdd) const{
	return toAdd->coma::numb::Arithmetic<RealNumber, Number>::getSum(this);
}

Number *const RealNumber::getDifference(const Number *const toSubtract) const{
	return toSubtract->coma::numb::Arithmetic<RealNumber, Number>::getDifferenceNegation(this);
}

Number *const RealNumber::getProduct(const Number *const toMultiply) const{
	return toMultiply->coma::numb::Arithmetic<RealNumber, Number>::getProduct(this);
}

Number *const RealNumber::getQuotient(const Number *const toDivide) const{
	return toDivide->coma::numb::Arithmetic<RealNumber, Number>::getQuotientInverse(this);
}

Number *const RealNumber::getDifferenceNegation(const Number *const minuend) const{
	return minuend->coma::numb::Arithmetic<RealNumber, Number>::getDifference(this);
}

Number *const RealNumber::getQuotientInverse(const Number *const dividend) const{
	return dividend->coma::numb::Arithmetic<RealNumber, Number>::getQuotient(this);
}


Number *const RealNumber::getSum(const Complex *const toAdd) const{
	return toAdd->coma::numb::Arithmetic<RealNumber, Number>::getSum(this);
}

Number *const RealNumber::getDifference(const Complex *const toSubtract) const{
	return toSubtract->coma::numb::Arithmetic<RealNumber, Number>::getDifferenceNegation(this);
}

Number *const RealNumber::getProduct(const Complex *const toMultiply) const{
	return toMultiply->coma::numb::Arithmetic<RealNumber, Number>::getProduct(this);
}

Number *const RealNumber::getQuotient(const Complex *const toDivide) const{
	return toDivide->coma::numb::Arithmetic<RealNumber, Number>::getQuotientInverse(this);
}

Number *const RealNumber::getDifferenceNegation(const Complex *const minuend) const{
	return minuend->coma::numb::Arithmetic<RealNumber, Number>::getDifference(this);
}

Number *const RealNumber::getQuotientInverse(const Complex *const dividend) const{
	return dividend->coma::numb::Arithmetic<RealNumber, Number>::getQuotient(this);
}

} /* namespace numb */
} /* namespace coma */
