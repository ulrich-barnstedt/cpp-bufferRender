#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <stdio.h>
    #include <unistd.h>
#endif

namespace strLib {
    class Terminal {
        public:
            const int x;
            const int y;
            Terminal(int x, int y) : x(x), y(y) {};
            explicit Terminal(const Terminal &src) : x(src.x), y(src.y) {};

            static Terminal getAttached () {
                #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
                    CONSOLE_SCREEN_BUFFER_INFO csbi;
                    int columns, rows;

                    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
                    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
                    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

                    return {columns, rows};
                #else
                    struct winsize w;
                    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

                    return {w.ws_col, w.ws_row};
                #endif
            }
    };
}