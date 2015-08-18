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
unsigned char *arrayFromHexadecimal(const std::string &hex);

/**
 * @brief
 *	Creates array of chars from hexadecimal in string.
 *
 * @param hex
 * 	Hexadecimal with sign in string to be converted to char array.
 *
 * @return
 * 	Unsigned char array representing number stored in string. For negative values 2 complement is used.
 */
unsigned char *arrayFromSignedHexadecimal(const std::string &hex);

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
 * 	Finds the size of array that can hold given hexadecimal value.
 *
 * @param hex
 * 	Signed number in string.
 *
 * @return
 * 	Size of array that can hold given hexadecimal value.
 */
const unsigned long long sizeFromSignedHexadecimal(const std::string &hex);

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
void fillArrayfromHexadecimal(const std::string &hexadecimal, unsigned char *array, const unsigned long long size);

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
void shiftArrayLeft(unsigned char *toShift, const unsigned long long size);

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
void addArray(unsigned char *toAdd1, const unsigned long long size1,
		const unsigned char *toAdd2, const unsigned long long size2);

/**
 * @brief
 * 	Changes number in array to its 2-complement negation.
 *
 * @param toNegate
 * 	Array to be negated.
 *
 * @param size
 * 	Size of given array.
 */
void negateArray(unsigned char *toNegate, const unsigned long long size);

/**
 * @brief
 *	Adds @c right value to @c left in place.
 *
 * @param left
 * 	Variable storing first argument and result of addition.
 *
 * @param right
 * 	Variable storing second argument.
 *
 * @param carry
 * 	Tells if carry will be added to left in this and next operation.
 */
inline void addWithCarry(unsigned char &left, const unsigned char right, unsigned char &carry){
	left += carry;
	if(left < carry) carry = 1;
	else carry = 0;

	left += right;
	if(left < right) carry = 1;
}

/**
 * @brief
 * 	Subtracts @c right from @c left in place. Uses and produces borrow if needed.
 *
 * @param left
 *	Number from which @c right is subtracted.
 *
 * @param right
 * 	Number which is being subtracted.
 *
 * @param borrow
 * 	Tells if borrow will be used in this and next subtraction.
 */
inline void subtractWithBorrow(unsigned char &left, const unsigned char right, unsigned char &borrow){
	if(left < borrow){
		left -= borrow;
		borrow = 1;
	}
	else{
		left -= borrow;
		borrow = 0;
	}

	if(left < right) borrow = 1;
	left -= right;
}

}
}
}
#endif /* UTILITY_NUMBERS_H_ */
