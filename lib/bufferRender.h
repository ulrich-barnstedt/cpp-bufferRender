#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "terminalSize.h"
#include "cursor.h"

namespace TE {
    class BufferRender {
        public:
            std::vector<std::vector<std::string*>> buf;
            const int height, width;

            BufferRender(int height, int width);
            explicit BufferRender(const terminalDimensions &dim);
            ~BufferRender();
            void render();
        private:
            std::vector<std::vector<std::string*>> pre;

            void init();
    };
}




