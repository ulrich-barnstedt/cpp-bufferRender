#include "exBufferRender.h"

// ------------------ Buffer I/O
void TE::STR::ExBufferRender::set(int x, int y, const std::string &str) {
    set(x, y, new std::string(str));
}

void TE::STR::ExBufferRender::set(int x, int y, std::string *str) {
    if (!inBounds(x, y)) return;
    memoryProtectedOverwrite(x, y, str);
}

std::string *TE::STR::ExBufferRender::get(int x, int y) {
    if (!inBounds(x, y)) return nullptr;
    return buf[y][x];
}

// ------------------ Checking/adjusting private methods

bool TE::STR::ExBufferRender::inBounds(int x, int y) {
    return x < width && y < height;
}

template<typename T> void TE::STR::ExBufferRender::trimVector(int limiter, int offset, std::vector<T> &vec) {
    if (vec.size() + offset >= limiter) vec.resize(limiter - offset);
}

//no bounds check / memory safe write
void TE::STR::ExBufferRender::memoryProtectedOverwrite(int x, int y, std::string *str) {
    if (pre[y][x] != buf[y][x]) delete buf[y][x];
    buf[y][x] = str;
}

// ------------------ Utility methods for common operations

void TE::STR::ExBufferRender::fill(const std::string &str) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            memoryProtectedOverwrite(j, i, new std::string(str));
        }
    }
}

void TE::STR::ExBufferRender::verticalArray(int x, int y, std::vector<std::string *> &arr) {
    if (!inBounds(x, y)) return;
    trimVector<std::string*>(height, y, arr);

    for (int i = 0; i < arr.size(); i++) {
        memoryProtectedOverwrite(x, i + y, arr[i]);
    }
}

void TE::STR::ExBufferRender::horizontalArray(int x, int y, std::vector<std::string *> &arr) {
    if (!inBounds(x, y)) return;
    trimVector<std::string*>(width, x, arr);

    for (int i = 0; i < arr.size(); i++) {
        memoryProtectedOverwrite(x + i, y, arr[i]);
    }
}

void TE::STR::ExBufferRender::d2Array(int x, int y, std::vector<std::vector<std::string *>> &arr) {
    if (!inBounds(x, y)) return;
    trimVector<std::vector<std::string*>>(height, y, arr);

    for (int i = 0; i < arr.size(); i++) {
        horizontalArray(x, i + y, arr[i]);
    }
}
