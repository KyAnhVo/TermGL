#include "terminalManager.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

void TerminalManager::getTerminalSize(int& width, int& height) {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    width  = ws.ws_col;
    height = ws.ws_row;
#endif
    this->width = width;
    this->height = height;
}


bool TerminalManager::drawTriangles(int index) {
    // if VBO empty -> nothing to draw
    if (this->VBOs[index].vertices.size() == 0) return false;

    if (this->EBOs[index].vertexIndices.size() == 0) {
        // use EBO to draw
    } else {
        // use VBO to draw
    }
    return true;
}
