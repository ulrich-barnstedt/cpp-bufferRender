#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "../util/terminalSize.h"
#include "../util/cursor.h"

namespace TE::STR {
    class BufferRender {
        public:
            std::vector<std::vector<std::string*>> buf;
            const int height, width;

            BufferRender(int height, int width);
            explicit BufferRender(const Util::terminalDimensions &dim);
            ~BufferRender();
            void render();
        protected:
            std::vector<std::vector<std::string*>> pre;
        private:
            void init();
    };
}




