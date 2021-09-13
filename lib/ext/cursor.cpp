#include "cursor.h"

void TE::EXT::Cursor::move (int x, int y) {
    if (x == currentX && y == currentY) return;

    currentY = y;
    currentX = x;

    //zero indexing fix
    printf("\033[%d;%dH", y + 1, x + 1);
}

void TE::EXT::Cursor::write(const std::string &ref) {
    currentX++;

    std::cout << ref;
}

void TE::EXT::Cursor::operator<<(const std::string &str) {
    write(str);
}
