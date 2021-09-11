#pragma once
#include <iostream>

namespace strLib {
    class Cursor {
        public:
            static void move(int x, int y);
            static void write(std::string &text);
    };
}




