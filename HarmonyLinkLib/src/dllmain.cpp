// Copyright (C) 2023  Jordon Brooks

#if BUILD_WINDOWS
#include <windows.h>

// Standard DLL entry point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        // Code to run when the DLL is loaded
            break;
    case DLL_THREAD_ATTACH:
        // Code to run when a thread is created during the DLL's lifetime
            break;
    case DLL_THREAD_DETACH:
        // Code to run when a thread ends normally.
            break;
    case DLL_PROCESS_DETACH:
        // Code to run when the DLL is unloaded
            break;
    }
    return TRUE; // Successful DLL_PROCESS_ATTACH.
}

#endif
