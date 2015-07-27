/*
 * Number.cpp
 *
 *  Created on: 8 lip 2015
 *      Author: Bartosz Miera
 */

#include "Number.h"
#include "Complex.h"
#include "FloatingPoint.h"
#include "Signed.h"
#include "Unsigned.h"

#include <memory>

namespace coma{
namespace numb{

template<>
const Number *const core::Multiplyable<Number>::NEUTRAL_ELEMENT = numb::Unsigned::fromHexadecimalInString("1");

template<>
const Number *const core::Addable<Number>::NEUTRAL_ELEMENT = numb::Unsigned::fromHexadecimalInString("0");

Number *const Number::getDifference(const Number *const toSubtract) const{
	std::unique_ptr<Number> negation { toSubtract->getNegation() };
	return negation->getSum(this);
}

Number *const Number::getQuotient(const Number *const toDivide) const{
	std::unique_ptr<Number> inversion { toDivide->getInversion() };
	return this->getQuotient(inversion.get());
}

}
}
