# Tic Tac Toe in C

A simple and interactive console-based Tic Tac Toe game written in C.  
This project supports two-player gameplay, input validation, replay functionality, automatic turn handling, and winner detection.

---

## Features

- Two-player mode
- Dynamic first-player system
- Automatic next starter selection:
  - Loser starts next match
  - In case of draw, the player who played second starts next
- Input validation
- Invalid move detection
- Replay option
- Exit feature during gameplay
- Clean modular code structure
- Console board visualization

---

## Game Rules

- Player 1 uses **X**
- Player 2 uses **O**
- Players enter row and column positions to place marks
- First player to align 3 symbols horizontally, vertically, or diagonally wins
- If all cells are filled without a winner, the game ends in a draw

---

## Controls

### Enter Move

Players enter moves using:

row column

Example:

2 3

This places the mark at:
- Row 2
- Column 3

---

### Exit Game

To exit the current game during gameplay:

0 0

---

## Project Structure

Tic-Tac-Toe/
│
├── tictactoe.c
├── README.md
└── .gitignore

---

## How to Compile and Run

### Using GCC

Compile:

gcc tictactoe.c -o game

Run on Windows:

game.exe

Run on Linux / MacOS:

./game

---

## Example Gameplay

Welcome to Tic Tac Toe

Enter Your Names:
Alice Bob

Alice is X and Bob is O

-------------
|   |   |   |
-------------
|   |   |   |
-------------
|   |   |   |
-------------

Alice (X), enter your move:
1 1

---

## Concepts Used

- Functions
- Arrays
- Loops
- Conditional statements
- Input validation
- Modular programming
- Game logic implementation

---

## Future Improvements

Possible future upgrades:

- Single-player AI mode
- Minimax algorithm
- Scoreboard system
- Colored console output
- Dynamic board size
- GUI version
- Online multiplayer

---

## Author
Akidul Islam Jim

GitHub Repository:
https://github.com/JimIITDU/Tic-Tac-Toe

---

## License

This project is open-source and available under the MIT License.