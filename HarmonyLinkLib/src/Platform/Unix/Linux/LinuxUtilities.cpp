#include "LinuxUtilities.h"


#include <fstream>
#include <string>
#include "Platform/WineUtilities.h"

FBattery LinuxUtilities::get_battery_status()
{
    return WineUtilities::get_battery_status();
}

FOSVerInfo LinuxUtilities::get_os_version()
{
    return WineUtilities::get_linux_info();
}
