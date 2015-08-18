/*
 * ConstantSizedMemoryPool.cpp
 *
 *  Created on: 3 sie 2015
 *      Author: Bartosz Miera
 */

#include "ConstantSizedMemoryPool.h"
#include <algorithm>
#include <utility>

namespace coma {
namespace tech {

ConstantSizedMemoryPool::ConstantSizedMemoryPool(const size_t chunkSize = 0, const size_t chunkNumber = 0) :
		m_chunkSize{chunkSize},
		m_chunkNumber{chunkNumber}{}

ConstantSizedMemoryPool::ConstantSizedMemoryPool(const ConstantSizedMemoryPool &toCopy) :
		m_chunkSize{toCopy.m_chunkSize},
		m_chunkNumber{toCopy.m_chunkNumber},
		m_freeChunks{toCopy.m_freeChunks},
		m_usedChunks{toCopy.m_usedChunks}{
			if(toCopy.m_storedMemory){
				m_storedMemory = malloc(m_chunkNumber * m_chunkSize);
				memcpy(m_storedMemory, toCopy.m_storedMemory, m_chunkNumber * m_chunkSize);
			}
		}

ConstantSizedMemoryPool::~ConstantSizedMemoryPool() {
	if(m_storedMemory) free(m_storedMemory);
}

ConstantSizedMemoryPool &ConstantSizedMemoryPool::operator=(ConstantSizedMemoryPool toCopy){
	ConstantSizedMemoryPool tmp = toCopy;
	this->swap(toCopy);
	return *this;
}

void *ConstantSizedMemoryPool::allocate(const size_t size){
	if(!m_storedMemory) initalize();//lazy initialization
	if(size > m_chunkSize || m_freeChunks.empty()){
		return malloc(size);
	}else{
		void *ret = m_freeChunks.front();
		m_usedChunks.splice(m_usedChunks.begin(), m_freeChunks, m_freeChunks.begin());
		return ret;
	}
}

void ConstantSizedMemoryPool::deallocate(void *toDealloc){
	auto i = std::find(m_usedChunks.begin(), m_usedChunks.end(), toDealloc);
	if(i != m_usedChunks.end()){
		m_freeChunks.splice(m_freeChunks.begin(), m_usedChunks, i);
	}else{
		free(toDealloc);
	}
}

void ConstantSizedMemoryPool::initalize(){
	if(!m_chunkNumber || !m_chunkSize) return;
	m_storedMemory = malloc(m_chunkNumber * m_chunkSize);
	for(std::size_t j { 0 }; j < m_chunkNumber; ++j){
		m_freeChunks.push_back(m_storedMemory + j * m_chunkSize);
	}
}

void ConstantSizedMemoryPool::swap(ConstantSizedMemoryPool &toSwap){
	std::swap(m_chunkNumber, toSwap.m_chunkNumber);
	std::swap(m_chunkSize, toSwap.m_chunkSize);
	m_freeChunks.swap(toSwap.m_freeChunks);
	std::swap(m_storedMemory, toSwap.m_storedMemory);
	m_usedChunks.swap(toSwap.m_usedChunks);
}

} /* namespace tech */
} /* namespace coma */
