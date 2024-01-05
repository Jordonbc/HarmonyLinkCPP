#include "IPlatformUtilities.h"

#include <fstream>
#include <sstream>
#include <unordered_map>

IPlatformUtilities::IPlatformUtilities()
{
    std::cout << "Creating new instance of IPlatformUtilities.\n";
}

FOSInfo IPlatformUtilities::get_os_info(const std::string& file_location)
{
    FOSInfo os_info;
    if (file_location.empty())
    {
        std::cout << "File location is invalid\n";
        return {};
    }
    
    std::ifstream file(file_location);
    std::unordered_map<FString, FString> Hashmap;

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

                    Hashmap[key] = value;
                }
            }
        }
        file.close();
    }

    // Now you can access the values using the keys:
    os_info.name = Hashmap["NAME"];
    os_info.id = Hashmap["ID"];
    os_info.version_id = Hashmap["VERSION_ID"];
    os_info.version_codename = Hashmap["VERSION_CODENAME"];
    os_info.pretty_name = Hashmap["PRETTY_NAME"];

    try {
        os_info.version = std::stoi(Hashmap["VERSION"].c_str());
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        // Handle the error, perhaps by setting a default value or leaving the field unchanged
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        // Handle the error, perhaps by setting a default value or leaving the field unchanged
    }

    return os_info;
}
