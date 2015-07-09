/*
 * Number.cpp
 *
 *  Created on: 8 lip 2015
 *      Author: Bartosz Miera
 */

#include "Number.h"
#include "Complex.h"
#include "FloatingPoint.h"
#include "Signed.h"
#include "Unsigned.h"

namespace coma{
namespace numb{

const Number *const Number::ONE = Unsigned::fromHexadecimalInString("1");

const Number *const Number::ZERO = Unsigned::fromHexadecimalInString("0");

}
}
