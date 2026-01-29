#include <iostream>

#include "ansi.h"

int main() {
    AnsiManager manager(RGB { 255, 0, 0 }, RGB { 0, 255, 0 });
    manager.resetScreen(std::cout);
}
