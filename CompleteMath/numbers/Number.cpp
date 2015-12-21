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
Pointer<Number> core::Multiplyable<Pointer<Number>>::MULTIPLICATION_NEUTRAL_ELEMENT =
		numb::Unsigned::fromHexadecimalInString("1");

template<>
Pointer<Number> core::Addable<Pointer<Number>>::ADDITION_NEUTRAL_ELEMENT =
		numb::Unsigned::fromHexadecimalInString("0");

bool Number::isEqual(Pointer<Number> toCompare) const{
	if(!toCompare) REPORT_ERROR(std::exception("Null pointer exception"), false);
	Pointer<Number> diff = getDifference(toCompare);
	return diff->isZero();
}

Pointer<Number> Number::getDifference(Pointer<Number> toSubtract) const{
	if(!toSubtract) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toSubtract->getNegation()->getSum(shared_from_this());
}

Pointer<Number> Number::getQuotient(Pointer<Number> toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return this->getQuotient(toDivide->getInversion());
}

Pointer<Unsigned> Number::ZERO() noexcept{
	return staticPointerCast<Unsigned>(additionNeutralElement());
}

Pointer<Unsigned> Number::ONE() noexcept{
	return staticPointerCast<Unsigned>(multiplicationNeutralElement());
}
}
}
