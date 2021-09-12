#include "bufferRender.h"

TE::BufferRender::BufferRender (int height, int width) : height(height), width(width) {
    this->init();
}

TE::BufferRender::BufferRender (const terminalDimensions &dim) : height(dim.height), width(dim.width) {
    this->init();
}

void TE::BufferRender::init () {
    this->buf.resize(height);
    this->pre.resize(height);

    for (int i = 0; i < this->height; i++) {
        this->buf[i].resize(width);
        this->pre[i].resize(width);
    }

    Cursor::getInstance().move(0, 0);
}

TE::BufferRender::~BufferRender() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::string* &bufPtr = this->buf[i][j];
            std::string* &prePtr = this->pre[i][j];

            if (bufPtr != nullptr && this->buf[i][j] != prePtr) delete bufPtr;
            if (prePtr != nullptr) delete prePtr;
        }
    }
}

void TE::BufferRender::render () {
    Cursor &cursor = Cursor::getInstance();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int cursorY = cursor.currentY, cursorX = cursor.currentX;

            std::string* &bufPtr = this->buf[i][j];
            std::string* &prePtr = this->pre[i][j];

            if (bufPtr == nullptr) continue;
            if (prePtr != nullptr && *bufPtr == *prePtr) continue;

            if (prePtr != nullptr) delete prePtr;
            prePtr = bufPtr;

            if (cursorX == j && cursorY == i) {
                Cursor::getInstance().write(*bufPtr);
                continue;
            }

            Cursor::getInstance().move(j, i);
            Cursor::getInstance().write(*bufPtr);
        }
    }
}