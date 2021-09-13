#include "terminalSize.h"

TE::STR::terminalDimensions TE::STR::getTerminalSize() {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns, rows;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        return {columns, rows};
    #else
        winsize w {};
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

        return {w.ws_row, w.ws_col};
    #endif
}