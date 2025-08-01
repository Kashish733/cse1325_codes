# 💣 Boom! – A Text-Based Guessing Game

Boom! is a command-line guessing game built in C++. It reads puzzles from a file, applies character transformations, and provides interactive feedback. The game tests your pattern recognition and guessing skills under pressure — guess wrong, and you might hear a *boom*!

## 🎮 Gameplay
- The program selects a random puzzle from a file.
- Some characters are hidden or transformed.
- The player guesses characters one by one.
- Incorrect guesses trigger warning sounds and messages.
- The game continues until the puzzle is solved or you lose.

## 🧠 Learnings
- File I/O and data parsing in C++
- Class design and inheritance (`Firecracker`, `Puzzle`)
- Random selection using STL
- String manipulation and character transformations
- ANSI color formatting for terminal UI
- Use of STL containers and iterators

## 🛠️ Build Instructions
To compile and run the game:

```bash
make
./boom
