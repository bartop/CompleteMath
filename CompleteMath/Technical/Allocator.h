/*
 * Allocator.h
 *
 *  Created on: 18 sie 2015
 *      Author: Bartosz Miera
 */

#ifndef TECHNICAL_ALLOCATOR_H_
#define TECHNICAL_ALLOCATOR_H_

#include <vector>

namespace coma {
namespace tech {

template<class T>
class Allocator{
public:
	using allocated_type = T;
	using size_t = std::size_t;

	virtual ~Allocator() = default;

	template<class... Args>
	allocated_type *emplaceAtPosition(size_t position, Args&&... args){
		if(position >= m_size) reallocate(position + 1);
		new (m_allocated[position]) allocated_type{std::forward<Args>(args)...};
		return m_allocated;
	}

	allocated_type &getFromPosition(size_t position){
		if(position >= m_size) reallocate(position + 1);
		return m_allocated[position];
	}

	void destructAtPosition(size_t position){
		m_allocated[position]->~allocated_type;
	}

	size_t getCapacity(){
		return m_size;
	}

private:
	size_t m_size = 0;
	allocated_type *m_allocated = nullptr;

	virtual void reallocate(size_t size);

};

}  // namespace tech
}  // namespace coma

#endif /* TECHNICAL_ALLOCATOR_H_ */
