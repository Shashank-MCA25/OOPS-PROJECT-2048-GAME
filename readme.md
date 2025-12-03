# 2048 Game in C++

A fully modular and terminal-based implementation of the classic **2048 puzzle game**, written in **C++**.  
This project uses clean object-oriented design with separate files for **Game**, **Board**, and **Utility** functions.

---

## 📌 Features

- 4×4 grid, classic 2048 gameplay  
- Supports movement using **W / A / S / D**  
- Automatic merging and sliding of tiles  
- Random tile generation (2 or 4) after every valid move  
- Win detection (2048 reached)  
- Game-over detection  
- Clean modular structure:
  - `Game` → Handles input + main loop  
  - `Board` → Grid, movement, merging logic  
  - `Utils` → Helper functions (clear screen, random values)

---




---

## ▶️ How to Compile & Run

### **Using g++ (MinGW / Linux / macOS)**

Navigate to the project folder:

```bash
cd project

Compile:    g++ main.cpp src/*.cpp -o game

Run:    ./game

On Windows PowerShell

cd project
g++ main.cpp src/*.cpp -o game.exe
./game.exe

🎮 Controls
Key	Action
W	Move Up
A	Move Left
S	Move Down
D	Move Right
Q	Quit Game

🧩 How the Game Works

Tiles slide in the input direction.

Adjacent tiles with the same value merge.

After every move, a new tile (2 or 4) appears.

You win when a 2048 tile is created.

Game ends when no moves remain.

🛠️ Requirements

C++11 or higher

g++ or any standard C++ compiler

Optional:

Windows users need <conio.h> (handled with #ifdef _WIN32).

🧑‍💻 Authors
Made by Shashank, Sumit Rai.
