/*
 * FloatingPoint.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_FLOATINGPOINT_H_
#define NUMBERS_FLOATINGPOINT_H_

#include "RealNumber.h"

namespace coma {
namespace numb {

class Signed;
class Unsigned;
class Integer;

class FloatingPoint final: public RealNumber {

	const Integer *const m_numerator = nullptr;
	const Unsigned *const m_denominator = nullptr;
	const Integer *const m_power = nullptr;

public:
	//======================================
	//------------FLOATINGPOINT-------------
	//======================================

	/**
	 * @brief
	 * 	Creates new FloatingPoint from fraction of Integers.
	 *
	 * @details
	 * 	The value is calculated from formula:
	 * 		@a numerator/@a denominator * 256^@a power.
	 *
	 * @param numerator
	 * 	Numerator of fraction.
	 *
	 * @param denominator
	 * 	Denominator of fraction.
	 *
	 * @param power
	 * 	Power in formula given in details.
	 *
	 * @return
	 *	New FloatingPoint based on given formula and arguments.
	 */
	static FloatingPoint *const fromFraction(const Integer *const numerator,
			const Integer *const denominator,
			const Integer *const power);
	/**
	 * @brief
	 * 	Creates new FloatingPoint from binary numbers given in strings.
	 *
	 * @param numerator
	 * 	Numerator of created fraction.
	 *
	 * @param denominator
	 * 	Denominator of created fraction.
	 *
	 * @return
	 * 	New FloatingPoint based on given numbers.
	 */
	static FloatingPoint *const fromBinaryFractionInStrings(const std::string &numerator,
			const std::string &denominator);

	/**
	 * @brief
	 * 	Creates new FloatingPoint from decimal numbers given in strings.
	 *
	 * @param numerator
	 * 	Numerator of created fraction.
	 *
	 * @param denominator
	 * 	Denominator of created fraction.
	 *
	 * @return
	 * 	New FloatingPoint based on given numbers.
	 */
	static FloatingPoint *const fromOctalFractionInStrings(const std::string &numerator,
			const std::string &denominator);

	/**
	 * @brief
	 * 	Creates new FloatingPoint from decimal numbers given in strings.
	 *
	 * @param numerator
	 * 	Numerator of created fraction.
	 *
	 * @param denominator
	 * 	Denominator of created fraction.
	 *
	 * @return
	 * 	New FloatingPoint based on given numbers.
	 */
	static FloatingPoint *const fromDecimalFractionInStrings(const std::string &numerator,
				const std::string &denominator);

	/**
	 * @brief
	 * 	Creates new FloatingPoint from decimal numbers given in strings.
	 *
	 * @param numerator
	 * 	Numerator of created fraction.
	 *
	 * @param denominator
	 * 	Denominator of created fraction.
	 *
	 * @return
	 * 	New FloatingPoint based on given numbers.
	 */
	static FloatingPoint *const fromHexadecimalFractionInStrings(const std::string &numerator,
			const std::string &denominator);

	/**
	 * @brief
	 * 	Constructs FloatingPoint from string containing float written in hexadecimal system.
	 *
	 * @param flaot
	 * 	String containing float. Dot is valid delimiter.
	 *
	 * @return
	 * 	New FloatingPoint containing given number in string.
	 */
	static FloatingPoint *const fromBinaryFloatInString(const std::string &flaot);

	/**
	 * @brief
	 * 	Constructs FloatingPoint from string containing float written in hexadecimal system.
	 *
	 * @param flaot
	 * 	String containing float. Dot is valid delimiter.
	 *
	 * @return
	 * 	New FloatingPoint containing given number in string.
	 */
	static FloatingPoint *const fromOctalFloatInString(const std::string &flaot);

	/**
	 * @brief
	 * 	Constructs FloatingPoint from string containing float written in hexadecimal system.
	 *
	 * @param flaot
	 * 	String containing float. Dot is valid delimiter.
	 *
	 * @return
	 * 	New FloatingPoint containing given number in string.
	 */
	static FloatingPoint *const fromDecimalFloatInString(const std::string &flaot);

	/**
	 * @brief
	 * 	Constructs FloatingPoint from string containing float written in hexadecimal system.
	 *
	 * @param flaot
	 * 	String containing float. Dot is valid delimiter.
	 *
	 * @return
	 * 	New FloatingPoint containing given number in string.
	 */
	static FloatingPoint *const fromHexadecimalFloatInString(const std::string &flaot);

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~FloatingPoint();

	//======================================
	//--------------COPYABLE----------------
	//======================================

	virtual Number *const copy() const override;

	//======================================
	//-------------ARITHMETIC---------------
	//======================================
	/**
	 * @{
	 */

	virtual Number *const getSum(const Number *const toAdd) const override;
	virtual Number *const getSum(const Complex *const toAdd) const override;
	virtual Number *const getSum(const FloatingPoint *const toAdd) const override;
	virtual Number *const getSum(const Signed *const toAdd) const override;
	virtual Number *const getSum(const Unsigned *const toAdd) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *const getProduct(const Number *const toMultiply) const override;
	virtual Number *const getProduct(const Complex *const toMultiply) const override;
	virtual Number *const getProduct(const FloatingPoint *const toMultiply) const override;
	virtual Number *const getProduct(const Signed *const toMultiply) const override;
	virtual Number *const getProduct(const Unsigned *const toMultiply) const override;

	/**
	 * @}
	 */

	//======================================
	//---------------NUMBER-----------------
	//======================================

	virtual const bool isZero() const override;

	/**
	 * @{
	 */

	virtual const std::string getAsBinary() const override;
	virtual const std::string getAsOctal() const override;
	virtual const std::string getAsDecimal() const override;
	virtual const std::string getAsHexadecimal() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 *
	 */

	virtual Unsigned *const getAsUnsignedInteger() const override;
	virtual Signed *const getAsSignedInteger() const override;
	virtual FloatingPoint *const getAsFloatingPoint() const override;
	virtual Complex *const getAsComplex() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *const getNegation() const override;
	virtual Number *const getInversion() const override;

	/**
	 * @}
	 */

	//======================================
	//-------------REALNUMBER---------------
	//======================================

	/**
	 * @{
	 */

	virtual const bool isNegative() const override;
	virtual const bool isPositive() const override;

	/**
	 * @}
	 */

private:
	/**
	 * @brief
	 * 	Creates floating point number as quotient of two integers.
	 *
	 * @details
	 * 	The number is stored in unusual kind of way: (numerator/denominator) * 256^power.
	 *
	 * @param numerator
	 * 	Numerator of real number.
	 *
	 * @param denominator
	 * 	Denominator of desired real number.
	 *
	 * @param power
	 *	Power in formula given above.
	 */
	FloatingPoint(const Integer *const numerator, const Unsigned *const denominator, const Integer *const power);

	static FloatingPoint *const fromFloat(const std::string &number,
			const std::string &base,
			const std::function<Integer *const(const std::string &)> &numeratorCreator);

};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_FLOATINGPOINT_H_ */
