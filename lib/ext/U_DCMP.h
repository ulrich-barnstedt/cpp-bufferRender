#pragma once
#include "DCMP.h"

namespace TE::EXT {
    template <typename T> class U_DCMP : public DCMP<T> {
        public:
            using DCMP<T>::DCMP;
            using DCMP<T>::initInstance;

            bool inBounds(int x, int y);

            void fill_ref(T& src);
            void fill_copy(const T& src);
            void verticalArray(int x, int y, const std::vector<T&> &src);
            void horizontalArray(int x, int y, const std::vector<T&> &src);
            void d2Array(int x, int y, const std::vector<std::vector<T&>> &src);
        private:
            template <typename V> void trimVector(int limiter, int offset, const std::vector<V> &vec);

    };

    template<typename T> void U_DCMP<T>::fill_ref(T &src) {
        for (int i = 0; i < this->height; i++) {
            for (int j = 0; j <this-> width; j++) {
                this->data[i][j] = src;
            }
        }
    }

    template<typename T> void U_DCMP<T>::fill_copy(const T &src) {
        for (int i = 0; i < this->height; i++) {
            for (int j = 0; j < this->width; j++) {
                this->data[i][j] = T(src);
            }
        }
    }

    template<typename T> bool U_DCMP<T>::inBounds(int x, int y) {
        return x < this->width && y < this->height;
    }

    template<typename T> template<typename V> void U_DCMP<T>::trimVector(int limiter, int offset, const std::vector<V> &vec) {
        if (vec.size() + offset >= limiter) vec.resize(limiter - offset);
    }

    template<typename T> void U_DCMP<T>::verticalArray(int x, int y, const std::vector<T&> &src) {
        if (!inBounds(x, y)) return;
        trimVector<T>(this->height, y, src);

        for (int i = 0; i < this->arr.size(); i++) {
            this->data[i + y][x] = src[i];
        }
    }

    template<typename T> void U_DCMP<T>::horizontalArray(int x, int y, const std::vector<T&> &src) {
        if (!inBounds(x, y)) return;
        trimVector<T>(this->width, x, src);

        for (int i = 0; i < this->arr.size(); i++) {
            this->data[y][i + x] = src[i];
        }
    }

    template<typename T> void U_DCMP<T>::d2Array(int x, int y, const std::vector<std::vector<T&>> &src) {
        if (!inBounds(x, y)) return;
        trimVector<std::vector<T>>(this->height, y, src);

        for (int i = 0; i < this->arr.size(); i++) {
            horizontalArray(x, i + y, src[i]);
        }
    }
}
