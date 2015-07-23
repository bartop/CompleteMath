/*
 * Integer.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_INTEGER_H_
#define NUMBERS_INTEGER_H_

#include "RealNumber.h"
#include "IntegerArithmetic.h"
#include "../Utility/RuntimeArray.h"

namespace coma {
namespace numb {

/**
 * @brief
 * 	Enum defining if array of bytes stores number in little- or big-endian manner
 */
enum class Endianess{
	Little,//!< Little little-endian form
	Big    //!< Big big-endian form
};

class Unsigned;
class Signed;

/**
 * @brief
 * 	Interface for integer values.
 */
class Integer:
		public RealNumber,
		public IntegerArithmetic<Integer>,
		public IntegerArithmetic<Unsigned, Integer>,
		public IntegerArithmetic<Signed, Integer>{
private:
	/**
	 * @brief
	 * 	Array storing very long unsigned.
	 */
	const util::RuntimeArray<unsigned char> m_integer;

protected:
	/**
	 * @brief
	 * 	Constructs Integer from array of unsigned chars.
	 *
	 * @param numbersArray
	 *	Array of bytes containing long number.

	 * @param endianess
	 * 	Defines if given number in array uses big- or little-endian notation.
	 */
	explicit Integer(const util::RuntimeArray<unsigned char> numbersArray, const Endianess endianess = Endianess::Little);

	/**
	 * @brief
	 * 	Array getter.
	 *
	 * @return
	 * 	Stored array.
	 */
	const util::RuntimeArray<unsigned char> &getArray() const;

public:
	/**
	 * @brief
	 * 	Creates Integer from given array.
	 *
	 * @param array
	 * 	Array representing number in 256-based number system. The number is stored in little-endian manner.
	 *
	 * @param asSigned
	 * 	Tells if array should be interpreted as singed or unsigned number.
	 *
	 * @return
	 * 	New Integer based on passed array.
	 */
	static Integer *const fromLittleEndianArray(const util::RuntimeArray<unsigned char> &array, bool asSigned = false);

	/**
	 * @brief
	 * 	Creates Integer from given array.
	 *
	 * @param array
	 * 	Array representing number in 256-based number system. The number is stored in big-endian manner.
	 *
	 * @param asSigned
	 * 	Tells if array should be interpreted as singed or unsigned number.
	 *
	 * @return
	 * 	New Integer based on passed array.
	 */
	static Integer *const fromBigEndianArray(const util::RuntimeArray<unsigned char> &array, bool asSigned = false);

	/**
	 * @brief
	 * 	Creates Integer containing given number.
	 *
	 * @param binary
	 * 	Binary number in string.
	 *
	 * @return
	 * 	New Integer based on given number in string.
	 */
	static Integer *const fromBinaryInString(const std::string &binary);

	/**
	 * @brief
	 * 	Creates Integer containing given number.
	 *
	 * @param binary
	 * 	Octal number in string.
	 *
	 * @return
	 * 	New Integer based on given number in string.
	 */
	static Integer *const fromOctalInString(const std::string &octal);

	/**
	 * @brief
	 * 	Creates Integer containing given number.
	 *
	 * @param binary
	 * 	Decimal number in string.
	 *
	 * @return
	 * 	New Integer based on given number in string.
	 */
	static Integer *const fromDecimalInString(const std::string &decimal);

	/**
	 * @brief
	 * 	Creates Integer containing given number.
	 *
	 * @param binary
	 * 	Hexadecimal number in string.
	 *
	 * @return
	 * 	New Integer based on given number in string.
	 */
	static Integer *const fromHexadecimalInString(const std::string &hex);

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~Integer(){}
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_INTEGER_H_ */
