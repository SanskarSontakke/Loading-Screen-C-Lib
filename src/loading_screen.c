#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "../include/loading_screen.h"

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

// Static variables to hold console state
static HANDLE stdoutHandle;
static DWORD outModeInit;

/**
 * @brief Sets up the console for ANSI escape codes.
 */
static void setupConsole(void)
{
    DWORD outMode = 0;
    stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (stdoutHandle == INVALID_HANDLE_VALUE)
    {
        exit(GetLastError());
    }

    if (!GetConsoleMode(stdoutHandle, &outMode))
    {
        exit(GetLastError());
    }

    outModeInit = outMode;

    // Enable ANSI escape codes
    outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(stdoutHandle, outMode))
    {
        exit(GetLastError());
    }
}

/**
 * @brief Restores the console to its original state.
 */
static void restoreConsole(void)
{
    // Reset colors
    printf("\x1b[0m");

    // Reset console mode
    if (!SetConsoleMode(stdoutHandle, outModeInit))
    {
        exit(GetLastError());
    }
}

/**
 * @brief Sets the cursor position in the console.
 * @param x The X coordinate.
 * @param y The Y coordinate.
 */
static void setxy(int x, int y)
{
    COORD c;
    c.X = (SHORT)x;
    c.Y = (SHORT)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/**
 * @brief Delays execution for a specified number of milliseconds.
 * @param number_of_milli_seconds The delay duration.
 */
static void delay(int number_of_milli_seconds)
{
    Sleep((DWORD)number_of_milli_seconds);
}

void loading_screen(int no_of_sections, int delay_per_section, int type, int x, int y, int colour, int arrow)
{
    setupConsole();

    // Set text color
    printf("\033[0;3%dm", colour);
    // Hide cursor
    printf("\033[?25l");

    setxy(x, y);

    int _x = x;
    int _y = y;

    if (type == 1)
    {
        printf("|");
        for (int i = 1; i <= no_of_sections; i++)
        {
            x = x + 1;
            setxy(x, y);
            printf("#");
            delay(delay_per_section);
            setxy(_x + no_of_sections + 2, _y);
            printf("   %d", (i * 100) / no_of_sections);
        }
        setxy(x + 1, y);
        printf("|");
        printf("  100 ");
    }
    else if (type == 2)
    {
        printf("|");
        for (int i = 1; i <= (no_of_sections - 1); i++)
        {
            x = x + 1;
            setxy(x, y);
            printf("=");
            if (arrow == 1)
            {
                setxy((x + 1), y);
                printf(">");
            }
            delay(delay_per_section);
            setxy(_x + no_of_sections + 2, _y);
            printf("   %d", (i * 100) / no_of_sections);
        }
        setxy((x + 1), y);
        printf("=");
        printf("|");
        printf("  100 ");
    }
    else if (type == 3)
    {
        printf("|");
        for (int i = 1; i <= no_of_sections; i++)
        {
            x = x + 1;
            setxy(x, y);
            printf(">");
            delay(delay_per_section);
            setxy(_x + no_of_sections + 2, _y);
            printf("   %d", (i * 100) / no_of_sections);
        }
        setxy(x + 1, y);
        printf("|");
        printf("  100 ");
    }
    else if (type == 4)
    {
        printf("|");
        for (int i = 1; i <= no_of_sections; i++)
        {
            x = x + 1;
            setxy(x, y);
            printf("*");
            delay(delay_per_section);
            setxy(_x + no_of_sections + 2, _y);
            printf("   %d", (i * 100) / no_of_sections);
        }
        setxy(x + 1, y);
        printf("|");
        printf("  100 ");
    }
    else if (type == 5)
    {
        printf("|");
        for (int i = 1; i <= (no_of_sections - 1); i++)
        {
            x = x + 1;
            setxy(x, y);
            printf("-");
            if (arrow == 1)
            {
                setxy((x + 1), y);
                printf(">");
            }
            delay(delay_per_section);
            setxy(_x + no_of_sections + 2, _y);
            printf("   %d", (i * 100) / no_of_sections);
        }
        setxy((x + 1), y);
        printf("-");
        printf("|");
        printf("  100 ");
    }

    // Reset color
    printf("\033[0;37m");
    restoreConsole();
}
