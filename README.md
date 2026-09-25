# Mouse vs Doubao
**A personal learning project, not affiliated with any official product**
## 1. Project Overview

`Mouse vs Doubao` is a desktop interactive mini-game written in **C++17** and rendered with **SFML 3.1.0**. It draws a character named "Doubao" inside an 800×600 window. The player indirectly controls the character by moving the mouse: Doubao automatically moves based on its distance to the cursor — it flees when the mouse gets close and approaches when the mouse moves away. Once the cursor gets too close, Doubao's health points (HP) keep dropping until they reach zero, at which point it "dies" and stops moving.

The project (build target `MouseVsDoubao`) serves as a practical exercise in modern C++ and the new SFML 3 API.

## 2. Features

- Mouse-driven indirect movement with smart "flee / approach" logic
- Health system: HP starts at 100; touching the cursor drains HP per frame; at 0 HP, switches to the death texture and stops moving
- Real-time HUD: current HP shown top-left, operation tips at the bottom
- Boundary constraint: the character's position is clamped within the window
- Windows-specific optimization: auto-disables / restores the Input Method Editor (IME) on window focus gain/loss to prevent the Chinese IME popup from interfering
- Uses a locally bundled SFML 3.1.0 — no online download from GitHub required

## 3. Game Mechanics

| Mechanic | Description |
| --- | --- |
| Movement rule | Computes distance `dis` and angle to the mouse; displacement `moveDis = (200 - dis) × 0.05 × (-1)`. When `dis < 200` it moves away from the cursor; when `dis > 200` it moves toward the cursor |
| Rotation | Doubao always rotates to face the cursor (angle via `atan2`, with coordinate-axis special cases) |
| Damage | When the distance to the cursor is under 45, HP decreases by 1 per frame |
| Death state | At HP ≤ 0, switches to the death texture and stops moving |
| Boundary | Positions are clamped within the window's min/max bounds |

## 4. Technical Architecture

- **Language standard**: C++17 (`CMAKE_CXX_STANDARD 17`)
- **Build system**: CMake ≥ 3.20, generates a Visual Studio project (`MouseVsDoubao.slnx` / `.vcxproj`)
- **Rendering library**: SFML 3.1.0 (`Graphics`, `Audio` modules), provided locally under `thirdparty/`
- **Compiler option**: `/utf-8` to keep source strings correct
- **Platform adaptation**: `main.cpp` uses the `SFML_SYSTEM_WINDOWS` macro for Windows IME disable/restore (`ImmAssociateContext`)

**Core class: `Doubao`** (`doubao.h` / `doubao.cpp`)

- Encapsulates textures (normal & death), sprite, movement bounds and HP
- `move()`: computes distance and angle from the mouse, updates displacement, rotation and HP
- `inToWindow()`: clamps the position within the window bounds
- `draw()`: renders the sprite

## 5. Project Structure

```
Mouse vs Doubao/
├── CMakeLists.txt          # Build config (C++17 / SFML 3)
├── main.cpp                # Entry point, main loop, HUD, IME handling
├── doubao.h                # Doubao class declaration
├── doubao.cpp              # Doubao implementation (movement, HP, textures)
├── res/                    # Runtime assets: doubao.png, doubao_death.png, Inter-var-2.ttf
├── thirdparty/SFML-3.1.0   # Bundled SFML 3.1.0 dependency
├── build/                  # Build output (Debug / Release exe)
├── .vscode/                # Editor configuration
└── .gitignore              # Ignores .vscode/, build/, output/
```

## 6. Build & Run

1. Configure the project with CMake, pointing at the bundled `thirdparty/SFML-3.1.0` (pre-set via `CMAKE_PREFIX_PATH` in `CMakeLists.txt`)
2. Generate and build the Visual Studio project to obtain `MouseVsDoubao.exe` (`build/Debug` or `build/Release`)
3. Runtime assets are loaded from the `res/` folder (`doubao.png`, `doubao_death.png`, `Inter-var-2.ttf`), which is tracked in Git and present right after cloning
4. Launch and move the mouse to interact with Doubao

> Note: build outputs live under `build/`, which is ignored by `.gitignore` and therefore not tracked in Git. Runtime assets live under `res/` and are tracked in Git.

## 7. Development Status & Roadmap

**Git commits:**

- `81e1975` init — project initialized
- `8d3a789` fix path format in .gitignore
- `22d5dc1` implement movement and HP — added character movement logic and the health system
- `74f9bfe` rename project to `MouseVsDoubao`, update build target, add project introduction
- `8603697` add disclaimer to README (personal learning project, not affiliated with any official product)
- `91ae380` move runtime assets into a dedicated `res/` folder

**Possible extensions:**

- Add game audio (the project already links SFML's `Audio` module)
- Add score, levels or a timer to enrich gameplay
- Parameterize the movement rule (distance threshold, speed factor) for tuning
- Define the purpose of the `output/` directory
