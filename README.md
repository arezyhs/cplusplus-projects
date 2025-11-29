# C++ Games Collection

## Overview

This repository contains a collection of C++ console-based games, including strategy, puzzle, and guessing games. All games are designed to be simple, educational, and fun to play.

## Games Included

### 1. 🏰 Breach the Fortress
A strategic game where you use cannons to breach a fortress. Combine explosion values of consecutive cannons to overcome the fortress defense.

**Location:** `breach-the-fortress/`
**Features:** 
- Strategic gameplay with up to 10 cannons
- Random fortress defense values (750-1250)
- Recursive algorithm for checking combinations

### 2. 🔢 Number Guessing Game  
A classic guessing game where players try to guess a random number between 1-100 within 15 attempts.

**Location:** `number-guessing-game/`
**Features:**
- 15 attempts to guess correctly
- Real-time feedback (too high/too low)
- Support for both English and Indonesian

### 3. 🗼 Hanoi Tower
The classic Tower of Hanoi puzzle implementation with recursive solution display.

**Location:** `hanoi-tower/`
**Features:**
- Variable number of disks
- Step-by-step solution display
- Educational recursive algorithm demonstration

## Project Structure

```
├── breach-the-fortress/
│   ├── breach-the-fortress.cpp
│   └── README.md
├── number-guessing-game/
│   ├── number-guessing-game.cpp
│   └── README.md
├── hanoi-tower/
│   ├── hanoi-tower.cpp
│   └── README.md
├── build-all.bat
└── README.md
```

## How to Run Any Game

1. Navigate to the specific game directory
2. Compile the C++ file: `g++ [filename].cpp -o [output_name]`
3. Run the executable: `./[output_name]` (Linux/Mac) or `[output_name].exe` (Windows)

## Author
- @arezyhs

## License

This project is licensed under the MIT License.
