#pragma once

#include "bufferRender.h"

namespace TE {
    class ExBufferRender : public BufferRender {
        public:
            using BufferRender::BufferRender;

            void fill(const std::string &str);
            void set(int x, int y, const std::string &str);
            void set(int x, int y, std::string *str);
            void verticalArray(int x, int y, std::vector<std::string*> &arr);
            void horizontalArray(int x, int y, std::vector<std::string*> &arr);
            void d2Array(int x, int y, std::vector<std::vector<std::string*>> &arr);
            bool inBounds(int x, int y);
        private:
            template <typename T> void trimVector(int limiter, int offset, std::vector<T> &vec);
    };
}



