#include "cursor.h"

void TE::Util::Cursor::move (int x, int y) {
    if (x == currentX && y == currentY) return;

    currentY = y;
    currentX = x;

    //zero indexing fix
    printf("\033[%d;%dH", y + 1, x + 1);
}

void TE::Util::Cursor::write(const std::string &ref) {
    currentX++;

    std::cout << ref;
}

void TE::Util::Cursor::operator<<(const std::string &str) {
    write(str);
}
