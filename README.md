# Mouse vs Doubao

**Personal learning project, not related to any official product**

A small, playful desktop game prototype built with C++ and SFML, where the player uses the mouse to interact with a character named Doubao in a simple survival-style loop.

This project is designed as a learning-focused, lightweight game experiment and is not affiliated with any official product or brand.

## Overview

`Mouse vs Doubao` is a mini-game built in C++17 using the SFML 3.1.0 framework. The character reacts to the cursor in real time: when the mouse is close, Doubao flees; when the mouse is farther away, it approaches. If the cursor gets too near, Doubao starts losing HP. Meanwhile, Doubao fights back by firing cannonballs toward the cursor. The match ends when either side reaches zero HP.

The project combines simple game logic, real-time motion, collision handling, and a tiny HUD into a compact, runnable prototype.

## Key Features

- Mouse-driven interaction system
- Dynamic movement based on cursor distance and angle
- HP-based combat and game-over conditions
- Projectile shooting mechanic from Doubao toward the mouse
- Window-bound movement and collision constraints
- HUD with HP display and gameplay tips
- Windows-specific IME handling for a smoother input experience
- Offline local SFML dependency bundled in the repository

## Gameplay Loop

- The mouse cursor acts as the opponent or external force.
- Doubao continuously evaluates its position relative to the cursor.
- At close range, it moves away.
- At longer range, it moves toward the cursor.
- If the cursor stays too near, Doubao loses health over time.
- Doubao periodically launches cannonballs to damage the mouse.
- The game ends when either Doubao or the mouse reaches 0 HP.
- Press `Esc` to exit.

## Project Structure

```text
Mouse vs Doubao/
├── CMakeLists.txt              # Build configuration for C++17 and SFML
├── main.cpp                    # Main loop, window setup, HUD, and input handling
├── doubao.h / doubao.cpp       # Doubao character logic and behavior
├── mouse.h / mouse.cpp         # Mouse state and HP tracking
├── cannonball.h / cannonball.cpp # Projectile logic
├── math_utils.h / math_utils.cpp # Distance and angle helper functions
├── res/                        # Game assets (textures and font)
├── thirdparty/
│   └── SFML-3.1.0/            # Bundled SFML 3.1.0 library
├── build/                      # Generated build output
├── output/                     # Reserved output folder
├── .gitignore                  # Ignored generated/editor files
├── README.md                   # Project documentation
├── .vscode/                    # Editor configuration
└── .gitignore
```

## Technical Highlights

- Built in **C++17**
- Uses **SFML 3.1.0** for rendering and input
- Uses **CMake** for project configuration and build generation
- Includes local asset support under the `res/` folder
- Contains Windows-only IME disable/restore logic for smoother keyboard behavior during focus changes

## Main Components

- `Doubao`
  - Controls sprite rendering, health, death state, and movement behavior
  - Manages projectile spawning and window boundary checks
- `Mouse`
  - Tracks cursor-related HP and pointer state
- `Cannonball`
  - Represents projectiles fired by Doubao
  - Moves toward the mouse and reduces HP on contact
- `math_utils`
  - Provides geometric calculations for distance and angle used by the game logic

## Build and Run

### Requirements

- CMake 3.20 or newer
- A compatible C++ compiler
- SFML 3.1.0, already bundled in `thirdparty/SFML-3.1.0`

### Build Steps

1. Configure the project with CMake.
2. Build the target `MouseVsDoubao`.
3. Run the generated executable from the build output folder.

Typical Windows output paths:

```text
build/Debug/MouseVsDoubao.exe
build/Release/MouseVsDoubao.exe
```

### Runtime Assets

The project loads required assets from the `res/` directory, including:

- `doubao.png`
- `doubao_death.png`
- `cannonball.png`
- `Inter-var-2.ttf`

## Why This Project

This repository is a compact example of how a small game can be built from scratch using modern C++ and a lightweight graphics framework. It focuses on:

- game loop design
- character movement logic
- health and combat systems
- geometric calculations for entity behavior
- simple object-oriented code organization

It is intentionally lightweight and approachable, making it suitable as a personal learning project or a base for further expansion.

## Notes

- This project is intended for experimentation and learning.
- Generated files under `build/` are typically not tracked by Git.
- Asset files in `res/` are part of the runtime content and are kept alongside the project source.
- The project is still evolving and can serve as a starting point for richer gameplay features in the future.

## License and Status

This project is a personal learning prototype and does not currently declare a formal open-source license. It is shared as a code sample and creative experiment rather than a production-grade game product.
