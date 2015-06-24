/*
 * RealNumber.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_REALNUMBER_H_
#define NUMBERS_REALNUMBER_H_

#include "Comparable.h"
#include "Number.h"

namespace cm {
namespace numb {

/**
 * @brief
 * 	Class representing real numbers.
 */
class RealNumber: public Number, public Comparable<RealNumber> {
public:
	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~RealNumber(){}
};

} /* namespace numb */
} /* namespace cm */

#endif /* NUMBERS_REALNUMBER_H_ */
