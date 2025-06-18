#ifndef THEMES_H
#define THEMES_H

#include "imgui.h"

// In Themes.h
enum class ColorType {
    Primary,        // Deep blue
    PrimaryLight,   // Lighter blue
    Secondary,      // Dark gray
    SecondaryLight, // Medium gray
    Accent,         // Teal accent
    AccentLight,    // Light teal
    Text,           // White
    TextLight,      // Light gray
    Success,        // Green
    Warning,        // Orange
    Error,          // Red
    Highlight       // Bright blue
};

class Themes {
public:
    static void SetDarkTheme();
    static void SetLightTheme();
    static ImVec4 GetColor(ColorType type);
};

#endif // THEMES_H