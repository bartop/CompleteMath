/*
 * math.h
 *
 *  Created on: 28 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_MATH_H_
#define NUMBERS_MATH_H_

#include "Integer.h"

namespace coma {
namespace numb {
/**
 * @brief
 * 	Finds greatest common divisor of given Integers.
 *
 * @param numberOne
 * 	First number.
 *
 * @param numberTwo
 * 	Second number.
 *
 * @return
 * 	Greatest common divisor of @a numberOne and @a numberTwo.
 */
Integer *getGCD(const Integer *numberOne, const Integer *numberTwo);

/**
 * @brief
 * 	Finds least common multiple of given Integers.
 *
 * @param numberOne
 * 	Fist number.
 *
 * @param numberTwo
 * 	Second number.
 *
 * @return
 * 	Least common multiple of @a numberOne and @a numberTwo.
 */
Integer *getLCM(const Integer *numberOne, const Integer *numberTwo);


}  // namespace numb
}  // namespace coma

#endif /* NUMBERS_MATH_H_ */
