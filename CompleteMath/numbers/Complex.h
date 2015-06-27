/*
 * Complex.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_COMPLEX_H_
#define NUMBERS_COMPLEX_H_

#include "Number.h"

namespace coma {
namespace numb {

class Complex: public Number {
public:
	Complex();
	virtual ~Complex();
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_COMPLEX_H_ */
