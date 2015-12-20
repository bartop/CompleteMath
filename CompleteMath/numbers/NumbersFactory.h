/*
 * NumbersFactory.h
 *
 *  Created on: 4 paü 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_NUMBERSFACTORY_H_
#define NUMBERS_NUMBERSFACTORY_H_

#include <map>
#include <memory>
#include <functional>

#include "../coreInterfaces/Uncreatable.h"
#include "typedefs.h"

namespace coma {
namespace numb {

class Number;

/**
 * @brief
 *	Factory class for Number and derived classes.
 */
class NumbersFactory{
public:
	using map_type = std::map<std::string, Pointer<const Number>>;
	using clean_strategy_type = std::function<bool(const map_type &)>;

	Pointer<const Number> createNumber(std::string numberInString) const;
	void cleanMap() const;

	void setCleanStrategy(clean_strategy_type clearStrategy);
private:
	mutable map_type m_numberMap;
	clean_strategy_type m_cleanStrategy = [](const map_type &){ return true; };
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_NUMBERSFACTORY_H_ */
