// Copyright (C) 2024  Jordon Brooks

#pragma once

#include <memory>
#include <cstring>
#include <string>

#include "Core.h"  // Replace with actual API export macro

class FStringImpl;
/**
 * @file FString.h
 * @brief FString Class - Custom String Management for DLL Export
 *
 * The FString class is a custom string management class designed to safely encapsulate
 * string handling and memory management, especially for use in DLLs (Dynamic Link Libraries).
 * It resolves the common issue of exporting classes containing standard library types,
 * such as std::string, across DLL boundaries, which can lead to compiler warnings or errors.
 *
 * Features:
 * - Implements basic string operations such as construction, destruction, copy, and move semantics.
 * - Utilizes smart pointers (std::unique_ptr) for automatic memory management, reducing the risk of memory leaks.
 * - Provides a simple interface for interacting with character strings, similar to std::string.
 * - Includes both deep copy semantics for safety and move semantics for performance in object transfers.
 *
 * Usage:
 * FString can be used as a safer alternative to std::string for classes that are exported from a DLL.
 * It handles memory allocation/deallocation automatically and provides a basic set of string operations.
 * 
 * Example:
 *     FString myString("Hello, world!");
 *     std::cout << myString.c_str() << std::endl; // Output: Hello, world!
 *
 * Note:
 * - The class is currently designed with basic functionality. Additional features such as
 *   string concatenation, substring, and comparison operations can be added as needed.
 * - Ensure that the HarmonyLinkLibApi.h (or equivalent) file correctly defines the export macro
 *   for DLL usage.
 *
 */
class HARMONYLINKLIB_API FString {
public:
    FString() : data_(new char[1]) {
        data_[0] = '\0';
    }

    FString(const char* str) {
        const size_t len = strlen(str);
        data_ = new char[len + 1];
        memcpy(data_, str, len + 1);
    }

    // Copy constructor
    FString(const FString& other) {
        const size_t len = strlen(other.data_);
        data_ = new char[len + 1];
        memcpy(data_, other.data_, len + 1);
    }

    // Copy assignment operator
    FString& operator=(const FString& other) {
        if (this != &other) {
            delete[] data_;
            const size_t len = strlen(other.data_);
            data_ = new char[len + 1];
            memcpy(data_, other.data_, len + 1);
        }
        return *this;
    }

    // Move constructor
    FString(FString&& other) noexcept : data_(other.data_) {
        other.data_ = nullptr;
    }

    FString(const std::string& str) {
        const size_t len = str.length();
        data_ = new char[len + 1];
        memcpy(data_, str.c_str(), len + 1);
    }

    // Move assignment operator
    FString& operator=(FString&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            other.data_ = nullptr;
        }
        return *this;
    }

    ~FString() {
        delete[] data_;
    }

    const char* c_str() const {
        return data_;
    }

private:
    char* data_ = nullptr;
};
