/*
 * Number.cpp
 *
 *  Created on: 23 cze 2015
 *      Author: Bartosz Miera
 */

#include "Number.h"

namespace cm{
namespace numb{

const Number *const Number::getDifference(const Number *const toSubtract) const{
	return this->getSum(toSubtract->getNegation());
}

const Number *const Number::getQuotient(const Number *const toDivide) const{
	return this->getProduct(toDivide->getInversion());
}

}/* namespace numb */
} /* namespace cm */
