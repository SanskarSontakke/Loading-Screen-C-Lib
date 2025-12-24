# Loading Screen Library

This is a simple C library to display various styles of loading screens (progress bars) in the Windows console.

## Features

- **Multiple Styles**: Supports 5 different styles of progress bars.
- **Customizable**: Adjustable length, speed, position, and color.
- **Easy Integration**: Single header and source file.

## Directory Structure

```
.
├── src/
│   └── loading_screen.c    # Source code
├── include/
│   └── loading_screen.h    # Header file
└── examples/
    └── demo.c              # Usage example
```

## Requirements

- **Operating System**: Windows (uses `windows.h` and Windows Console API).
- **Compiler**: A C compiler that supports Windows API (e.g., MinGW, MSVC).

## Building

To build the example program, compile `src/loading_screen.c` and `examples/demo.c` together.

### Using GCC (MinGW)

```bash
gcc examples/demo.c src/loading_screen.c -o loading_screen_demo.exe -Iinclude
```

### Using MSVC

```cmd
cl examples/demo.c src/loading_screen.c /Fe:loading_screen_demo.exe /Iinclude
```

## Usage

Include `loading_screen.h` in your project and call the `loading_screen` function.

```c
#include "loading_screen.h"

int main() {
    // loading_screen(no_of_sections, delay, type, x, y, colour, arrow);
    loading_screen(20, 50, 1, 5, 5, 2, 0);
    return 0;
}
```

### Parameters

- `no_of_sections`: Length of the progress bar (number of characters).
- `delay_per_section`: Delay in milliseconds for each step.
- `type`: Style of the progress bar (1-5).
- `x`, `y`: Console coordinates (column, row).
- `colour`: ANSI color code (e.g., 1=Red, 2=Green).
- `arrow`: 1 to enable arrow head (for supported styles), 0 to disable.

## Styles

1. Blocks: `|#####|`
2. Equals: `|=====|` or `|====>|`
3. Arrows: `|>>>>>|`
4. Stars:  `|*****|`
5. Hyphens:`|-----|` or `|---->|`

## License

This project is open source.
