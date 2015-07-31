/*
 * math.cpp
 *
 *  Created on: 29 lip 2015
 *      Author: Bartosz Miera
 */

#include "math.h"

namespace coma {
namespace numb {

Integer *const getGCD(const Integer *const numberOne, const Integer *const numberTwo){
	std::unique_ptr<Integer>
		one{ static_cast<Integer *>(numberOne->getAbsoluteValue()) },
		two{ static_cast<Integer *>(numberTwo->getAbsoluteValue()) };
	while(one->compare(two.get()) != CompareResult::Equal){
		if(one->compare(two.get()) == CompareResult::ThisGreater){
			one.reset(static_cast<Integer *>(one->getDifference(two.get())));
		}else{
			two.reset(static_cast<Integer *>(two->getDifference(one.get())));
		}
	}
	return one.release();
}

Integer *const getLCM(const Integer *const numberOne, const Integer *const numberTwo){
	std::unique_ptr<Integer> tmp { getGCD(numberOne, numberTwo) };
	tmp.reset(static_cast<const coma::numb::IntegerArithmetic<Integer> *>(numberOne)->getIntegerQuotient(tmp.get()));
	tmp.reset(static_cast<Integer *>(tmp->getProduct(numberTwo)));
	return tmp.release();
}

}  // namespace numb
}  // namespace coma

