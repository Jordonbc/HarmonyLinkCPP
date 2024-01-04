#pragma once
#include <string>

#include "FString.h"

struct FDistroInfo {
    FString name;
    FString version;
    FString id;
    FString version_id;
    FString version_codename;
    FString pretty_name;
};
