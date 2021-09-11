#include "lib/exBufferRender.h"
#define NO_LEN_DEBUG 0

#if NO_LEN_DEBUG == 1
    #define CONSTR TE::ExBufferRender render(TE::getTerminalSize());
#else
    #define CONSTR TE::ExBufferRender render(20, 20);
#endif

void drawBoxes (TE::ExBufferRender &render);

int main() {
    CONSTR

    for (int i = 0; i < render.height; i++) {
        for (int j = 0; j < render.width; j++) {
            render.buf[i][j] = new std::string("a");
            render.render();
        }
    }

    render.fill("_");
    render.render();

    drawBoxes(render);
    render.buf[1][1] = new std::string("b");
    render.set(2, 2, "b");

    render.render();

    return 0;
}

void drawBoxes (TE::ExBufferRender &render) {
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