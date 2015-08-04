/*
 * MemoryPoolObject.h
 *
 *  Created on: 3 sie 2015
 *      Author: Bartosz Miera
 */

#ifndef TECHNICAL_MEMORYPOOLOBJECT_H_
#define TECHNICAL_MEMORYPOOLOBJECT_H_

#include "MemoryPool.h"
#include <memory>
#include "MemoryPoolDummy.h"
#include "ConstantSizedMemoryPool.h"

namespace coma {
namespace tech {

/**
 * @brief
 *	Abstract object for memory pool usage.
 */
class MemoryPoolObject {
public:
	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~MemoryPoolObject();

	/**
	 * @brief
	 * 	New overload for derived classes. Uses memory pool allocate function.
	 *
	 * @param size
	 * 	Size of allocated object.
	 */
	void *operator new(std::size_t size);

	/**
	 * @brief
	 * 	Delete overload for derived classes. Uses memory pool deallocate function.
	 *
	 * @param toDelete
	 * 	Memory to be freed.
	 */
	void operator delete(void *const toDelete);

	/**
	 * @brief
	 * 	Sets memory pool used by this and inheriting classes.
	 *
	 * @param memoryPool
	 * 	Memory pool to set active.
	 */
	static void setMemoryPool(MemoryPool &memoryPool);

	static MemoryPool &getDefaultMemoryPool(){
		static MemoryPool &&defaultPool = MemoryPoolDummy();
		return defaultPool;
	}
private:
	static MemoryPool *m_memoryPool;

	static void initialize();
};

} /* namespace tech */
} /* namespace coma */

#endif /* TECHNICAL_MEMORYPOOLOBJECT_H_ */
