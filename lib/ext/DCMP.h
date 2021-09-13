#pragma once
#include <string>
#include <vector>
#include <type_traits>
#include "cursor.h"
#include "Base.h"

//functions defined in-place because of template problems

namespace TE::EXT {
    template <typename T> class DCMP {
        public:
            static_assert(std::is_base_of<Base, T>::value, "T must inherit from list");
            std::vector<std::vector<T&>> data;
            const int height, width;
            DCMP(int height, int width);
            void render();
            void init();
            virtual T& initInstance(int y, int x) = 0;
        private:
            std::vector<std::vector<T>> mirror;
    };

    template <typename T> DCMP<T>::DCMP(int height, int width) : height(height), width(width) {
        init();
    }

    template <typename T> void DCMP<T>::render() {
        Cursor &cursor = Cursor::getInstance();

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                T &current = data[i][j];
                T &last = mirror[i][j];

                if (current == last) return;
                last = current;

                cursor.move(j, i);
                cursor << current;
            }
        }
    }

    template<typename T> void DCMP<T>::init() {
        data.reserve(height);
        mirror.reserve(height);

        for (int i = 0; i < this->height; i++) {
            data.resize[i].reserve(width);
            mirror.resize[i].reserve(width);

            for (int j = 0; j < width; j++) {
                T& newData = initInstance(i, j);
            }
        }

        Cursor::getInstance().move(0, 0);
    }
}




