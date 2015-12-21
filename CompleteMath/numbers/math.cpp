/*
 * math.cpp
 *
 *  Created on: 29 lip 2015
 *      Author: Bartosz Miera
 */

#include "math.h"

namespace coma {
namespace numb {

Pointer<Integer> getGCD(Pointer<Integer> numberOne, Pointer<Integer> numberTwo){
	Pointer<Integer>
		one = staticPointerCast<Integer>(numberOne->getAbsoluteValue()),
		two = staticPointerCast<Integer>(numberTwo->getAbsoluteValue());
	while(!one->isZero()){
		Pointer<Integer> tmp = one;
		one = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(two)->getRemainder(tmp);
		two = tmp;
	}
	return two;
}

Pointer<Integer> getLCM(Pointer<Integer> numberOne, Pointer<Integer> numberTwo){
	Pointer<Integer> tmp = getGCD(numberOne, numberTwo);
	tmp = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(
			numberOne)->getIntegerQuotient(tmp);
	tmp = staticPointerCast<Integer>(tmp->getProduct(numberTwo));
	return tmp;
}

}  // namespace numb
}  // namespace coma

