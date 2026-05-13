#include "loading_screen.h"
#include <stdio.h>

int main() {
    if (ls_init() != 0) return 1;

    ls_config_t config = ls_get_default_config();
    config.width = 30;
    config.delay_ms = 10;
    config.stay_on_line = 1;

    config.label = "Step 1/3"; config.color = LS_COLOR_YELLOW;
    ls_display(&config, 100);

    config.label = "Step 2/3"; config.color = LS_COLOR_CYAN;
    ls_display(&config, 100);

    config.label = "Step 3/3"; config.color = LS_COLOR_GREEN;
    ls_display(&config, 100);

    printf("\n\nTask complete. Starting temporary cleanup demo...\n");
    
    config.label = "Deleting temp files";
    config.color = LS_COLOR_RED;
    config.clear_on_finish = 1;
    ls_display(&config, 100);

    printf("Success: All temporary indicators cleared.\n");

    ls_cleanup();
    return 0;
}
