/*
 * Unsigned.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_UNSIGNED_H_
#define NUMBERS_UNSIGNED_H_

#include "Integer.h"

namespace cm {
namespace numb {

class Unsigned: public Integer {
private:
	/**
	 * @brief
	 * 	Array storing very long unsigned.
	 */
	const unsigned char *const m_unsigned;

	/**
	 * @brief
	 * 	Number storing length of array.
	 */
	const unsigned long long m_size;

	const unsigned char *const generate(const unsigned char *const numbersArray, const unsigned long long arrayLenght);
public:
	/**
	 * @brief
	 * 	Constructs Unsigned from decimal stored in string.
	 *
	 * @details
	 * 	This constructor does NOT check if there is a valid integer value stored in string due to O(2^n) complexity of this
	 * 	task.
	 *
	 * @param decimalInString
	 * 	Decimal integer value stored in string.
	 */
	explicit Unsigned(const NumberInString &decimalInString);

	/**
	 * @brief
	 * 	Constructs Unsigned from array of unsigned chars.
	 *
	 * @param numbersArray
	 *	Array of bytes containing long number.
	 *
	 * @param arrayLenght
	 * 	Length of the given array.
	 *
	 * @param endianess
	 * 	Enum telling if the number in array is stored in big- or little-endian manner.
	 */
	Unsigned(const unsigned char *const numbersArray = nullptr,
			const unsigned long long arrayLenght = 0,
			const Endianess endianess = Endianess::Little);

	/**
	 * @brief
	 * 	Creates new Unsigned object from big-endian byte array and returns it.
	 *
	 * @param numbersArray
	 *	Array of bytes containing long number.
	 *
	 * @param arrayLenght
	 * 	Length of the given array.
	 *
	 * @return
	 * 	New Unsigned object containing value stored in array.
	 */
	static Unsigned *const fromBigEndianArray(const unsigned char *const numbersArray = nullptr,
			const unsigned long long arrayLenght = 0);

	/**
	 * @brief
	 * 	Creates new Unsigned object from little-endian byte array and returns it.
	 *
	 * @param numbersArray
	 *	Array of bytes containing long number.
	 *
	 * @param arrayLenght
	 * 	Length of the given array.
	 *
	 * @return
	 * 	New Unsigned object containing value stored in array.
	 */
	static Unsigned *const fromLittleEndianArray(const unsigned char *const numbersArray = nullptr,
			const unsigned long long arrayLenght = 0);

	/**
	 * @brief
	 * 	Creates new Unsigned object from binary number stored in string.
	 *
	 * @param binaryInString
	 * 	Binary number stored in string.
	 *
	 * @return
	 *	New Unsigned object containing value stored string.
	 */
	static Unsigned *const fromBinaryInString(const NumberInString &binaryInString);

	/**
	 * @brief
	 * 	Creates new Unsigned object from octal number stored in string.
	 *
	 * @param octalInString
	 *	Octal number stored in string.
	 *
	 * @return
	 *	New Unsigned object containing value stored string.
	 */
	static Unsigned *const fromOctalInString(const NumberInString &octalInString);

	/**
	 * @brief
	 * 	Creates new Unsigned object from decimal number stored in string.
	 *
	 * @param decimalInString
	 * 	Decimal number stored in string.
	 *
	 * @return
	 *	New Unsigned object containing value stored string.
	 */
	static Unsigned *const fromDecimalInString(const NumberInString &decimalInString);

	/**
	 * @brief
	 * 	Creates new Unsigned object from hexadecimal number stored in string.
	 *
	 * @param hexadecimalInString
	 * 	Hexadecimal number stored in string.
	 *
	 * @return
	 *	New Unsigned object containing value stored string.
	 */
	static Unsigned *const fromHexadecimalInString(const NumberInString &hexadecimalInString);

	virtual ~Unsigned();
};

} /* namespace numb */
} /* namespace cm */

#endif /* NUMBERS_UNSIGNED_H_ */
