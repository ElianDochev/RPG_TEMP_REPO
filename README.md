# My RPG - Game Project

This is an RPG game project developed using CSFML (C binding of SFML). The game features multiple states including a start menu, gameplay, pause menu, and game over screen.

## Prerequisites

Before running the game, you need to install the following dependencies:

- CSFML libraries (graphics, audio, window, system)
- GCC compiler
- Make

## Installation

### On Debian/Ubuntu:

```bash
sudo apt-get update
sudo apt-get install libcsfml-dev libcsfml-audio-dev libcsfml-graphics-dev libcsfml-system-dev libcsfml-window-dev libcsfml-network-dev
```

### On Fedora:

```bash
sudo dnf install CSFML CSFML-devel
```

### On Arch Linux:

```bash
sudo pacman -S csfml
```

### On macOS (using Homebrew):

```bash
brew install csfml
```

## Building the Game

1. Clone this repository:
```bash
git clone <repository-url>
cd RPG_TEMP_REPO
```

2. Compile the game using make:
```bash
make
```

This will compile the game and generate an executable named `my_rpg`.

## Running the Game

After successful compilation, run the game with:

```bash
./my_rpg
```

## Game Controls

- **Arrow Keys**: Move the player character
- **Space**: Attack
- **B**: Use bomb
- **P**: Pause/Unpause game
- **Esc**: Quit game
- **C**: Change map (debug feature)

## Game Features

- Start menu with options to play, view help, adjust settings, or quit
- Gameplay with character movement and combat
- Interactive map with various environments
- Enemy characters with basic AI
- Inventory system
- Pause menu with resume, inventory, and options
- Game over screen

## Project Structure

- source: Contains all source code files
- include: Contains header files
- resources: Contains game assets (textures, fonts, audio)
- maps: Contains map files for different game areas

## Troubleshooting

If you encounter issues with missing libraries, ensure that CSFML is properly installed on your system.

For graphics-related issues, check that your system supports the required OpenGL version.

## Credits

This project was developed by Eliyan DOCHEV, Marouan Bader and Valentin Scheller-Vidal

## License

This project is provided for educational purposes only under the MIT License. You are free to use, modify, and distribute the code as long as you include the original license in your copies or substantial portions of the software.

## WARNING
WHis project is part of EPITECH's curriculum so students of EPITECH beware of -42 rule, you are not allowed to use this code for your own project.