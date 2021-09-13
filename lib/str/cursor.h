#pragma once

#include <iostream>

namespace TE::STR {
    class Cursor {
        public:
            static Cursor &getInstance () {
                static Cursor instance;
                return instance;
            }
            Cursor (Cursor const&) = delete;
            void operator= (Cursor const&) = delete;

            int currentY = 0, currentX = 0;
            void move (int x, int y);
            void write (const std::string &ref);
        private:
            Cursor () = default;
    };
}