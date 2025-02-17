ASCII Retro Arcade Game in C

This project is inspired by the classic 1988 arcade game Contra, though it is not an exact replica due to resource limitations (it uses only CMD and Notepad). The game is completely coded in the C programming language and designed to resemble retro 8-bit arcade games with ASCII characters representing the environment, the player character, and enemies.

Overview

The game begins directly, much like traditional arcade games. The player controls a character, represented by the symbol &, that moves through a scenario loaded from a customizable text file. The text-based scenario can be edited and tailored by the player. The game operates in raw keyboard mode, where no need to press "Enter" is required to perform actions. The player can move using the WASD keys, jump, and shoot.

Game Mechanics

- Movement & Actions: The player can move left, right, and jump using the W, A, S, D keys. The character can shoot in two directions, represented by the symbols - and +.
- Enemies: Enemies, represented by the letter E, appear randomly and move towards the player. If an enemy touches the player, the game ends.
- Gravitation: The game features a basic gravity mechanic that makes the player character fall when there is no ground beneath them.
- Points & Score: The objective is to eliminate enemies that appear randomly, earning points with each enemy destroyed. The game continues indefinitely, following the arcade-style loop.
- Customizable Scenario: The environment is loaded from a text file, allowing players to modify and personalize the layout of the level.
- Sound: Basic sound effects are implemented using the Beep function.
- Animation: A simple animation plays when enemies are destroyed.
- Game Over: If the player exceeds the game’s boundaries, the game ends.
- Scoreboard: The game keeps track of the score and the number of enemies defeated.

Features

- Randomized Enemy Spawns: Enemies appear at random intervals and move towards the player.
- Endless Arcade Mode: The game continues indefinitely as long as the player avoids getting touched by enemies.
- Customizable Text-based Environment: The layout can be changed using a text file, enabling the player to design the game environment.
- Basic Sound Effects: Sounds are triggered during certain actions (e.g., shooting, enemy destruction).
- Gravity Mechanism: The character falls if no ground is beneath them, creating a dynamic experience.
- Simple Animation: Basic animations for enemy destruction.
- Keyboard Input: The game utilizes raw keyboard input with WASD keys for player control.

How to Play

1. Download the game files and open the project in a C compiler.
2. Run the game using a command-line interface (CMD).
3. Use the WASD keys to move the player, jump, and shoot.
4. Eliminate enemies to score points.
5. Avoid getting touched by enemies, or the game will end.
6. Customize the scenario by editing the text file used to load the level.

Installation

1. Ensure you have a C compiler installed (e.g., GCC, MinGW).
2. Download the project files.
3. Compile the C program with your preferred compiler.
4. Run the game from CMD.

Video

To see how the game looks in action, watch the video here: https://drive.google.com/file/d/1hJN9zY2toMXb4u7Hs9aCdd_crVSKjKCb/view?usp=sharing

Conclusion

This project is an attempt to recreate the feel of retro 8-bit arcade games using only ASCII text, with simple mechanics and customization options. It’s a fun exercise in C programming and a nostalgic throwback to the classic games of the 1980s.
