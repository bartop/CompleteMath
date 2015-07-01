/*
 * IntegerArithmetic.h
 *
 *  Created on: 29 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_INTEGERARITHMETIC_H_
#define NUMBERS_INTEGERARITHMETIC_H_

namespace coma {
namespace numb {

template<typename T, typename U = T>
class IntegerArithmetic {
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
	virtual U *const getIntegerQuotient(const T *const toDivide) const = 0;

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
	virtual U *const getRemainder(const T *const toDivide) const = 0;

	/**
	 * @brief
	 * 	Function to perform integer division.
	 *
	 * @param dividend
	 * 	Integer is supposed to be divided by which @c *this.
	 *
	 * @return
	 * 	Quotient of @c dividend and @c *this.
	 */
	virtual U *const getIntegerQuotientInverse(const T *const dividend) const = 0;

	/**
	 * @brief
	 * 	Function to perform mod operation.
	 *
	 * @param dividend
	 * 	Integer is supposed to be divided by which @c *this.
	 *
	 * @return
	 * 	Remainder of @c dividend and @c *this  division.
	 */
	virtual U *const getInverseRemainder(const T *const dividend) const = 0;


	virtual ~IntegerArithmetic() {}
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_INTEGERARITHMETIC_H_ */
