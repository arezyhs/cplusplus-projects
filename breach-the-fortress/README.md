# Breach the Fortress Game

## Introduction

Welcome to the "Breach the Fortress" game! This console-based game allows players to breach a fortress using a strategic combination of cannons. Your goal is to bring down the fortress by pairing the explosion values of two cannons until the fortress is breached.

## How to Play

1. **Input Cannons:** Enter the number of cannons you want to bring to breach the fortress (maximum is 10).
2. **Explosion Values:** Input the explosion value for each cannon. The maximum explosion value for each cannon is 500.
3. **Breach Strategy:** The game will attempt to breach the fortress by combining the explosion values of consecutive cannons.
4. **Outcome:** Find out whether you successfully breached the mighty fortress or if you failed in your attempt.

## How to Run

1. Open a terminal in this directory.
2. Compile the code: `g++ breach-the-fortress.cpp -o breach-the-fortress`
3. Run the executable: `./breach-the-fortress` (Linux/Mac) or `breach-the-fortress.exe` (Windows)

## Game Logic

- The fortress has a random defense value between 750-1250 points
- You use consecutive pairs of cannons (1st+2nd, then 2nd+3rd, etc.)
- If any pair's combined explosion value exceeds the fortress defense, you win!
- The game uses recursion to check all possible cannon combinations

## Author
- @arezyhs

## License

This project is licensed under the MIT License.