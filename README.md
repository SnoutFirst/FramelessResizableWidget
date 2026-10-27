# FramelessResizableWidget

A small Qt Widgets demo: a frameless top-level window that can be resized by
dragging near its edges.

## Requirements

- CMake 3.16 or newer
- A C++17 compiler
- Qt 6 or Qt 5 with the `Widgets` module (`qt6-base-dev` / `qtbase5-dev`)

## Build and run

```sh
cmake -S . -B build
cmake --build build
./build/FramelessResizableWidget
```

Press `Esc` to quit.

## License

MIT — see `LICENSE`. Copyright (c) 2026 d3fault.
