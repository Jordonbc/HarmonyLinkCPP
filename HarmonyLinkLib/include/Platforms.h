#pragma once

#include <cstdint>

// Enum class for representing different operating platforms
enum class EPlatform : uint8_t
{
    WINDOWS,
    LINUX,
    MAC,
    UNIX,
};

// Enum class for representing different types of devices
enum class EDevice : uint8_t
{
    DESKTOP,
    LAPTOP,
    HANDHELD,
    
    STEAM_DECK,
    // ROG_ALLY
    // AYONEO_SLIDE
    // etc...
};

// Struct to represent a specific device with both platform and device type
struct FDevice
{
    EPlatform platform;
    EDevice device;
};
