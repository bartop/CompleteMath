/*
 * MemoryPoolObject.cpp
 *
 *  Created on: 3 sie 2015
 *      Author: Bartosz Miera
 */

#include "MemoryPoolObject.h"
#include "ConstantSizedMemoryPool.h"

namespace coma {
namespace tech {

MemoryPoolObject::~MemoryPoolObject(){}

void *MemoryPoolObject::operator new(std::size_t size){
	if(!m_memoryPool) setMemoryPool(getDefaultMemoryPool());
	return m_memoryPool->allocate(size);
}

void MemoryPoolObject::operator delete(void *const toDelete){
	m_memoryPool->deallocate(toDelete);
}

void MemoryPoolObject::setMemoryPool(MemoryPool &memoryPool){
	m_memoryPool = &memoryPool;
}

MemoryPool *MemoryPoolObject::m_memoryPool = nullptr;

} /* namespace tech */
} /* namespace coma */
