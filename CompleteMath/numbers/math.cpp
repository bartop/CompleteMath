/*
 * math.cpp
 *
 *  Created on: 29 lip 2015
 *      Author: Bartosz Miera
 */

#include "math.h"

namespace coma {
namespace numb {

Pointer< Integer> getGCD(Pointer< Integer> numberOne, Pointer< Integer> numberTwo){
	Pointer< Integer>
		one = std::static_pointer_cast<const Integer>(numberOne->getAbsoluteValue()),
		two = std::static_pointer_cast<const Integer>(numberTwo->getAbsoluteValue());
	while(!one->isZero()){
		Pointer< Integer> tmp = one;
		one = std::static_pointer_cast<const IntegerArithmetic<Pointer< Integer>>>(two)->getRemainder(tmp);
		two = tmp;
	}
	return two;
}

Pointer< Integer> getLCM(Pointer< Integer> numberOne, Pointer< Integer> numberTwo){
	Pointer< Integer> tmp = getGCD(numberOne, numberTwo);
	tmp = std::static_pointer_cast<const IntegerArithmetic<Pointer< Integer>>>(
			numberOne)->getIntegerQuotient(tmp);
	tmp = std::static_pointer_cast<const Integer>(tmp->getProduct(numberTwo));
	return tmp;
}

}  // namespace numb
}  // namespace coma

