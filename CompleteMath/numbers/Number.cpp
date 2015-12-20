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
Pointer<const Number> core::Multiplyable<Pointer<const Number>>::MULTIPLICATION_NEUTRAL_ELEMENT =
		numb::Unsigned::fromHexadecimalInString("1");

template<>
Pointer<const Number> core::Addable<Pointer<const Number>>::ADDITION_NEUTRAL_ELEMENT =
		numb::Unsigned::fromHexadecimalInString("0");

bool Number::isEqual(Pointer<const Number> toCompare) const{
	if(!toCompare) REPORT_ERROR(std::exception("Null pointer exception"), false);
	Pointer<const Number> diff = getDifference(toCompare);
	return diff->isZero();
}

Pointer<const Number> Number::getDifference(Pointer<const Number> toSubtract) const{
	if(!toSubtract) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toSubtract->getNegation()->getSum(shared_from_this());
}

Pointer<const Number> Number::getQuotient(Pointer<const Number> toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return this->getQuotient(toDivide->getInversion());
}

Pointer<const Unsigned> Number::ZERO() noexcept{
	return std::static_pointer_cast<const Unsigned>(additionNeutralElement());
}

Pointer<const Unsigned> Number::ONE() noexcept{
	return std::static_pointer_cast<const Unsigned>(multiplicationNeutralElement());
}
}
}
