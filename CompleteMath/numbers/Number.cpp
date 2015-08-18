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
const Number *core::Multiplyable<Number>::NEUTRAL_ELEMENT = numb::Unsigned::fromHexadecimalInString("1");

template<>
const Number *core::Addable<Number>::NEUTRAL_ELEMENT = numb::Unsigned::fromHexadecimalInString("0");

const bool Number::isEqual(const Number *toCompare) const{
	std::unique_ptr<Number> diff{ this->getDifference(toCompare) };
	return diff->isZero();
}

Number *Number::getDifference(const Number *toSubtract) const{
	std::unique_ptr<Number> negation { toSubtract->getNegation() };
	return negation->getSum(this);
}

Number *Number::getQuotient(const Number *toDivide) const{
	std::unique_ptr<Number> inversion { toDivide->getInversion() };
	return this->getQuotient(inversion.get());
}

const Unsigned *Number::ZERO(){
	return static_cast<const Unsigned *>(additionNeutralElement());
}

const Unsigned *Number::ONE(){
	return static_cast<const Unsigned *>(multiplicationNeutralElement());
}
}
}
