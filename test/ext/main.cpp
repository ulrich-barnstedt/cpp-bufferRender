#include "../../lib/ext/U_DCMP.h"

class StrPtrMMC : public TE::EXT::Base<StrPtrMMC> {
    public:
        std::string data;
        StrPtrMMC();
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

StrPtrMMC::StrPtrMMC() {
    data = "U";
}

class Renderer : public TE::EXT::U_DCMP<StrPtrMMC> {
    public:
        using TE::EXT::U_DCMP<StrPtrMMC>::U_DCMP;

        StrPtrMMC initInstance(int y, int x, bool primary) override {
            return StrPtrMMC(primary ? "_" : "a");
        }
};

void droppingSquares (Renderer &render) {
    StrPtrMMC fill("~");

    for (int m = 0; m < 1; m++) {
        for (int l = 0; l < 10; l++) {
            for (int i = 0; i < render.height; i++) {
                render.fill_ref(fill);
                std::vector<std::vector<StrPtrMMC>> vec(10);

                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 100; k++) {
                        vec[j].push_back(StrPtrMMC("#"));
                    }
                }

                render.d2Array(13, i, vec);
                render.render();
            }
        }
    }
}

int main () {
    //Renderer x(TE::Util::getTerminalSize());
    Renderer x(60, 200);

    x.init();
    x.render();

    std::vector<std::vector<StrPtrMMC>> vec2d;
    vec2d.resize(10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            vec2d[i].push_back(StrPtrMMC("#"));
        }
    }

    x.d2Array(2, 2, vec2d);
    x.render();

    droppingSquares(x);


    //TODO:
    // Merge
    // Fix Readme


    return 0;
}