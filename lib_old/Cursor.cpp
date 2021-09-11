#include "Cursor.h"

void strLib::Cursor::move(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void strLib::Cursor::write(std::string &text) {
    std::cout << text;
}
