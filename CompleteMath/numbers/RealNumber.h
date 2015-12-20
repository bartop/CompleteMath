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
		public core::Comparable<Pointer<const RealNumber>>{
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
	static Pointer<const RealNumber> fromBinaryInString(const std::string &binary);

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
	static Pointer<const RealNumber> fromOctalInString(const std::string &octal);

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
	static Pointer<const RealNumber> fromDecimalInString(const std::string &decimal);

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
	static Pointer<const RealNumber> fromHexadecimalInString(const std::string &hex);

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
	virtual bool isNegative() const noexcept = 0;

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
	virtual bool isPositive() const noexcept = 0;

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~RealNumber(){}

	virtual CompareResult compare(const Pointer<const RealNumber> toCompare) const override;
	virtual Pointer<const Number> getAbsoluteValue() const override;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_REALNUMBER_H_ */
