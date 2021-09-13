#include "cursor.h"

void TE::STR::Cursor::move (int x, int y) {
    currentY = y;
    currentX = x;

    //zero indexing fix
    printf("\033[%d;%dH", y + 1, x + 1);
}

void TE::STR::Cursor::write(const std::string &ref) {
    currentX++;

    std::cout << ref;
}

