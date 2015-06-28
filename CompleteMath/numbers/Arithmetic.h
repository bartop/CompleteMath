/*
 * Arithmetic.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_ARITHMETIC_H_
#define NUMBERS_ARITHMETIC_H_

namespace coma {
namespace numb {
/**
 * Interface class for objects for which arithmetical operations are possible.
 */
template<typename T, typename U = T>
class Arithmetic {
public:

	/**
	 * @brief
	 * 	Method used to add numbers.
	 *
	 * @param toAdd
	 *	Number that is supposed to be added to @c *this.
	 *
	 * @return
	 * 	Sum of @c *this and @c toAdd.
	 */
	virtual U *const getSum(const T *const toAdd) const = 0;

	/**
	 * @brief
	 * 	Method used to subtract numbers.
	 *
	 * @param toSubtract
	 *	Number that is supposed to be subtracted from @c *this.
	 *
	 * @return
	 * 	Difference between @c *this and @c toSubtract.
	 */
	virtual U *const getDifference(const T *const toSubtract) const = 0;

	/**
	 * @brief
	 * 	Method used to subtract numbers.
	 *
	 * @param minuend
	 * 	Number from which @c *this is subtracted.
	 *
	 * @return
	 * 	Difference between @c minuend and @c *this.
	 */
	virtual U *const getDifferenceNegation(const T *const minuend) const = 0;

	/**
	 * @brief
	 * 	Method used to multiply numbers.
	 *
	 * @param toMultiply
	 *	Number that is supposed to be multiplied by @c *this.
	 *
	 * @return
	 * 	Product of @c *this and @c toMultiply.
	 */
	virtual U *const getProduct(const T *const toMultiply) const = 0;

	/**
	 * @brief
	 * 	Method used to divide numbers.
	 *
	 * @param toDivide
	 * 	Number by which @c *this is supposed to be divided.
	 *
	 * @return
	 *	Quotient of @c *this and @c toDivide.
	 */
	virtual U *const getQuotient(const T *const toDivide) const = 0;

	/**
	 * @brief
	 * 	Method used to divide numbers.
	 *
	 * @param dividend
	 *  Number which is supposed to be divided by @c *this.
	 *
	 * @return
	 *	Quotient of @c dividend and @c *this.
	 */
	virtual U *const getQuotientInverse(const T *const dividend) const = 0;

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~Arithmetic(){};
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_ARITHMETIC_H_ */
