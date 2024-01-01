// Copyright (C) 2023  Jordon Brooks
#pragma once

#include <string>
#include <sstream>
#include <Version.generated.h>

class version
{
    std::string build_timestamp = std::string();
    std::string git_branch = std::string();
    std::string git_commit_timestamp = std::string();
    std::string version_pre;

    static bool is_debug()
    {
    #ifdef DEBUG_MODE
            return true;
    #else
            return false;
    #endif
    }

public:
    static std::string ToString()
    {
        return HARMONYLINK_VERSION;
    }
};
