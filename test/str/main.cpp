#include "../../lib/str/exBufferRender.h"

void drawBoxes (TE::STR::ExBufferRender &render);

int main() {
    //TE::STR::ExBufferRender render(TE::Util::getTerminalSize());
    TE::STR::ExBufferRender render(60, 200);

    for (int i = 0; i < render.height; i++) {
        for (int j = 0; j < render.width; j++) {
            render.set(j, i, "a");
            render.render();
        }
    }

    render.fill("_");
    render.render();

    drawBoxes(render);
    render.set(1, 1, "b");
    render.set(2, 2, "b");

    render.render();

    for (int m = 0; m < 10; m++) {
        for (int l = 0; l < 10; l++) {
            for (int i = 0; i < render.height; i++) {
                render.fill("_");
                std::vector<std::vector<std::string*>> vec(10);

                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 100; k++) {
                        vec[j].push_back(new std::string(std::to_string(l)));
                    }
                }

                render.d2Array(3, i, vec);
                render.render();
            }
        }
    }

    return 0;
}

void drawBoxes (TE::STR::ExBufferRender &render) {
    std::vector<std::string*> vec(10);
    for (int i = 0; i < 10; i++) vec[i] = new std::string("#");
    std::vector<std::string*> vec2(10);
    for (int i = 0; i < 10; i++) vec2[i] = new std::string("#");

    render.horizontalArray(3, 3, vec);
    render.verticalArray(3, 7, vec2);

    std::vector<std::vector<std::string*>> vecX(10);
    for (int i = 0; i < 10; i++) {
        vecX[i].resize(10);

        for (int j = 0; j < 10; j++) {
            vecX[i][j] = new std::string("#");
        }
    }
    render.d2Array(7, 5, vecX);
}