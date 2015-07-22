/*
 * ArrayArithmetic.cpp
 *
 *  Created on: 16 lip 2015
 *      Author: Bartosz Miera
 */

#include "ArrayArithmetic.h"
#include <algorithm>
#include <utility>

namespace coma{
namespace util{

namespace{
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
void addWithCarry(unsigned char &left, const unsigned char right, unsigned char &carry){
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
void subtractWithBorrow(unsigned char &left, const unsigned char right, unsigned char &borrow){
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

const int compare(const RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	unsigned long long index { std::max(lhs.length(), rhs.length()) - 1 };
	unsigned long long lower { std::min(lhs.length(), rhs.length()) - 1 };
	const RuntimeArray<unsigned char> &longer { (rhs.length() > lhs.length()) ? rhs : lhs };
	while (index > lower && longer[index] == 0){
		--index;
	}
	if(index <= lower){
		while (index > 0 && lhs[index] == rhs[index]){
			--index;
		}
		if(index != 0){
			if(lhs[index] < rhs[index]) return -1;
			else return 1;
		}else{
			if(lhs[index] == rhs[index]) return 0;
			else if(lhs[index] > rhs[index]) return 1;
			else return -1;
		}
	}else{
		return lhs.length() - rhs.length();
	}
}

}

void negate(RuntimeArray<unsigned char> &toNegate){
	RuntimeArray<unsigned char> one {1,1};
	for(unsigned long long i = 0; i < toNegate.length(); ++i){
		toNegate[i] = ~toNegate[i];
	}
	toNegate += one;
}

const RuntimeArray<unsigned char> withoutMeaninglessChars(const RuntimeArray<unsigned char> &array, bool withSign){
	unsigned long long result { array.length() };
	if(withSign){
		unsigned char mask { 0x80 };
		unsigned char sign { mask & array[array.length() - 1] };
		unsigned char meaninglessByte { sign ? 0xFF : 0};
		while(array[result - 1] == meaninglessByte && !(sign ^ (array[result - 2] & mask)) && result > 1) --result;
	}else{
		while(!array[result - 1] && result > 1) --result;
	}
	return { array.begin(), result};
}

const RuntimeArray<unsigned char> reverse(const RuntimeArray<unsigned char> &toReverse){
	RuntimeArray<unsigned char> copy = toReverse;
	for(unsigned long long i = 0; i < copy.length() / 2; ++i) std::swap(copy[i], copy[copy.length() - 1 - i]);
	return copy;
}

RuntimeArray<unsigned char> &operator+=(RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	unsigned char carry {0};
	for(unsigned long long i = 0; i < rhs.length() || (carry == 1 && i < lhs.length()); ++i){
		if(i < rhs.length()) addWithCarry(lhs[i], rhs[i], carry);
		else addWithCarry(lhs[i], 0, carry);
	}
	return lhs;
}

const RuntimeArray<unsigned char> operator+(const RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	RuntimeArray<unsigned char> result = lhs;
	result += rhs;
	return result;
}

RuntimeArray<unsigned char> &operator-=(RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	unsigned char borrow {0};
	for(unsigned long long i = 0; i < rhs.length() || (borrow == 1 && i < lhs.length()); ++i){
		if(i < rhs.length()) subtractWithBorrow(lhs[i], rhs[i], borrow);
		else subtractWithBorrow(lhs[i], 0, borrow);
	}
	return lhs;
}

const RuntimeArray<unsigned char> operator-(const RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	RuntimeArray<unsigned char> result = lhs;
	result -= rhs;
	return result;
}

const RuntimeArray<unsigned char> operator~(const RuntimeArray<unsigned char> &array){
	RuntimeArray<unsigned char> negation{ array.length() };
	for(unsigned long long i = 0; i < array.length(); ++i) negation[i] = ~array[i];
	return negation;
}

const RuntimeArray<unsigned char> operator-(const RuntimeArray<unsigned char> &array){
	RuntimeArray<unsigned char> negation{ ~array }, one{ 1, 1};
	return negation + one;
}

RuntimeArray<unsigned char> &operator<<=(RuntimeArray<unsigned char> &lhs, unsigned long long rhs){
	for(unsigned long long i = rhs; i < lhs.length(); ++i) lhs[lhs.length() - i] = lhs[lhs.length() - i - rhs];
	for(unsigned long long i = 0; i < rhs; ++i) lhs[i] = 0;
	return lhs;
}

const RuntimeArray<unsigned char> operator<<(const RuntimeArray<unsigned char> &lhs, unsigned long long rhs){
	RuntimeArray<unsigned char> copy = lhs;
	copy <<= rhs;
	return copy;
}

RuntimeArray<unsigned char> &operator*=(RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	RuntimeArray<unsigned char> table = lhs;
	std::fill(lhs.begin(), lhs.end(), 0);
	unsigned char carry { 0 };
	for(unsigned long long i = 0; i < table.length(); ++i){
		unsigned buffer { 0 };
		for(unsigned long long j = 0; j < rhs.length() && (i + j) < lhs.length() ; ++j){
			buffer = table[i] * rhs[j];
			unsigned char lower { static_cast<unsigned char>(buffer)      };
			unsigned char upper { static_cast<unsigned char>(buffer >> 8) };
			addWithCarry(lhs[i + j    ], lower, carry);
			if(lhs.length() > (i + j + 1)){
				addWithCarry(lhs[i + j + 1], upper, carry);
			}
		}
	}
	return lhs;
}

const RuntimeArray<unsigned char> operator*(const RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	RuntimeArray<unsigned char> tmp = lhs;
	tmp *= rhs;
	return tmp;
}

RuntimeArray<unsigned char> &operator/=(RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	RuntimeArray<unsigned char>
		left = lhs,
		rema { lhs.length() };
	std::fill(lhs.begin(), lhs.end(), 0);
	for(unsigned long long i = 0; i < lhs.length(); ++i){
		rema <<= 1;
		rema[0] = left[lhs.length() - 1 - i];
		bool RgeD {};
		do{
			RgeD = (compare(rema, rhs) > 0);
			if (RgeD){
				rema -= rhs;
				lhs[lhs.length() - 1 - i] += 1;
			}
		}while(RgeD);
	}
	return lhs;
}

const RuntimeArray<unsigned char> operator/(const RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	RuntimeArray<unsigned char> tmp = lhs;
	tmp /= rhs;
	return tmp;
}

RuntimeArray<unsigned char> &operator%=(RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	RuntimeArray<unsigned char>
		left = lhs,
		quot { lhs.length() };
	std::fill(lhs.begin(), lhs.end(), 0);
	for(unsigned long long i = 0; i < lhs.length(); ++i){
		lhs <<= 1;
		lhs[0] = left[quot.length() - 1 - i];
		bool RgeD {};
		do{
			RgeD = (compare(lhs, rhs) > 0);
			if (RgeD){
				lhs -= rhs;
				quot[lhs.length() - 1 - i] += 1;
			}
		}while(RgeD);
	}
	return lhs;
}

const RuntimeArray<unsigned char> operator%(const RuntimeArray<unsigned char> &lhs, const RuntimeArray<unsigned char> &rhs){
	RuntimeArray<unsigned char> copy = lhs;
	copy %= rhs;
	return copy;
}

}
}

