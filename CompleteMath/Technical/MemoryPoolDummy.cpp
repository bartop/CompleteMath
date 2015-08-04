/*
 * MemoryPoolDummy.cpp
 *
 *  Created on: 3 sie 2015
 *      Author: Bartosz Miera
 */

#include "MemoryPoolDummy.h"

namespace coma {
namespace tech {

MemoryPoolDummy::~MemoryPoolDummy() {
}

void *const MemoryPoolDummy::allocate(const std::size_t size){
	return new char[size]{};
}

void MemoryPoolDummy::deallocate(void *const toDealloc){
	delete[] static_cast<char *const>(toDealloc);
}

MemoryPoolDummy memoryPoolDummy{};

} /* namespace tech */
} /* namespace coma */
