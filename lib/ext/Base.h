#pragma once

namespace TE::EXT {
    template <typename T> class Base {
        public:
            virtual bool operator==(const T& ref) = 0;
            virtual const std::string& toString() = 0;
    };
}