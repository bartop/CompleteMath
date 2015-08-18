/*
 * Complex.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_COMPLEX_H_
#define NUMBERS_COMPLEX_H_

#include "Number.h"

namespace coma {
namespace numb {

class RealNumber;

class Complex final:
		public Number {
public:
	//======================================
	//--------------COMPLEX-----------------
	//======================================
	/**
	 * @brief
	 * 	Factory function creating Complex from real and imaginary part.
	 *
	 * @param real
	 * 	Real part of created Complex.
	 *
	 * @param imaginary
	 * 	Imaginary part of created Complex.
	 *
	 * @return
	 * 	New Complex with given real and imaginary part.
	 */
	static Complex *fromRealAndImaginary(const RealNumber *real, const RealNumber *imaginary);

	/**
	 * @brief
	 * 	Virtual destructor which frees resources.
	 */
	virtual ~Complex();

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

	virtual Number *getAbsoluteValue() const override;
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

private:
	const RealNumber *const m_real = nullptr;
	const RealNumber *const m_imaginary = nullptr;

	/**
	 * @brief
	 * 	Constructor copying @a real as real part and @a imaginary as imaginary part.
	 *
	 * @param real
	 * 	Real part of created Complex number.
	 *
	 * @param imaginary
	 * 	Imaginary part of created Complex number.
	 */
	Complex(const RealNumber *real, const RealNumber *imaginary);
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_COMPLEX_H_ */
