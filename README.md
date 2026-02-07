Slot Machine (C++ / SFML)

Project Description

This project is a simple slot machine game written in C++ using the SFML (Simple and Fast Multimedia Library).
The program opens a graphical window with three slot reels represented as text symbols:
Cherry, Lemon, Bell, and 777.

The user can spin the slot machine by pressing a key, spend in-game currency, and win rewards based on the result.
The project demonstrates basic concepts of C++ programming, event handling, random number generation, and graphical rendering with SFML.

Controls

- SPACE
  - Start the game from the intro screen
  - Spin the slot machine (costs 200$)
- =
  - Display the total current balance
- Close window
  - Exit the program

Game Rules

- Each spin costs 200$
- 777 777 777 → Jackpot (+10000$)
- Any 3 identical symbols → Win (+1000$)
- Any other combination → Lose (no reward)

Requirements

To compile and run this project, you need:

- C++ compiler (supports C++17 or newer)
  - GCC / MinGW / MSVC
- SFML library (version 3.x or compatible)
- Windows OS (default font path uses Windows Arial font)

How to Compile

Install SFML

Download SFML from the official website:
https://www.sfml-dev.org/

Make sure SFML is correctly linked to your compiler.

---

Compile (Example using g++ / MinGW)

```bash
g++ main.cpp -o slot_machine -lsfml-graphics -lsfml-window -lsfml-system
