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
		public IntegerArithmetic<Signed, Integer>,
		public Comparable<Signed>,
		public Arithmetic<Signed, Number>,
		public Comparable<Unsigned>,
		public Arithmetic<Unsigned, Number>{
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
	const unsigned char *const arrayCopy(const unsigned char *const toCopy,
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
	virtual const CompareResult compare(const RealNumber *const toCompare) const override;
	virtual const CompareResult compare(const FloatingPoint *const toCompare) const override;

	/**
	 * @{
	 */

	virtual Number *const getSum(const RealNumber *const toAdd) const override;
	virtual Number *const getDifference(const RealNumber *const toSubtract) const override;
	virtual Number *const getProduct(const RealNumber *const toMultiply) const override;
	virtual Number *const getQuotient(const RealNumber *const toDivide) const override;
	virtual Number *const getDifferenceNegation(const RealNumber *const minuend) const override;
	virtual Number *const getQuotientInverse(const RealNumber *const dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *const getSum(const FloatingPoint *const toAdd) const override;
	virtual Number *const getDifference(const FloatingPoint *const toSubtract) const override;
	virtual Number *const getProduct(const FloatingPoint *const toMultiply) const override;
	virtual Number *const getQuotient(const FloatingPoint *const toDivide) const override;
	virtual Number *const getDifferenceNegation(const FloatingPoint *const minuend) const override;
	virtual Number *const getQuotientInverse(const FloatingPoint *const dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @brief
	 *	Destructor deleting allocated memory.
	 */
	virtual ~Integer();
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_INTEGER_H_ */
