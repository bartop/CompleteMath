/*
 * TypeTraits.h
 *
 *  Created on: 31 sie 2015
 *      Author: Bartosz Miera
 */

#ifndef TECHNICAL_TYPETRAITS_H_
#define TECHNICAL_TYPETRAITS_H_

#include <type_traits>

template<typename Test, template<typename...> class Ref>
struct isSpecialization : std::false_type {};

template<template<typename...> class Ref, typename... Args>
struct isSpecialization<Ref<Args...>, Ref> : std::true_type {};

#endif /* TECHNICAL_TYPETRAITS_H_ */
