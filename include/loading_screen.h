#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Displays a loading screen (progress bar) in the console.
 *
 * This function draws a progress bar at the specified coordinates in the console window.
 * It supports different styles and colors.
 *
 * @param no_of_sections Number of sections (characters) in the progress bar.
 * @param delay_per_section Delay in milliseconds between each section update.
 * @param type The style of the progress bar (1-5).
 *             1: Blocks (#)
 *             2: Equals (=) with optional arrow
 *             3: Greater than (>)
 *             4: Asterisk (*)
 *             5: Hyphen (-) with optional arrow
 * @param x The X coordinate (column) to start drawing.
 * @param y The Y coordinate (row) to start drawing.
 * @param colour The color code (ANSI color code, 1-9 usually).
 *               1: Red, 2: Green, 3: Yellow, 4: Blue, 5: Magenta, 6: Cyan, 7: White
 * @param arrow If 1, adds an arrow head (>) to the progress bar (applicable for types 2 and 5).
 */
void loading_screen(int no_of_sections, int delay_per_section, int type, int x, int y, int colour, int arrow);

#ifdef __cplusplus
}
#endif

#endif // LOADING_SCREEN_H
