/*
 * NumbersFactory.cpp
 *
 *  Created on: 4 paü 2015
 *      Author: Bartosz Miera
 */

#include "NumbersFactory.h"
#include "Number.h"

namespace coma {
namespace numb {

Pointer<const Number> NumbersFactory::createNumber(std::string numberInString) const{
	auto found = m_numberMap.find(numberInString);
	Pointer<const Number> ret;
	if(found == m_numberMap.end()){
		//TODO finish after Number final work
	}else{
		ret = found->second;
	}
	cleanMap();
	return ret;
}

void NumbersFactory::cleanMap() const{
	if (m_cleanStrategy(m_numberMap)){
		for(auto i : m_numberMap){
			if(i.second.unique()) m_numberMap.erase(i.first);
		}
	}
}

void NumbersFactory::setCleanStrategy(clean_strategy_type cleanStrategy){
	m_cleanStrategy = cleanStrategy;
}

} /* namespace numb */
} /* namespace coma */
