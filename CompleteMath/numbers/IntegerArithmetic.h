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
	 * 	Default virtual destructor.
	 */
	virtual ~IntegerArithmetic() noexcept = default;

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
	virtual U *getIntegerQuotient(const T *toDivide) const = 0;

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
	virtual U *getRemainder(const T *toDivide) const = 0;

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
	virtual U *getIntegerQuotientInverse(const T *dividend) const = 0;

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
	virtual U *getInverseRemainder(const T *dividend) const = 0;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_INTEGERARITHMETIC_H_ */
