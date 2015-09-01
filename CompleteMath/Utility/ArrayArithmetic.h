/*
 * ArrayArithmetic.h
 *
 *  Created on: 16 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef UTILITY_ARRAYARITHMETIC_H_
#define UTILITY_ARRAYARITHMETIC_H_

#include "../Technical/RuntimeArray.h"

namespace coma{
namespace util{

/**
 * @brief
 * 	Creates array of numbers without meaningless bytes.
 *
 * @param array
 * 	Array to copy inside.
 *
 * @param withSign
 * 	Tells if array contains sing or unsigned number.
 *
 * @return
 * 	Copy of given array w/o meaningless chars.
 */
const tech::RuntimeArray<unsigned char> withoutMeaninglessChars(const tech::RuntimeArray<unsigned char> &array,
		bool withSign);

/**
 * @brief
 * 	Reverses the order of elements in array.
 *
 * @param toReverse
 * 	Array to have order reversed,
 *
 * @return
 * 	New array with reversed ordering.
 */
const tech::RuntimeArray<unsigned char> reverse(const tech::RuntimeArray<unsigned char> &toReverse);

/**
 * @brief
 * 	Negates array in place.
 *
 * @param toNegate
 * 	Array to negate.
 */
void negate(tech::RuntimeArray<unsigned char> &toNegate);

/**
 * @brief
 * 	Adds numbers in arrays in place.
 *
 * @param lhs
 * 	Number to which @a right is added.
 *
 * @param rhs
 * 	Number to add.
 *
 * @return
 * 	@a lhs after addition.
 */
tech::RuntimeArray<unsigned char> &operator+=(tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);

/**
 * @brief
 * 	Adds two numbers in arrays.
 *
 * @param lhs
 * 	Left operand.
 *
 * @param rhs
 * 	Right operand.
 *
 * @return
 * 	Array containing sum.
 */
const tech::RuntimeArray<unsigned char> operator+(const tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);

/**
 * @brief
 * 	Sibtracts numbers in arrays in place.
 *
 * @param lhs
 * 	Number from which @a right is subtracted.
 *
 * @param rhs
 * 	Number to subtract.
 *
 * @return
 * 	@a lhs after subtraction.
 */
tech::RuntimeArray<unsigned char> &operator-=(tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);

/**
 * @brief
 * 	Subtracts two numbers in arrays.
 *
 * @param lhs
 * 	Left operand.
 *
 * @param rhs
 * 	Right operand.
 *
 * @return
 * 	Array containing difference.
 */
const tech::RuntimeArray<unsigned char> operator-(const tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);

/**
 * @brief
 * 	Negates number in array.
 *
 * @param array
 * 	Array to negate.
 *
 * @return
 * 	Negation of @a array.
 */
const tech::RuntimeArray<unsigned char> operator~(const tech::RuntimeArray<unsigned char> &array);

/**
 * @brief
 * 	Negates number in array.
 *
 * @param array
 * 	Array to negate.
 *
 * @return
 * 	Arithmetic negation of @a array.
 */
const tech::RuntimeArray<unsigned char> operator-(const tech::RuntimeArray<unsigned char> &array);

/**
 * @brief
 * 	Shifts elements in array left.
 *
 * @param lhs
 * 	Array to shift.
 *
 * @param rhs
 * 	Number of elements to shift.
 *
 * @return
 * 	@a lhs after shift.
 */
tech::RuntimeArray<unsigned char> &operator<<=(tech::RuntimeArray<unsigned char> &lhs, unsigned long long rhs);

/**
 * @brief
 * 	Shifts elements in array left.
 *
 * @param lhs
 * 	Array to shift.
 *
 * @param rhs
 * 	Number of elements to shift.
 *
 * @return
 * 	 New array being result of shift.
 */
const tech::RuntimeArray<unsigned char> operator<<(const tech::RuntimeArray<unsigned char> &lhs, unsigned long long rhs);

/**
 * @brief
 * 	Multiplies numbers in arrays.
 *
 * @param lhs
 * 	Left operand.
 *
 * @param rhs
 * 	Right operand.
 *
 * @return
 * 	Product of @a lhs and @a rhs stored in @a lhs.
 */
tech::RuntimeArray<unsigned char> &operator*=(tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);

/**
 * @brief
 * 	Multiplies numbers in arrays.
 *
 * @param lhs
 * 	Left operand.
 *
 * @param rhs
 * 	Right operand.
 *
 * @return
 * 	Product of @a lhs and @a rhs.
 */
const tech::RuntimeArray<unsigned char> operator*(const tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);

/**
 * @brief
 * 	Divides @a lhs by @a rhs.
 *
 * @param lhs
 * 	Dividend.
 *
 * @param rhs
 * 	Divisor.
 *
 * @return
 * 	Quotient of @a lhs and @a rhs stored in @a lhs.
 */
tech::RuntimeArray<unsigned char> &operator/=(tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);

/**
 * @brief
 * 	Divides @a lhs by @a rhs.
 *
 * @param lhs
 * 	Dividend.
 *
 * @param rhs
 * 	Divisor.
 *
 * @return
 * 	Quotient of @a lhs and @a rhs.
 */
const tech::RuntimeArray<unsigned char> operator/(const tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);

/**
 * @brief
 * 	Gets remainder of division.
 *
 * @param lhs
 * 	Dividend.
 *
 * @param rhs
 * 	Divisor.
 *
 * @return
 * 	Remainder of division stored in @a lhs.
 */
tech::RuntimeArray<unsigned char> &operator%=(tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);

/**
 * @brief
 * 	Gets remainder of division.
 *
 * @param lhs
 * 	Dividend.
 *
 * @param rhs
 * 	Divisor.
 *
 * @return
 * 	Remainder of division.
 */
const tech::RuntimeArray<unsigned char> operator%(const tech::RuntimeArray<unsigned char> &lhs, const tech::RuntimeArray<unsigned char> &rhs);
}
}

#endif /* UTILITY_ARRAYARITHMETIC_H_ */
