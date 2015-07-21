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
	 * 	Dummy virtual destructor.
	 */
	virtual ~Integer(){}
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_INTEGER_H_ */
