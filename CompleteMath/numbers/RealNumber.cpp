/*
 * RealNumber.cpp
 *
 *  Created on: 1 lip 2015
 *      Author: Bartosz Miera
 */

#include "RealNumber.h"
#include "Complex.h"
#include <memory>

namespace coma {
namespace numb {

const CompareResult RealNumber::compare(const RealNumber *const toCompare) const{
	std::unique_ptr<RealNumber> diff { static_cast<RealNumber *>(static_cast<const coma::core::Arithmetic<Number> *>(this)->
			getDifference(toCompare)) };
	if(diff->isPositive()) return CompareResult::ThisGreater;
	else if(diff->isZero()) return CompareResult::Equal;
	else return CompareResult::ThisLesser;
}

} /* namespace numb */
} /* namespace coma */
