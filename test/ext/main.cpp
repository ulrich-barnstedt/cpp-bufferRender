#include "../../lib/ext/U_DCMP.h"

class StrPtrMMC : public TE::EXT::Base<StrPtrMMC> {
    public:
        std::string data;
        explicit StrPtrMMC(const std::string &ref);

        const std::string& toString() override;
        bool operator== (const StrPtrMMC &ref) override;
};

StrPtrMMC::StrPtrMMC(const std::string &ref) {
    this->data = ref;
}

const std::string &StrPtrMMC::toString() {
    return data;
}

bool StrPtrMMC::operator==(const StrPtrMMC &ref) {
    return ref.data == this->data;
}

class Renderer : public TE::EXT::U_DCMP<StrPtrMMC> {
    public:
        using TE::EXT::U_DCMP<StrPtrMMC>::U_DCMP;

        StrPtrMMC initInstance(int y, int x, bool primary) override {
            return StrPtrMMC(primary ? "A" : "a");
        }
};

int main () {
    //TE::EXT::U_DCMP<StrPtrMMC> render(TE::Util::getTerminalSize());
    //Renderer x(TE::Util::getTerminalSize());
    Renderer x(10, 10);

    x.init();
    x.render();


    //TODO:
    // Merge
    // Test functions (extra functions)
    // Check rendering working properly
    // Check code generally
    // Fix Readme


    return 0;
}