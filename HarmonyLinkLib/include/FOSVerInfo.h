#pragma once

#include "FString.h"

struct FOSVerInfo {
    // 'name' represents the operating system's name, e.g., "Ubuntu" in Linux or "Windows" in Windows systems.
    FString name;
    
    // 'version' is a numerical representation of the OS version. In Linux, it might be the kernel version, 
    // whereas in Windows, it could be the major version number like 10 for Windows 10.
    uint32_t version = 0;

    // 'id' is a unique identifier for the OS. In Linux, it might be a lower-case string like "ubuntu". 
    // In Windows, this could map to the edition ID, such as "Professional".
    FString id;

    // 'version_id' is a string representing the specific version of the OS. 
    // For example, "20.04" in Ubuntu or "1909" in Windows 10.
    FString version_id;

    // 'version_codename' is a codename for the OS version, if available. 
    // This is common in Linux distributions (e.g., "focal" for Ubuntu 20.04) but not typically used in Windows.
    FString version_codename;

    // 'pretty_name' is a more readable version of the name, potentially including the version and codename.
    // For example, "Ubuntu 20.04 LTS (Focal Fossa)" or "Windows 10 Pro".
    FString pretty_name;
};
