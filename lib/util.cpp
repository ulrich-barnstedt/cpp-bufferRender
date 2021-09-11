#include "util.h"

void TE::ExBufferRender::fill(const std::string &str) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            buf[i][j] = new std::string(str);
        }
    }
}

void TE::ExBufferRender::set(int x, int y, const std::string &str) {
    if (!inBounds(x, y)) return;
    buf[y][x] = new std::string(str);
}

void TE::ExBufferRender::set(int x, int y, std::string *str) {
    if (!inBounds(x, y)) return;
    buf[y][x] = str;
}

void TE::ExBufferRender::verticalArray(int x, int y, std::vector<std::string *> &arr) {
    if (!inBounds(x, y)) return;
    trimVector<std::string*>(height, y, arr);

    for (int i = y; i < arr.size(); i++) {
        buf[i][x] = arr[i];
    }
}

void TE::ExBufferRender::horizontalArray(int x, int y, std::vector<std::string *> &arr) {
    if (!inBounds(x, y)) return;
    trimVector<std::string*>(width, x, arr);

    for (int i = x; i < arr.size(); i++) {
        buf[y][i] = arr[i];
    }
}

void TE::ExBufferRender::d2Array(int x, int y, std::vector<std::vector<std::string *>> &arr) {
    if (!inBounds(x, y)) return;
    trimVector<std::vector<std::string*>>(height, y, arr);

    for (int i = y; i < arr.size(); i++) {
        horizontalArray(x, i, arr[i]);
    }
}

bool TE::ExBufferRender::inBounds(int x, int y) {
    return x < width && y < height;
}

template<typename T> void TE::ExBufferRender::trimVector(int limiter, int offset, std::vector<T> &vec) {
    if (vec.size() + offset >= limiter) vec.resize(limiter - offset);
}
