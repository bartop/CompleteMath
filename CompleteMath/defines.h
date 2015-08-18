/*
 * defines.h
 *
 *  Created on: 14 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_DEFINES_H_
#define NUMBERS_DEFINES_H_

#define THIS_IS_DLL
#define DEBUG

#ifndef REPORT_ERROR
#	ifdef USE_EXCEPTIONS
#		define REPORT_ERROR(exception, ret) throw exception;
#	else
#		define REPORT_ERROR(exception, ret) return ret;
#	endif
#endif

#ifndef DLL_MACRO
#	ifdef THIS_IS_DLL
#		define DLL_MACRO __declspec(dllexport)
#	else
#		define DLL_MACRO __declspec(dllimport)
#	endif
#endif

#endif /* NUMBERS_DEFINES_H_ */
