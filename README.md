# Loading-Screen-C-Lib 🚀

[![C99](https://img.shields.io/badge/C-99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Production Ready](https://img.shields.io/badge/Status-Production--Ready-brightgreen.svg)]()

A lightweight, high-performance, and professional loading screen library for C and C++. Enhance your CLI applications with beautiful progress bars and spinners.

https://github.com/user-attachments/assets/7a509343-8a72-45a4-9044-4fb837320f5b

## ✨ Features

- **Multiple Styles**: Blocks, Equals, Dots, Smooth Unicode, Braille, and more.
- **Indeterminate Spinners**: For tasks where progress is unknown.
- **Color Support**: ANSI-based color presets.
- **Cross-Platform**: Robust support for Linux, macOS, and Windows (via Virtual Terminal Processing).
- **Customizable**: Control width, position, delay, and labels.
- **Production Ready**: Clean API, no global namespace pollution, and robust error handling.

## 📦 Installation

### Using CMake

```bash
mkdir build && cd build
cmake ..
make
sudo make install
```

### Using Makefile

```bash
make
./loading_demo
```

## 🚀 Quick Start

```c
#include "loading_screen.h"

int main() {
    ls_init(); // Initialize terminal

    ls_config_t config = ls_get_default_config();
    config.label = "Downloading data";
    config.type = LS_TYPE_SMOOTH;
    config.color = LS_COLOR_GREEN;

    ls_display(&config, 100);

    ls_cleanup(); // Restore terminal
    return 0;
}
```

## 🎨 Loading Bar Types

| Type | Appearance | Description |
|------|------------|-------------|
| `LS_TYPE_BLOCKS` | `[####  ]` | Classic block style |
| `LS_TYPE_SMOOTH` | `[████  ]` | Modern Unicode smooth blocks |
| `LS_TYPE_BRAILLE`| `[⣿⣿⣿  ]` | Professional Braille dots |
| `LS_TYPE_SPINNER`| `/` | Circular indeterminate spinner |

## 🛠️ Configuration Options

The `ls_config_t` struct allows full control:

```c
typedef struct {
    ls_type_t type;       // Style type
    ls_color_t color;     // ANSI color
    int width;            // Width of the bar
    int x, y;             // Position (0 for current)
    int delay_ms;         // Speed of animation
    int show_percentage;  // Show % text
    const char* label;    // Prefix text
    int use_arrow;        // Add '>' to progress
} ls_config_t;
```

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
