/*
 * RealNumber.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_REALNUMBER_H_
#define NUMBERS_REALNUMBER_H_

#include "../coreInterfaces/Comparable.h"
#include "Number.h"

namespace coma {
namespace numb {

typedef core::CompareResult CompareResult;

/**
 * @brief
 * 	Interface for real numbers.
 */
class RealNumber:
		public Number,
		public core::Comparable<RealNumber>{
public:
	/**
	 * @brief
	 * 	Creates RealNumber from given number. Automatically chooses type.
	 *
	 * @param binary
	 * 	Binary number in string.
	 *
	 * @return
	 * 	Pointer to RealNumber containing given number.
	 */
	static RealNumber *const fromBinaryInString(const std::string &binary);

	/**
	 * @brief
	 * 	Creates RealNumber from given number. Automatically chooses type.
	 *
	 * @param octal
	 * 	Octal number in string.
	 *
	 * @return
	 * 	Pointer to RealNumber containing given number.
	 */
	static RealNumber *const fromOctalInString(const std::string &octal);

	/**
	 * @brief
	 * 	Creates RealNumber from given number. Automatically chooses type.
	 *
	 * @param decimal
	 * 	Decimal number in string.
	 *
	 * @return
	 * 	Pointer to RealNumber containing given number.
	 */
	static RealNumber *const fromDecimalInString(const std::string &decimal);

	/**
	 * @brief
	 * 	Creates RealNumber from given number. Automatically chooses type.
	 *
	 * @param hex
	 * 	Hexadecimal number in string.
	 *
	 * @return
	 * 	Pointer to RealNumber containing given number.
	 */
	static RealNumber *const fromHexadecimalInString(const std::string &hex);

	/**
	 * @brief
	 * 	Method to check if stored value is positive or negative.
	 *
	 * @details
	 * 	0 (zero) is treated as neither positive nor negative value.
	 *
	 * @return
	 * 	True if stored value is negative.
	 * 	False if stored value is non-negative.
	 */
	virtual const bool isNegative() const = 0;

	/**
	 * @brief
	 * 	Method to check if stored value is positive or positive.
	 *
	 * @copydetails isNegative()
	 *
	 * @return
	 * 	True if stored value is positive.
	 * 	False if stored value is non-positive.
	 */
	virtual const bool isPositive() const = 0;

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~RealNumber(){}

	virtual const CompareResult compare(const RealNumber *const toCompare) const override;
	virtual Number *const getAbsoluteValue() const override;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_REALNUMBER_H_ */
