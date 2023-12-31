// copyright notice here

#pragma once


// Use a preprocessor definition to switch between export and import declarations
#ifdef HARMONYLINKLIB_EXPORTS
#define HARMONYLINKLIB_API __declspec(dllexport)
#else
#define HARMONYLINKLIB_API __declspec(dllimport)
#endif
