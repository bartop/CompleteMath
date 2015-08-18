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

class Integer;

class FloatingPoint final: public RealNumber {

	const Integer *m_numerator = nullptr;
	const Unsigned *m_denominator = nullptr;
	const Integer *m_power = nullptr;

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
	static FloatingPoint *fromFraction(const Integer *numerator,
			const Integer *denominator,
			const Integer *power);
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
	static FloatingPoint *fromBinaryFractionInStrings(const std::string &numerator,
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
	static FloatingPoint *fromOctalFractionInStrings(const std::string &numerator,
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
	static FloatingPoint *fromDecimalFractionInStrings(const std::string &numerator,
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
	static FloatingPoint *fromHexadecimalFractionInStrings(const std::string &numerator,
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
	static FloatingPoint *fromBinaryFloatInString(const std::string &flaot);

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
	static FloatingPoint *fromOctalFloatInString(const std::string &flaot);

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
	static FloatingPoint *fromDecimalFloatInString(const std::string &flaot);

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
	static FloatingPoint *fromHexadecimalFloatInString(const std::string &flaot);

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~FloatingPoint();

	//======================================
	//--------------COPYABLE----------------
	//======================================

	virtual Number *copy() const override;

	//======================================
	//-------------ARITHMETIC---------------
	//======================================
	/**
	 * @{
	 */

	virtual Number *getSum(const Number *toAdd) const override;
	virtual Number *getSum(const Complex *toAdd) const override;
	virtual Number *getSum(const FloatingPoint *toAdd) const override;
	virtual Number *getSum(const Signed *toAdd) const override;
	virtual Number *getSum(const Unsigned *toAdd) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *getProduct(const Number *toMultiply) const override;
	virtual Number *getProduct(const Complex *toMultiply) const override;
	virtual Number *getProduct(const FloatingPoint *toMultiply) const override;
	virtual Number *getProduct(const Signed *toMultiply) const override;
	virtual Number *getProduct(const Unsigned *toMultiply) const override;

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

	virtual Unsigned *getAsUnsignedInteger() const override;
	virtual Signed *getAsSignedInteger() const override;
	virtual FloatingPoint *getAsFloatingPoint() const override;
	virtual Complex *getAsComplex() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *getNegation() const override;
	virtual Number *getInversion() const override;

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
	FloatingPoint(const Integer *numerator, const Unsigned *denominator, const Integer *power);

	static FloatingPoint *fromFloat(const std::string &number,
			const std::string &base,
			const std::function<Integer *const(const std::string &)> &numeratorCreator);

};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_FLOATINGPOINT_H_ */
