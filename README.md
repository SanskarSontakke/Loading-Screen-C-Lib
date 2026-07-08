# Loading-Screen-C-Lib

> A C library for rendering progress bars and spinners in the terminal.

[![C99](https://img.shields.io/badge/C-99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

https://github.com/user-attachments/assets/7a509343-8a72-45a4-9044-4fb837320f5b

## What it does

This library provides a simple API for displaying progress bars and spinners in CLI applications. It supports multiple visual styles (blocks, unicode, braille, spinner), ANSI colors, and customizable positioning and timing. You control width, labels, animation speed, and whether to show percentage text.

## Why I built it

To learn how to write clean, reusable C libraries with clear APIs. Most progress bar libraries are wrappers or language-specific; this one is native C with support for C++ via extern "C".

## Tech stack

- C99 (core library)
- CMake (optional build system)
- ANSI terminal escape codes (color and cursor control)

## Getting started

Clone and build with CMake:

```bash
git clone https://github.com/sanskarsontakke/loading-screen-c-lib.git
cd loading-screen-c-lib
mkdir build && cd build
cmake ..
make
sudo make install
```

Or build with Make:

```bash
git clone https://github.com/sanskarsontakke/loading-screen-c-lib.git
cd loading-screen-c-lib
make
./loading_demo
```

## How it works

Include the header and call three functions: `ls_init()` to set up the terminal, `ls_display()` to render a progress bar with a config struct, and `ls_cleanup()` to restore the terminal state. The config struct lets you pick a style (blocks, smooth Unicode, Braille dots, spinner), a color, width, position, and other display options. The library uses ANSI escape codes for cursor positioning and color, so it works on any modern terminal.

### Loading bar styles

| Type | Appearance | Description |
|------|------------|-------------|
| `LS_TYPE_BLOCKS` | `[####  ]` | Classic block style |
| `LS_TYPE_EQUALS` | `[====  ]` | Equals signs |
| `LS_TYPE_SMOOTH` | `[████  ]` | Unicode smooth blocks |
| `LS_TYPE_BRAILLE` | `[⣿⣿⣿  ]` | Braille dots |
| `LS_TYPE_SPINNER` | `/` | Indeterminate spinner |

### Usage example

```c
#include "loading_screen.h"

int main() {
    ls_init();

    ls_config_t config = ls_get_default_config();
    config.label = "Downloading";
    config.type = LS_TYPE_SMOOTH;
    config.color = LS_COLOR_GREEN;

    ls_display(&config, 100);

    ls_cleanup();
    return 0;
}
```

### Configuration

```c
typedef struct {
    ls_type_t type;           // Bar style
    ls_color_t color;         // ANSI color
    int width;                // Bar width
    int x, y;                 // Cursor position (0 = current)
    int delay_ms;             // Animation speed
    int show_percentage;      // Show % text
    const char* label;        // Prefix label
    int use_arrow;            // Add '>' to progress
    int clear_on_finish;      // Clear bar after done
    int stay_on_line;         // Keep bar when done
} ls_config_t;
```

## Results / status

Working library. Tested on Linux, macOS, and Windows (via Virtual Terminal Processing).

## License

MIT © 2026 Sanskar Sontakke
