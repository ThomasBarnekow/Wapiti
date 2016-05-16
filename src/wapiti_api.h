/*
 *      Wapiti - A linear-chain CRF tool
 *
 * Copyright 2016 Thomas Barnekow
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
 
#ifndef wapiti_api_h
#define wapiti_api_h

#include <Windows.h>

// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
#define WAPITI_DLL_IMPORT __declspec(dllimport)
#define WAPITI_DLL_EXPORT __declspec(dllexport)
#define WAPITI_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define WAPITI_DLL_IMPORT __attribute__ ((visibility ("default")))
#define WAPITI_DLL_EXPORT __attribute__ ((visibility ("default")))
#define WAPITI_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define WAPITI_DLL_IMPORT
#define WAPITI_DLL_EXPORT
#define WAPITI_DLL_LOCAL
#endif
#endif

// Now we use the generic helper definitions above to define WAPITI_API and
// WAPITI_LOCAL. WAPITI_API is used for the public API symbols. It either DLL
// imports or DLL exports (or does nothing for a static build).
// WAPITI_LOCAL is used for non-api symbols.
#ifdef WAPITI_DLL			// defined if WAPITI is compiled as a DLL
#ifdef WAPITI_DLL_EXPORTS	// defined if we are building the WAPITI DLL
#define WAPITI_API WAPITI_DLL_EXPORT
#else
#define WAPITI_API WAPITI_DLL_IMPORT
#endif	// WAPITI_DLL_EXPORTS
#define WAPITI_LOCAL WAPITI_DLL_LOCAL
#else	// WAPITI_DLL is not defined: this means WAPITI is a static lib
#define WAPITI_API
#define WAPITI_LOCAL
#endif	// WAPITI_DLL

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Dummy function.
 */
WAPITI_API int __cdecl wapiti_add(int a, int b);

#ifdef __cplusplus
}
#endif

#endif // wapiti_api_h
