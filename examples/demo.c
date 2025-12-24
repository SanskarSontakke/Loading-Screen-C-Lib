#include <stdio.h>
#include "../include/loading_screen.h"

int main(void)
{
    printf("Demo of Loading Screen Library\n\n");

    // Type 1: Blocks (#)
    loading_screen(20, 50, 1, 5, 5, 1, 1);

    // Type 2: Equals (=) with arrow
    loading_screen(20, 50, 2, 5, 7, 2, 1);

    // Type 3: Greater than (>)
    loading_screen(20, 50, 3, 5, 9, 3, 1);

    // Type 4: Asterisk (*)
    loading_screen(20, 50, 4, 5, 11, 4, 1);

    // Type 5: Hyphen (-) with arrow
    loading_screen(20, 50, 5, 5, 13, 5, 1);

    printf("\n\nDone!\n");
    return 0;
}
