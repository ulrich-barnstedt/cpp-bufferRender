#pragma once
#include "bufferRender.h"

namespace TE::STR {
    class ExBufferRender : public BufferRender {
        public:
            using BufferRender::BufferRender;

            void set(int x, int y, const std::string &str);
            void set(int x, int y, std::string *str);
            std::string* get(int x, int y);
            bool inBounds(int x, int y);

            void fill(const std::string &str);
            void verticalArray(int x, int y, std::vector<std::string*> &arr);
            void horizontalArray(int x, int y, std::vector<std::string*> &arr);
            void d2Array(int x, int y, std::vector<std::vector<std::string*>> &arr);
        private:
            using BufferRender::buf;

            template <typename T> void trimVector(int limiter, int offset, std::vector<T> &vec);
            void memoryProtectedOverwrite(int x, int y, std::string* str);
    };
}



