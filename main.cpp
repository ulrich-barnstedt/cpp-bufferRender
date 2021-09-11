#include "lib/bufferRender.h"

//testing code

int main() {
    //TE::BufferRender render(TE::getTerminalSize());
    TE::BufferRender render(100, 100);

    for (int i = 0; i < render.height; i++) {
        for (int j = 0; j < render.width; j++) {
            render.buf[i][j] = new std::string("a");
            render.render();
        }
    }

    render.buf[1][1] = new std::string("b");
    render.buf[2][2] = new std::string("b");
    render.render();

    return 0;
}