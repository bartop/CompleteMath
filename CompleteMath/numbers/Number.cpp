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
	if(!toCompare) REPORT_ERROR(std::exception("Null pointer exception"), false);
	std::unique_ptr<Number> diff{ this->getDifference(toCompare) };
	return diff->isZero();
}

Number *Number::getDifference(const Number *toSubtract) const{
	if(!toSubtract) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	std::unique_ptr<Number> negation { toSubtract->getNegation() };
	return negation->getSum(this);
}

Number *Number::getQuotient(const Number *toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	std::unique_ptr<Number> inversion { toDivide->getInversion() };
	return this->getQuotient(inversion.get());
}

const Unsigned *Number::ZERO() noexcept{
	return static_cast<const Unsigned *>(additionNeutralElement());
}

const Unsigned *Number::ONE() noexcept{
	return static_cast<const Unsigned *>(multiplicationNeutralElement());
}
}
}
