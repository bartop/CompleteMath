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

/**
 * @brief
 * 	Interface for integer exclusive operations.
 *
 * @tparam T
 * 	Type of arguments in methods.
 *
 * @tparam U
 * 	Type of returned values.
 */
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
	virtual U getIntegerQuotient(T toDivide) const = 0;

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
	virtual U getRemainder(T toDivide) const = 0;

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
	virtual U getIntegerQuotientInverse(T dividend) const = 0;

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
	virtual U getInverseRemainder(T dividend) const = 0;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_INTEGERARITHMETIC_H_ */
