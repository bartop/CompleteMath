/*
 * Numbers.h
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef UTILITY_NUMBERS_H_
#define UTILITY_NUMBERS_H_

#include <algorithm>
#include "../numbers/Number.h"

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
	number.erase(0, number.find_first_not_of("0"));
	if(number == "") number = "0";
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
 * 	Adds in place @c toAdd2 to @c toAdd1.
 *
 * @param toAdd1
 * 	First addition component and array containing result of addition.
 *
 * @param size1
 * 	Size of first component.
 *
 * @param toAdd2
 * 	Second addition component.
 *
 * @param size2
 *  Size of second component.
 */
void addArray(unsigned char *const toAdd1, const unsigned long long size1,
		const unsigned char *const toAdd2, const unsigned long long size2);

/**
 * @brief
 * 	Changes number in array to its 2-complement negation.
 *
 * @param toShift
 * 	Array to be negated.
 *
 * @param size
 * 	Size of given array.
 */
void negateArray(unsigned char *const toNegate, const unsigned long long size);

/**
 * @brief
 * 	Subtracts @c left array from @c right one.
 *
 * @param left
 *	Left operand of subtraction and the numbers difference.
 *
 * @param sizeLeft
 * 	Size of @c left array.
 *
 * @param right
 * 	Right operand of subtraction.
 *
 * @param sizeRight
 * 	Size of @c right array.
 */
void subtractArray(unsigned char *const left, const unsigned long long sizeLeft,
		const unsigned char *const right, const unsigned long long sizeRight);

/**
 * @brief
 * 	Returns minimal number of bytes that can store given number in array.
 *
 * @param array
 * 	Array to be checked for unused bytes.
 *
 * @param maxSize
 * 	Allocated size of @c array.
 *
 * @param negative
 * 	For @c true most significant bytes equal to unsigned char(-1) are removed.
 * 	For @c false most significant bytes equal to 0 are removed.
 */
const unsigned long long getUsedBytes(const unsigned char *const array, const unsigned long long maxSize, const bool negative = false);

}
}
}
#endif /* UTILITY_NUMBERS_H_ */
