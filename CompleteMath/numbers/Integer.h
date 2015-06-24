/*
 * Integer.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_INTEGER_H_
#define NUMBERS_INTEGER_H_

#include "RealNumber.h"

namespace cm {
namespace numb {

class Integer: public RealNumber {
public:
	/**
	 * @brief
	 * 	Function to perform integer division.
	 *
	 * @param toDivide
	 * 	Integer by which @c *this is supposed to be divided by.
	 *
	 * @return
	 * 	Quotient of @c *this and @c toDivide.
	 */
	virtual const Integer *const getIntegerQuotient(const Integer *const toDivide) const = 0;

	/**
	 * @brief
	 * 	Function to perform mod operation.
	 *
	 * @param toDivide
	 * 	Integer by which @c *this is supposed to be divided by.
	 *
	 * @return
	 * 	Remainder of @c *this and @c toDivide division.
	 */
	virtual const Integer *const getRemainder(const Integer *const toDivide) const = 0;

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~Integer() {}
};

} /* namespace numb */
} /* namespace cm */

#endif /* NUMBERS_INTEGER_H_ */
