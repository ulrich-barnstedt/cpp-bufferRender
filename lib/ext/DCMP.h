#pragma once
#include <string>
#include <vector>
#include <type_traits>
#include "../util/cursor.h"
#include "Base.h"
#include "../util/terminalSize.h"

//functions defined in-place because of template problems

namespace TE::EXT {
    template <typename T> class DCMP {
        public:
            static_assert(std::is_base_of<Base<T>, T>::value, "T must inherit from list");
            std::vector<std::vector<T>> data;
            const int height, width;
            DCMP(int height, int width);
            explicit DCMP(const TE::Util::terminalDimensions &dim);
            void render();
            void init();
            virtual T initInstance(int y, int x, bool primary) = 0;
        protected:
            std::vector<std::vector<T>> mirror;
    };

    template <typename T> DCMP<T>::DCMP(int height, int width) : height(height), width(width) {}

    template<typename T> DCMP<T>::DCMP(const TE::Util::terminalDimensions &dim) : width(dim.width), height(dim.height) {}

    template <typename T> void DCMP<T>::render() {
        Util::Cursor &cursor = Util::Cursor::getInstance();

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                T &current = data[i][j];
                T &last = mirror[i][j];

                if (current == last) continue;
                last = current;

                cursor.move(j, i);
                cursor << current.toString();
            }
        }
    }

    template<typename T> void DCMP<T>::init() {
        data.resize(height);
        mirror.resize(height);

        for (int i = 0; i < this->height; i++) {
            data[i].reserve(width);
            mirror[i].reserve(width);

            for (int j = 0; j < width; j++) {
                data[i].push_back(initInstance(i, j, true));
                mirror[i].push_back(initInstance(i, j, false));
            }
        }

        Util::Cursor::getInstance().move(0, 0);
    }
}




