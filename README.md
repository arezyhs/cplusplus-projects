# C++ Projects Collection

## Overview

This repository contains a comprehensive collection of C++ console-based applications, including games, network simulations, data management systems, algorithmic calculators, and educational projects. All applications are designed to be simple, educational, and demonstrate various programming concepts and data structures.

## Projects Included

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

### 4. 🌐 Network Traffic Monitoring & Tree Topology
Advanced network simulation and monitoring system with graph-based visualization capabilities.

**Location:** `network-traffic-monitoring/`
**Features:**
- Network traffic monitoring simulation
- Tree topology network visualization
- Graph-based network representation
- Multiple simulation modes (with/without graphs)

### 5. 📚 Library Management System
Simple library management system for book cataloging and management operations.

**Location:** `library-management/`
**Features:**
- Book inventory management
- Data structure implementations
- Practice exercises for data manipulation
- Simple CRUD operations

### 6. ⚔️ RPG Adventure Game
Final project RPG game with character development and adventure mechanics.

**Location:** `rpg-game/`
**Features:**
- Character creation and development
- Adventure-based gameplay
- RPG mechanics implementation
- Interactive storytelling

### 7. 🆔 ID Generator Calculator
Advanced ID generation system for data structures lab with specific algorithmic rules for creating driver and order IDs.

**Location:** `id-generator-calc/`
**Features:**
- Driver ID generation based on name, gender, and birthdate
- Order ID generation including license plate and destination data
- Collision handling with automatic ID incrementing
- Support for both driver-only and driver+order ID generation
- Educational implementation of data structure algorithms

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
├── network-traffic-monitoring/
│   ├── networkTrafficMonitoringSimulation.cpp
│   ├── networkTrafficMonitoringSimulationTanpaGraf.cpp
│   ├── output/
│   └── README.md
├── library-management/
│   ├── library-management.cpp
│   ├── praktikum-akhir-data.cpp
│   └── README.md
├── rpg-game/
│   ├── final-project-adventure-rpg.cpp
│   └── README.md
├── id-generator-calc/
│   ├── id-generator-supir-plus-pesanan.cpp
│   ├── id-generator-supir-saja.cpp
│   └── README.md
├── build-all.bat
└── README.md
```

## How to Run

### Option 1: Build All Projects at Once
Run the build script to compile all projects:
```batch
build-all.bat
```

### Option 2: Build Individual Projects
1. Navigate to the specific project directory
2. Compile the C++ file: `g++ [filename].cpp -o [output_name]`
3. Run the executable: `./[output_name]` (Linux/Mac) or `[output_name].exe` (Windows)

### Examples:
```bash
# Network Traffic Monitoring
cd network-traffic-monitoring
g++ networkTrafficMonitoringSimulation.cpp -o simulation.exe
./simulation.exe

# Library Management
cd library-management
g++ library-management.cpp -o library.exe
./library.exe

# RPG Game
cd rpg-game
g++ final-project-adventure-rpg.cpp -o rpg.exe
./rpg.exe

# ID Generator Calculator
cd id-generator-calc
g++ id-generator-supir-plus-pesanan.cpp -o id-gen-full.exe
./id-gen-full.exe
```

## Author
- @arezyhs

## License

This project is licensed under the MIT License.
