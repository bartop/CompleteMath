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

/**
 * @brief
 * 	Enum defining if array of bytes stores number in little- or big-endian manner
 */
enum class Endianess{
	Little,//!< Little little-endian form
	Big    //!< Big big-endian form
};

/**
 * @brief
 * 	Interface for integer values.
 */
class Integer: public RealNumber {
private:
	/**
	 * @brief
	 * 	Number storing length of array.
	 */
	const unsigned long long m_size;

	/**
	 * @brief
	 * 	Array storing very long unsigned.
	 */
	const unsigned char *const m_integer;

	/**
	 * @brief
	 * 	Creates deep copy of given array.
	 *
	 * @param toCopy
	 * 	Array to copy.
	 *
	 * @param size
	 * 	Size of copied array.
	 *
	 * @param endianess
	 * 	Defines if given number in array uses big- or little-endian notation.
	 *
	 * @return
	 * 	Deep copy of the toCopy array.
	 */
	static const unsigned char *const arrayCopy(const unsigned char *const toCopy,
			const unsigned long long size,
			const Endianess endianess);

protected:
	/**
	 * @brief
	 * 	Constructs Integer from array of unsigned chars.
	 *
	 * @param numbersArray
	 *	Array of bytes containing long number.
	 *
	 * @param arrayLenght
	 * 	Length of the given array.
	 *
	 * @param endianess
	 * 	Defines if given number in array uses big- or little-endian notation.
	 */
	explicit Integer(const unsigned char *const numbersArray = nullptr,
			const unsigned long long arrayLenght = 0,
			const Endianess endianess = Endianess::Little);

	/**
	 * @brief
	 * 	Array size getter.
	 *
	 * @return
	 *	Size of stored array.
	 */
	const unsigned long long getArraySize() const;

	/**
	 * @brief
	 * 	Array getter.
	 *
	 * @return
	 * 	Stored array.
	 */
	const unsigned char *const getArray() const;

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
	virtual Integer *const getIntegerQuotient(const Integer *const toDivide) const = 0;

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
	virtual Integer *const getRemainder(const Integer *const toDivide) const = 0;

	/**
	 * @brief
	 *	Destructor deleting allocated memory.
	 */
	virtual ~Integer();
};

} /* namespace numb */
} /* namespace cm */

#endif /* NUMBERS_INTEGER_H_ */
