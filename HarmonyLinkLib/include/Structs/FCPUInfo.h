#pragma once

#include <cstdint>
#include <unordered_set>
#include "FString.h"

#include "HarmonyLinkStruct.h"

struct FCPUInfo : HarmonyLinkStruct
{
    FString VendorID;
    FString Model_Name;
    uint32_t Physical_Cores = 0;
    uint32_t Logical_Cores = 0;
    std::unordered_set<FString> Flags;

    void print() const
    {
        printf("VendorID: '%s'\n", VendorID.c_str());
        printf("Model_Name: '%s'\n", Model_Name.c_str());
        printf("Physical_Cores: '%d'\n", Physical_Cores);
        printf("Logical_Cores: '%d'\n", Logical_Cores);
        
        // Initialize a string to hold all flags
        std::string allFlags;
        for (const auto& flag : Flags) {
            allFlags += std::string(flag.c_str()) + " "; // Append each flag followed by a space
        }

        // Remove the trailing space
        if (!allFlags.empty()) {
            allFlags.pop_back();
        }

        printf("Flags: '%s'\n", allFlags.c_str());
    }
};
