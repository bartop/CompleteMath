/*
 * RealNumber.cpp
 *
 *  Created on: 1 lip 2015
 *      Author: Bartosz Miera
 */

#include "RealNumber.h"
#include "Integer.h"
#include "FloatingPoint.h"

#include <memory>

namespace coma {
namespace numb {

Pointer<RealNumber> RealNumber::fromBinaryInString(const std::string &binary){
	if(std::find(binary.begin(), binary.end(), '.') == binary.end()){
		return Integer::fromBinaryInString(binary);
	}else{
		return FloatingPoint::fromBinaryFloatInString(binary);
	}
}

Pointer<RealNumber> RealNumber::fromOctalInString(const std::string &octal){
	if(std::find(octal.begin(), octal.end(), '.') == octal.end()){
		return Integer::fromOctalInString(octal);
	}else{
		return FloatingPoint::fromOctalFloatInString(octal);
	}
}

Pointer<RealNumber> RealNumber::fromDecimalInString(const std::string &decimal){
	if(std::find(decimal.begin(), decimal.end(), '.') == decimal.end()){
		return Integer::fromDecimalInString(decimal);
	}else{
		return FloatingPoint::fromDecimalFloatInString(decimal);
	}
}

Pointer<RealNumber> RealNumber::fromHexadecimalInString(const std::string &hex){
	if(std::find(hex.begin(), hex.end(), '.') == hex.end()){
		return Integer::fromHexadecimalInString(hex);
	}else{
		return FloatingPoint::fromHexadecimalFloatInString(hex);
	}
}

CompareResult RealNumber::compare(const Pointer<RealNumber> toCompare) const{
	Pointer<RealNumber> diff = staticPointerCast<RealNumber>(
			static_cast<const coma::core::Arithmetic<Pointer<Number>> *>(this)->getDifference(toCompare));
	if(diff->isPositive()) return CompareResult::ThisGreater;
	else if(diff->isZero()) return CompareResult::Equal;
	else return CompareResult::ThisLesser;
}

Pointer<Number> RealNumber::getAbsoluteValue() const{
	if(isNegative()) return this->getNegation();
	else return this->copy();
}


} /* namespace numb */
} /* namespace coma */
