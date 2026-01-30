#include "ansi.h"
#include "terminalManager.h"

#include <cstdio>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

int main() 
{
    std::stringstream str;
    AnsiManager ansiManager(RGB { 255, 255, 255 }, RGB { 0, 0, 0 });
    TerminalManager termManager;
    int width, height;
    termManager.getTerminalSize(width, height);

    const char* chars[] = {" ", "░", "▒", "▓", "█", "▓", "▒", "░"};
    const char * currChar = chars[0];
    int currInd = 0;

    for (;;) 
    {
        str.str("");
        str.clear();
        ansiManager.resetScreen(str);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                str << currChar;
            }
            if (i < height - 1) str << '\n';
        }
        std::cout << str.str() << std::flush;
        currInd = (currInd + 1) % 8;
        currChar = chars[currInd];
        std::this_thread::sleep_for(std::chrono::milliseconds(34));
    }


}
