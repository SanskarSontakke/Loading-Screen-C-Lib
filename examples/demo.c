#include <stdio.h>
#include "../include/loading_screen.h"

int main(void)
{
    printf("Demo of Loading Screen Library\n\n");

    // Type 1: Blocks (#)
    loading_screen(20, 50, 1, 5, 5, LOADING_COLOR_RED, 1);

    // Type 2: Equals (=) with arrow
    loading_screen(20, 50, 2, 5, 7, LOADING_COLOR_GREEN, 1);

    // Type 3: Greater than (>)
    loading_screen(20, 50, 3, 5, 9, LOADING_COLOR_YELLOW, 1);

    // Type 4: Asterisk (*)
    loading_screen(20, 50, 4, 5, 11, LOADING_COLOR_BLUE, 1);

    // Type 5: Hyphen (-) with arrow
    loading_screen(20, 50, 5, 5, 13, LOADING_COLOR_MAGENTA, 1);

    printf("\n\nDone!\n");
    return 0;
}
