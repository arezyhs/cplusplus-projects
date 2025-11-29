@echo off
echo Building C++ Games Collection...
echo.

echo Building Breach the Fortress...
cd breach-the-fortress
g++ breach-the-fortress.cpp -o breach-the-fortress.exe
cd ..

echo Building Number Guessing Game...
cd number-guessing-game  
g++ number-guessing-game.cpp -o number-guessing-game.exe
cd ..

echo Building Hanoi Tower...
cd hanoi-tower
g++ hanoi-tower.cpp -o hanoi-tower.exe  
cd ..

echo.
echo All games have been built successfully!
echo.
echo To run the games:
echo - Breach the Fortress: breach-the-fortress\breach-the-fortress.exe
echo - Number Guessing Game: number-guessing-game\number-guessing-game.exe  
echo - Hanoi Tower: hanoi-tower\hanoi-tower.exe
echo.
pause