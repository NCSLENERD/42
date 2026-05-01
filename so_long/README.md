*This project has been created as part of the 42 curriculum by nmayela.*

# so_long

## Description

`so_long` is a small 2D top-down game built with the school's graphical
library, the **MiniLibX**. The player navigates a map, collects every
collectible, and reaches the exit using the shortest path possible.

The project focuses on:

- Window and event handling (keyboard, window close, expose).
- Map parsing and validation.
- Pathfinding (flood fill) to guarantee the map is solvable.
- Strict memory management — every allocation is freed on a clean exit.

I inspire my so_long from pacman.

### Map format

A map is a `.ber` file using only these characters:

| Char | Meaning             |
|------|---------------------|
| `0`  | Empty space (floor) |
| `1`  | Wall                |
| `C`  | Collectible         |
| `E`  | Exit                |
| `P`  | Player start        |

A valid map must:

- Be **rectangular**.
- Be **enclosed by walls** on all sides.
- Contain **exactly one** `P`, **exactly one** `E`, and **at least one** `C`.
- Have a **valid path** from `P` to every `C` and to `E` (verified via flood fill).

Example (`test.ber`):

```
11111111111111111111
10000000C00000011111
10010111110000011111
10010000C0000P011111
1001000000000E011111
10001111101100000C11
11111111111111111111
```

If any rule is broken, the program prints `Error\n` followed by an explicit
message, frees everything, and exits cleanly.

## Instructions

### Requirements

- Linux (the project is linked against `libmlx.a`, `Xext` and `X11`).
- `cc`, `make`, and the standard X11 development headers.

### Compilation

```sh
make
```

The Makefile first builds the bundled MiniLibX (`minilibx-linux/`) and then
compiles the project. Available rules:

| Rule     | Effect                                  |
|----------|-----------------------------------------|
| `all`    | Default — builds `so_long`              |
| `clean`  | Removes object files                    |
| `fclean` | Removes object files and the binary     |
| `re`     | `fclean` + `all`                        |

Compiled with `-Wall -Wextra -Werror`.

### Run

```sh
./so_long your_map.ber
```

Exactly one argument is expected: the path to a `.ber` map file.

### Controls

| Key                    | Action       |
|------------------------|--------------|
| `W` / `↑`              | Move up      |
| `S` / `↓`              | Move down    |
| `A` / `←`              | Move left    |
| `D` / `→`              | Move right   |
| `ESC`                  | Quit         |
| Window close button    | Quit         |

Each move increments the move counter, which is printed in the terminal.
Reaching the exit with all collectibles picked up triggers a victory message
and a clean exit.

## Project structure

```
so_long/
├── Makefile
├── so_long.h
├── so_long.c          # entry point, init, main loop
├── events.c           # key, close, expose hooks + movement
├── render.c           # texture loading and map rendering
├── parse_map.c        # reads the .ber file into a 2D grid
├── verif_struct.c     # rectangular shape + wall borders
├── verif_content.c    # allowed chars + P/E/C counts
├── flood_fill.c       # solvability check
├── utils.c            # helpers + cleanup (free_game, error_exit)
├── ft_printf/         # custom printf
├── get_nextline/      # line-by-line file reader
├── minilibx-linux/    # bundled MiniLibX
└── textures/          # XPM sprites (wall, floor, collect, player, exit)
```

## Resources
Header of minilibx

### AI usage

Used to verify my code once done , also ask about some syntaxes.
