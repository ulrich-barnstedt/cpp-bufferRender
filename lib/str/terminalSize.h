#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

namespace TE::STR {
    struct terminalDimensions {
        int height;
        int width;
    };

    terminalDimensions getTerminalSize();
}