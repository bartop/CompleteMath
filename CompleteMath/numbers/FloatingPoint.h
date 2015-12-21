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
	static Pointer<FloatingPoint> fromFraction(Pointer<Integer> numerator,
			Pointer<Integer> denominator,
			Pointer<Integer> power);
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
	static Pointer<FloatingPoint> fromBinaryFractionInStrings(const std::string &numerator,
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
	static Pointer<FloatingPoint> fromOctalFractionInStrings(const std::string &numerator,
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
	static Pointer<FloatingPoint> fromDecimalFractionInStrings(const std::string &numerator,
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
	static Pointer<FloatingPoint> fromHexadecimalFractionInStrings(const std::string &numerator,
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
	static Pointer<FloatingPoint> fromBinaryFloatInString(const std::string &flaot);

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
	static Pointer<FloatingPoint> fromOctalFloatInString(const std::string &flaot);

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
	static Pointer<FloatingPoint> fromDecimalFloatInString(const std::string &flaot);

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
	static Pointer<FloatingPoint> fromHexadecimalFloatInString(const std::string &flaot);

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
	FloatingPoint(Pointer<Integer> numerator, Pointer<Unsigned> denominator, Pointer<Integer> power);

	/**
	 * @brief
	 * 	Virtual destructor which frees resources.
	 */
	virtual ~FloatingPoint() noexcept;

	//======================================
	//--------------COPYABLE----------------
	//======================================

	virtual Pointer<Number> copy() const override;

	//======================================
	//-------------ARITHMETIC---------------
	//======================================
	/**
	 * @{
	 */

	virtual Pointer<Number> getSum(Pointer<Number> toAdd) const override;
	virtual Pointer<Number> getSum(Pointer<Complex> toAdd) const override;
	virtual Pointer<Number> getSum(Pointer<FloatingPoint> toAdd) const override;
	virtual Pointer<Number> getSum(Pointer<Signed> toAdd) const override;
	virtual Pointer<Number> getSum(Pointer<Unsigned> toAdd) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<Number> getProduct(Pointer<Number> toMultiply) const override;
	virtual Pointer<Number> getProduct(Pointer<Complex> toMultiply) const override;
	virtual Pointer<Number> getProduct(Pointer<FloatingPoint> toMultiply) const override;
	virtual Pointer<Number> getProduct(Pointer<Signed> toMultiply) const override;
	virtual Pointer<Number> getProduct(Pointer<Unsigned> toMultiply) const override;

	/**
	 * @}
	 */

	//======================================
	//---------------NUMBER-----------------
	//======================================

	virtual bool isZero() const noexcept override;

	/**
	 * @{
	 */

	virtual std::string getAsBinary() const override;
	virtual std::string getAsOctal() const override;
	virtual std::string getAsDecimal() const override;
	virtual std::string getAsHexadecimal() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 *
	 */

	virtual Pointer<Unsigned> getAsUnsignedInteger() const override;
	virtual Pointer<Signed> getAsSignedInteger() const override;
	virtual Pointer<FloatingPoint> getAsFloatingPoint() const override;
	virtual Pointer<Complex> getAsComplex() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<Number> getNegation() const override;
	virtual Pointer<Number> getInversion() const override;

	/**
	 * @}
	 */

	//======================================
	//-------------REALNUMBER---------------
	//======================================

	/**
	 * @{
	 */

	virtual bool isNegative() const noexcept override;
	virtual bool isPositive() const noexcept override;

	/**
	 * @}
	 */

private:

	static Pointer<FloatingPoint> fromFloat(const std::string &number,
			const std::string &base,
			const std::function<Pointer<Integer> const(const std::string &)> &numeratorCreator);

	Pointer<FloatingPoint> sharedThis() const;

	Pointer<Integer> m_numerator;
	Pointer<Unsigned> m_denominator;
	Pointer<Integer> m_power;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_FLOATINGPOINT_H_ */
