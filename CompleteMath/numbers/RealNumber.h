/*
 * RealNumber.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_REALNUMBER_H_
#define NUMBERS_REALNUMBER_H_

#include "../coreInterfaces/Comparable.h"
#include "Number.h"

namespace coma {
namespace numb {

typedef core::CompareResult CompareResult;

/**
 * @brief
 * 	Interface for real numbers.
 */
class RealNumber:
		public Number,
		public core::Comparable<RealNumber>{
public:

	/**
	 * @brief
	 * 	Method to check if stored value is positive or negative.
	 *
	 * @details
	 * 	0 (zero) is treated as neither positive nor negative value.
	 *
	 * @return
	 * 	True if stored value is negative.
	 * 	False if stored value is non-negative.
	 */
	virtual const bool isNegative() const = 0;

	/**
	 * @brief
	 * 	Method to check if stored value is positive or positive.
	 *
	 * @copydetails isNegative()
	 *
	 * @return
	 * 	True if stored value is positive.
	 * 	False if stored value is non-positive.
	 */
	virtual const bool isPositive() const = 0;

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~RealNumber(){}


	virtual const CompareResult compare(const RealNumber *const toCompare) const override;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_REALNUMBER_H_ */
