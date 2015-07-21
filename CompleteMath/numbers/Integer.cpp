/*
 * Integer.cpp
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#include "Integer.h"
#include "FloatingPoint.h"
#include "../Utility/Numbers.h"
#include "../Utility/ArrayArithmetic.h"
#include <algorithm>
#include <memory>

namespace coma{
namespace numb{

Integer::Integer(const util::RuntimeArray<unsigned char> numbersArray, const Endianess endianess):
		m_integer{ endianess == Endianess::Little ? numbersArray : util::reverse(numbersArray) }{}

const util::RuntimeArray<unsigned char> &Integer::getArray() const{
	return m_integer;
}

}/* namespace numb */
} /* namespace coma */
