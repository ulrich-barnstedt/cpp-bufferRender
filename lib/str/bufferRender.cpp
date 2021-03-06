#include "bufferRender.h"

TE::STR::BufferRender::BufferRender (int height, int width) : height(height), width(width) {
    this->init();
}

TE::STR::BufferRender::BufferRender (const Util::terminalDimensions &dim) : height(dim.height), width(dim.width) {
    this->init();
}

void TE::STR::BufferRender::init () {
    this->buf.resize(height);
    this->pre.resize(height);

    for (int i = 0; i < this->height; i++) {
        this->buf[i].resize(width);
        this->pre[i].resize(width);
    }

    Util::Cursor::getInstance().move(0, 0);
}

TE::STR::BufferRender::~BufferRender() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::string* &bufPtr = this->buf[i][j];
            std::string* &prePtr = this->pre[i][j];

            if (bufPtr != nullptr && this->buf[i][j] != prePtr) delete bufPtr;
            if (prePtr != nullptr) delete prePtr;
        }
    }
}

void TE::STR::BufferRender::render () {
    Util::Cursor &cursor = Util::Cursor::getInstance();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::string* &bufPtr = this->buf[i][j];
            std::string* &prePtr = this->pre[i][j];

            if (bufPtr == nullptr) continue;
            if (prePtr != nullptr && *bufPtr == *prePtr) continue;

            if (prePtr != nullptr) delete prePtr;
            prePtr = bufPtr;

            cursor.move(j, i);
            cursor.write(*bufPtr);
        }
    }
}