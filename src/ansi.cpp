#include "ansi.h"

AnsiManager::AnsiManager(RGB defaultForegroundColor, RGB defaultBackgroundColor) :
    defaultForegroundColor(defaultForegroundColor),
    defaultBackgroundColor(defaultBackgroundColor),
    backgroundColor(RGB { 0, 0, 0 }),
    foregroundColor(RGB { 255, 255, 255 })
{ }

void AnsiManager::setForegroundColor(std::ostream& stream, RGB color)
{
    if (color == this->foregroundColor)
        return;

    stream << "\x1b[38;2;" << int(color.R) << ';' << int(color.G) << ';' << int(color.B) << 'm';
    this->foregroundColor = color;
}

void AnsiManager::setBackgroundColor(std::ostream& stream, RGB color)
{
    if (color == this->backgroundColor)
        return;

    stream << "\x1b[48;2;" << int(color.R) << ';' << int(color.G) << ';' << int(color.B) << 'm';
    this->backgroundColor = color;
}

void AnsiManager::resetForegroundColor(std::ostream& stream) {
    RGB color = this->defaultForegroundColor;
    stream << "\x1b[38;2;" << int(color.R) << ';' << int(color.G) << ';' << int(color.B) << 'm';
    this->backgroundColor = color;
}

void AnsiManager::resetBackgroundColor(std::ostream& stream) {
    RGB color = this->defaultBackgroundColor;
    stream << "\x1b[48;2;" << int(color.R) << ';' << int(color.G) << ';' << int(color.B) << 'm';
    this->backgroundColor = color;
}

void AnsiManager::resetScreen(std::ostream& stream) {
    stream /*<< this->ClearScreenAndBuffer*/ << this->ResetCursorTopRight;
    this->resetBackgroundColor(stream);
    this->resetForegroundColor(stream);
}
