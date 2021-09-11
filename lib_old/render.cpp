#include "render.h"

strLib::BufferRender::BufferRender(int xSrc, int ySrc) : src(xSrc, ySrc) { init(); }
strLib::BufferRender::BufferRender(const strLib::Terminal &src) : src(src) { init(); }

void strLib::BufferRender::init() {
    last.resize(src.y);
    buf.resize(src.y);

    for (int i = 0; i < src.y; i++) {
        for (int j = 0; j < src.x; j++) {
            last[i].push_back(internal::DataObj());
            buf[i].push_back(internal::__EMPTY__);
        }
    }
}

void strLib::BufferRender::render() {
    int atX = 0, atY = 0;
    strLib::Cursor::move(0, 0);

    for (int i = 0; i < src.y; i++) {
        for (int j = 0; j < src.x; j++) {
            last[i][j].update(new std::string(buf[i][j]));
            if (!last[i][j].diff()) continue;

            if (atX + 1 == j && atY == i) {
                strLib::Cursor::write(*last[i][j].val());
                atX++;
                continue;
            }

            strLib::Cursor::move(j, i);
            atX = j;
            atY = i;

            strLib::Cursor::write(*last[i][j].val());
        }
    }
}



