/*
 * math.cpp
 *
 *  Created on: 29 lip 2015
 *      Author: Bartosz Miera
 */

#include "math.h"

namespace coma {
namespace numb {

Pointer<const Integer> getGCD(Pointer<const Integer> numberOne, Pointer<const Integer> numberTwo){
	Pointer<const Integer>
		one = std::static_pointer_cast<const Integer>(numberOne->getAbsoluteValue()),
		two = std::static_pointer_cast<const Integer>(numberTwo->getAbsoluteValue());
	while(!one->isZero()){
		Pointer<const Integer> tmp = one;
		one = std::static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(two)->getRemainder(tmp);
		two = tmp;
	}
	return two;
}

Pointer<const Integer> getLCM(Pointer<const Integer> numberOne, Pointer<const Integer> numberTwo){
	Pointer<const Integer> tmp = getGCD(numberOne, numberTwo);
	tmp = std::static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(
			numberOne)->getIntegerQuotient(tmp);
	tmp = std::static_pointer_cast<const Integer>(tmp->getProduct(numberTwo));
	return tmp;
}

}  // namespace numb
}  // namespace coma

