/*
 * Number.cpp
 *
 *  Created on: 28 cze 2015
 *      Author: Bartosz Miera
 */

#include "Number.h"
#include "Complex.h"
#include "FloatingPoint.h"
#include "Signed.h"
#include "Unsigned.h"

namespace coma{
namespace numb{

Number *const Number::getDifferenceNegation(const Number *const minuend) const{
	return minuend->coma::numb::Arithmetic<Number>::getDifference(this);
}

Number *const Number::getQuotientInverse(const Number *const dividend) const{
	return dividend->coma::numb::Arithmetic<Number>::getQuotient(this);
}

Number *const Number::getDifferenceNegation(const Complex *const minuend) const{
	return minuend->coma::numb::Arithmetic<Number>::getDifference(this);
}

Number *const Number::getQuotientInverse(const Complex *const dividend) const{
	return dividend->coma::numb::Arithmetic<Number>::getQuotient(this);
}

Number *const Number::getDifferenceNegation(const FloatingPoint *const minuend) const{
	return minuend->coma::numb::Arithmetic<Number>::getDifference(this);
}

Number *const Number::getQuotientInverse(const FloatingPoint *const dividend) const{
	return dividend->coma::numb::Arithmetic<Number>::getQuotient(this);
}

Number *const Number::getDifferenceNegation(const Signed *const minuend) const{
	return minuend->coma::numb::Arithmetic<Number>::getDifference(this);
}

Number *const Number::getQuotientInverse(const Signed *const dividend) const{
	return dividend->coma::numb::Arithmetic<Number>::getQuotient(this);
}

Number *const Number::getDifferenceNegation(const Unsigned *const minuend) const{
	return minuend->coma::numb::Arithmetic<Number>::getDifference(this);
}

Number *const Number::getQuotientInverse(const Unsigned *const dividend) const{
	return dividend->coma::numb::Arithmetic<Number>::getQuotient(this);
}

} /* namespace numb */
} /* namespace coma */


