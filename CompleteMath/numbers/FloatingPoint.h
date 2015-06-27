/*
 * FloatingPoint.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_FLOATINGPOINT_H_
#define NUMBERS_FLOATINGPOINT_H_

#include "RealNumber.h"

namespace coma {
namespace numb {

class FloatingPoint: public coma::numb::RealNumber {
public:
	virtual ~FloatingPoint();
	FloatingPoint();
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_FLOATINGPOINT_H_ */
