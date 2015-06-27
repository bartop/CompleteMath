/*
 * BaseConverter.cpp
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#include "BaseConverter.h"
#include <stdexcept>
#include <algorithm>


namespace coma {
namespace util {

// Arbitrary precision base conversion by Daniel Gehriger <gehriger@linkcad.com>



const char* BaseConverter::binarySet_ = "01";
const char* BaseConverter::decimalSet_ = "0123456789";
const char* BaseConverter::hexSet_ = "0123456789ABCDEF";

BaseConverter::BaseConverter(const std::string& sourceBaseSet, const std::string& targetBaseSet)
    : sourceBaseSet_(sourceBaseSet)
    , targetBaseSet_(targetBaseSet)
{
    if (sourceBaseSet.empty() || targetBaseSet.empty())
        throw std::invalid_argument("Invalid base character set");
}

const BaseConverter& BaseConverter::decimalToBinaryConverter()
{
    static const BaseConverter dec2bin(decimalSet_, binarySet_);
    return dec2bin;
}

const BaseConverter& BaseConverter::binaryToDecimalConverter()
{
    static const BaseConverter bin2dec(binarySet_, decimalSet_);
    return bin2dec;
}

const BaseConverter& BaseConverter::decimalToHexConverter()
{
    static const BaseConverter dec2hex(decimalSet_, hexSet_);
    return dec2hex;
}

const BaseConverter& BaseConverter::hexToDecimalConverter()
{
    static const BaseConverter hex2dec(hexSet_, decimalSet_);
    return hex2dec;
}

std::string BaseConverter::convert(std::string value) const
{
    unsigned int numberBase = getTargetBase();
	std::string result { };

    do
    {
        unsigned int remainder = divide(sourceBaseSet_, value, numberBase);
        result.push_back(targetBaseSet_[remainder]);
    }
    while (!value.empty() && !(value.length() == 1 && value[0] == sourceBaseSet_[0]));

    std::reverse(result.begin(), result.end());
    return result;
}

std::string BaseConverter::convert(const std::string& value, size_t minDigits) const
{
    std::string result = convert(value);
    if (result.length() < minDigits)
        return std::string(minDigits - result.length(), targetBaseSet_[0]) + result;
    else
        return result;
}

std::string BaseConverter::fromDecimal(unsigned int value) const
{
    return dec2base(targetBaseSet_, value);
}

std::string BaseConverter::fromDecimal(unsigned int value, size_t minDigits) const
{
    std::string result = fromDecimal(value);
    if (result.length() < minDigits)
        return std::string(minDigits - result.length(), targetBaseSet_[0]) + result;
    else
        return result;
}

unsigned int BaseConverter::toDecimal(std::string value) const
{
    return base2dec(sourceBaseSet_, value);
}

unsigned int BaseConverter::divide(const std::string& baseDigits, std::string& x, unsigned int y)
{
	std::string quotient { };

    size_t lenght = x.length();
    for (size_t i = 0; i < lenght; ++i)
    {
        size_t j = i + 1 + x.length() - lenght;
        if (x.length() < j)
            break;

        unsigned int value = base2dec(baseDigits, x.substr(0, j));

        quotient.push_back(baseDigits[value / y]);
        x = dec2base(baseDigits, value % y) + x.substr(j);
    }

    // calculate remainder
    unsigned int remainder = base2dec(baseDigits, x);

    // remove leading "zeros" from quotient and store in 'x'
    size_t n = quotient.find_first_not_of(baseDigits[0]);
    if (n != std::string::npos)
    {
        x = quotient.substr(n);
    }
    else
    {
        x.clear();
    }

    return remainder;
}

std::string BaseConverter::dec2base(const std::string& baseDigits, unsigned int value)
{
	unsigned int numberBase { (unsigned int) (baseDigits.length()) };
	std::string result { };
    do
    {
        result.push_back(baseDigits[value % numberBase]);
        value /= numberBase;
    }
    while (value > 0);

    std::reverse(result.begin(), result.end());
    return result;
}

unsigned int BaseConverter::base2dec(const std::string& baseDigits, const std::string& value)
{
	unsigned int numberBase { (unsigned int) (baseDigits.length()) };
	unsigned int result { 0 };
    for (size_t i = 0; i < value.length(); ++i)
    {
        result *= numberBase;
        int c = baseDigits.find(value[i]);
        if ((unsigned)c == std::string::npos)
            throw std::runtime_error("Invalid character");

        result += (unsigned int)c;
    }

    return result;
}

} /* namespace util */
} /* namespace cm */
