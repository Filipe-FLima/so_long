<h1 align=center>
  42 Cursus
 </h1>
<h2 align=center>
  so_long
</h2>

**so_long** is a simple 2D game project developed in C as part of the curriculum. The objective of the game is to collect all the collectibles (items) on the map and reach the exit door while avoiding obstacles and enemies. The game uses the **minilibx** (a minimal X-Window library) to handle graphics and inputs.

## Description

The primary objective of the **so_long** project is to develop a simple 2D game with specific rules and functionalities. The project aims to reinforce various programming concepts, including file handling, graphics rendering, and user input processing. It also provides a practical application for students to showcase their understanding of C programming and basic game development principles.

Completing the **so_long** project is not only a valuable learning experience but also an opportunity for students to showcase their coding skills and creativity in designing and developing a simple game from scratch using C.

## Installation

Before proceeding with the installation, make sure you have the following dependencies:

- GCC (GNU Compiler Collection)
- X11 libraries and development headers
- Minilibx a simple X-Window (X11R6)
- CMake (optional)

Follow the steps below to install and run the game:

1. Clone the repository to your local machine:

```bash
git clone https://github.com/Filipe-FLima/so_long.git
```

2. Compile the game:
```bash
make
```

3. Execute with a valid map:
```bash
./so_long maps/bigger_map.ber
```

You can replace **maps/bigger_map.ber** with any valid map file of your choice. The game will load the specified map, and you can start playing.

### Game Rules
- The player starts at the player spawn position ('P') and has to collect all the collectibles ('C') on the map.
- Avoid enemies ('G') and obstacles ('1') on the map, as touching them will result in a game over. The enemy (G) is automatically added to the map based on the number of empty spaces (0).
- The exit door ('E') will only appear once all the collectibles are collected.
- Reach the exit door to win the game.

## Controls

Use the following controls to navigate the player character:

- **Up Arrow**: Move the player up.
- **Down Arrow**: Move the player down.
- **Left Arrow**: Move the player left.
- **Right Arrow**: Move the player right.
- **ESC** or **Cross Button (X)**: Close the game.

## Enemy movements
- The enemy moves randomly across the map, even when the player remains idle. Additionally, the game includes a level-up mechanic that increases the enemy's movement speed based on the time the player takes to complete the game.

## Map Format

Maps for the game are stored in plain text files with the extension '.ber'. Each character represents a specific element on the map:

- **0**: Empty space (floor)
- **1**: Wall (obstacle)
- **P**: Player spawn position
- **C**: Collectible item
- **E**: Exit door

Example of valid map:

```text
111111111111
10C0000000C1
100001110001
100011000001
1P011E0000X1
111111111111
```

## Resources

- [minilibx](https://github.com/42Paris/minilibx-linux) - The minimal X-Window library used for graphics and inputs.
