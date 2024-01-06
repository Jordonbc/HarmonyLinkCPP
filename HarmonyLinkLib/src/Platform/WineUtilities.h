#pragma once

#include "FOSVerInfo.h"
#include "FBattery.h"

class WineUtilities
{
public:
    static std::shared_ptr<FBattery> get_battery_status();

    /**
     * @brief Retrieves Linux OS version information from a specified file.
     * 
     * This function parses a file (typically a Linux OS release file) at the given location
     * to extract operating system version information. It reads key-value pairs from the file,
     * processes them to handle whitespace and quotes, and then stores them in an FOSVerInfo
     * structure. If the file location is invalid or the file cannot be opened, it returns an
     * empty FOSVerInfo structure. Errors during parsing, such as invalid format or out of range 
     * values, are handled with exception catching. In Windows builds where Wine is detected, 
     * this function can use the file location 'Z:/etc/os-release' to retrieve the underlying 
     * Linux system information.
     * 
     * @param file_location The location of the file containing OS version information.
     * @return A shared pointer to a structure containing the parsed OS version information.
     */
    static std::shared_ptr<FOSVerInfo> get_linux_info();

    /**
     * @brief Detects the presence of Wine or Proton in Windows builds.
     * 
     * This function assesses if the application is running under Wine or Proton by
     * querying specific functions in the 'ntdll.dll' module. It is only active in 
     * Windows builds, returning false for non-Windows builds.
     *
     * @return bool True if Wine or Proton is detected, false otherwise.
     */
    static bool detect_wine_presence();
};
