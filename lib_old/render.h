#pragma once
#include <vector>
#include <functional>
#include "renderInternal.h"
#include "Cursor.h"
#include "terminal.h"

namespace strLib {
    class BufferRender {
        public:
            const Terminal src;
            internal::vector2<internal::vector2<std::string>> buf;
            BufferRender(int x, int y);
            explicit BufferRender(const Terminal &src);
            void render();
        private:
            void init();
            internal::vector2<internal::vector2<internal::DataObj>> last;
    };
};




