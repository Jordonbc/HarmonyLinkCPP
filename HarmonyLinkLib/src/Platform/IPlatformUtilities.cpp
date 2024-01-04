#include "IPlatformUtilities.h"

#include <fstream>
#include <sstream>
#include <unordered_map>

FDistroInfo IPlatformUtilities::get_os_info(const std::string& FileLocation)
{
    FDistroInfo distroInfo;
    if (!FileLocation.empty())
    {
        std::cout << "File location is invalid\n";
        return distroInfo;
    }
    
    std::ifstream file(FileLocation);
    std::unordered_map<std::string, std::string> keyToValueMap;

    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::string key, value;
            if (std::getline(lineStream, key, '=')) {
                if (std::getline(lineStream, value)) {
                    // Remove leading and trailing whitespace
                    size_t firstNonSpace = value.find_first_not_of(" \t");
                    size_t lastNonSpace = value.find_last_not_of(" \t");
                    if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos) {
                        value = value.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
                    } else {
                        value.clear(); // If value is all whitespace, make it empty
                    }

                    // Check for double quotes and remove them
                    if (!value.empty() && value.front() == '"' && value.back() == '"') {
                        value = value.substr(1, value.length() - 2);
                    }

                    keyToValueMap[key] = value;
                }
            }
        }
        file.close();
    }

    // Now you can access the values using the keys:
    distroInfo.name = keyToValueMap["NAME"];
    distroInfo.version = keyToValueMap["VERSION"];
    distroInfo.id = keyToValueMap["ID"];
    distroInfo.version_id = keyToValueMap["VERSION_ID"];
    distroInfo.version_codename = keyToValueMap["VERSION_CODENAME"];
    distroInfo.pretty_name = keyToValueMap["PRETTY_NAME"];

    return distroInfo;
}
