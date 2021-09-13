#pragma once

namespace TE::EXT {
    class Base {
        public:
            virtual ~Base() = 0;
            virtual bool operator==(const Base &ref) = 0;
            virtual const std::string& toString() = 0;
    };
}