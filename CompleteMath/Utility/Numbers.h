/*
 * Numbers.h
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef UTILITY_NUMBERS_H_
#define UTILITY_NUMBERS_H_

#include <algorithm>

namespace coma{
namespace util{
namespace numb{

/**
 * @brief
 *	Removes all left trailing zeroes from number stored in string.
 *
 * @param number
 * 	Number in string from which left trailing zeroes are supposed to be deleted.
 */
inline void removeLeftTrailingZeroes(std::string &number){
	number.erase(number.begin(), std::find_if(number.begin(), number.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
}

/**
 * @brief
 *	Creates array of chars from hexadecimal in string.
 *
 * @param hex
 *	Hexadecimal in string to be converted to char array.
 *
 * @return
 * 	Unsigned char array representing number stored in string.
 */
unsigned char *const arrayFromHexadecimal(const std::string &hex);

/**
 * @brief
 * 	Finds the size of array that can hold given hexadecimal value.
 *
 * @param hex
 * 	Number in string.
 *
 * @return
 * 	Size of array that can hold given hexadecimal value.
 */
const unsigned long long sizeFromHexadecimal(const std::string &hex);

/**
 * @brief
 * 	Fills array of chars according to number stored in @c hexadecimal .
 *
 * @param hexadecimal
 * 	Number in string that is supposed to be converted to array of chars.
 *
 * @param array
 * 	Array in which value is supposed to be stored.
 *
 * @param size
 * 	Size of passed array.
 */
void fillArrayfromHexadecimal(const std::string &hexadecimal, unsigned char *const array, const unsigned long long size);

/**
 * @brief
 * 	Moves all elements in array left.
 *
 * @param toShift
 * 	Array to be shifted.
 *
 * @param size
 * 	Size of given array.
 */
void shiftArrayLeft(unsigned char *const toShift, const unsigned long long size);

/**
 * @brief
 * 	Subtracts @c left array from @c right one.
 *
 * @param left
 *	Left operand of subtraction.
 *
 * @param sizeLeft
 * 	Size of @c left array.
 *
 * @param right
 * 	Right operand of subtraction.
 *
 * @param sizeRight
 * 	Size of @c right array.
 *
 * @return
 * 	New difference array.
 */
unsigned char *const arraySubtract(const unsigned char *const left, const unsigned long long sizeLeft,
		const unsigned char *const right, const unsigned long long sizeRight);

}
}
}
#endif /* UTILITY_NUMBERS_H_ */
