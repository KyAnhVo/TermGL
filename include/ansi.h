#ifndef ANSI_H
#define ANSI_H

#include <cstdint>
#include <ostream>

struct RGB 
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
    
    bool operator==(RGB other) const noexcept
    {
        return R == other.R
            && G == other.G
            && B == other.B;
    }
};

class AnsiManager
{
    // Ansi chars to delete things
    static inline constexpr const char* ClearScreenAndBuffer    = "\x1b[3J";
    static inline constexpr const char* ResetCursorTopRight     = "\x1b[H";

    // color defaults
    const RGB defaultForegroundColor;
    const RGB defaultBackgroundColor;

    // color cache
    RGB foregroundColor;
    RGB backgroundColor;

public:
    /** Creates Ansi Manager object. If no specified default foreground and background colors,
     *  set the default foreground as white and default background as black.
     */
    AnsiManager(RGB defaultForegroundColor = RGB { 255, 255, 255 }, RGB defaultBackgroundColor = RGB { 0, 0, 0 });

    /** Set foreground color to corresponding color
     */
    void setForegroundColor(std::ostream& stream, RGB color);

    /** Set background color to corresponding color
     */
    void setBackgroundColor(std::ostream& stream, RGB color);

    /** Set foreground color to default foreground color
     */
    void resetForegroundColor(std::ostream& stream);

    /** Set background color to default background color
     */
    void resetBackgroundColor(std::ostream& stream);

    /** Clear screen and scroll buffer
     */
    void resetScreen(std::ostream& stream);
};

#endif
