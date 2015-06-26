/*
 * Numbers.h
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef UTILITY_NUMBERS_H_
#define UTILITY_NUMBERS_H_

#include <tuple>

namespace cm{
namespace util{
namespace numb{

inline void removeLeftTrailingZeroes(std::string &hex){
	hex.erase(hex.begin(), std::find_if(hex.begin(), hex.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
}

const std::tuple<const unsigned char *const, const unsigned long long> arrayAndLengthFromHexadecimal(const std::string hex){
	std::string tmp = hex;
	removeLeftTrailingZeroes(tmp);
	unsigned long long size = tmp.length() / 2 + tmp.length() % 2;
	unsigned char *array = new unsigned char[size]{};
	return std::tuple<const unsigned char *const, const unsigned long long>(array, size);
}

}
}
}
#endif /* UTILITY_NUMBERS_H_ */
