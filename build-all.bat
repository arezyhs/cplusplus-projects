@echo off
echo Building C++ Projects Collection...
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

echo Building Network Traffic Monitoring...
cd network-traffic-monitoring
g++ networkTrafficMonitoringSimulation.cpp -o networkTrafficMonitoringSimulation.exe
g++ networkTrafficMonitoringSimulationTanpaGraf.cpp -o networkTrafficMonitoringSimulationTanpaGraf.exe
cd ..

echo Building Library Management System...
cd library-management
g++ library-management.cpp -o library-management.exe
g++ praktikum-akhir-data.cpp -o praktikum-akhir-data.exe
cd ..

echo Building RPG Adventure Game...
cd rpg-game
g++ final-project-adventure-rpg.cpp -o final-project-adventure-rpg.exe
cd ..

echo Building ID Generator Calculator...
cd id-generator-calc
g++ id-generator-supir-plus-pesanan.cpp -o id-generator-supir-plus-pesanan.exe
g++ id-generator-supir-saja.cpp -o id-generator-supir-saja.exe
cd ..

echo.
echo All projects have been built successfully!
echo.
echo To run the programs:
echo - Breach the Fortress: breach-the-fortress\breach-the-fortress.exe
echo - Number Guessing Game: number-guessing-game\number-guessing-game.exe  
echo - Hanoi Tower: hanoi-tower\hanoi-tower.exe
echo - Network Traffic Monitoring: network-traffic-monitoring\networkTrafficMonitoringSimulation.exe
echo - Network Traffic Monitoring (No Graph): network-traffic-monitoring\networkTrafficMonitoringSimulationTanpaGraf.exe
echo - Library Management: library-management\library-management.exe
echo - Library Data Practice: library-management\praktikum-akhir-data.exe
echo - RPG Adventure Game: rpg-game\final-project-adventure-rpg.exe
echo - ID Generator (Driver + Order): id-generator-calc\id-generator-supir-plus-pesanan.exe
echo - ID Generator (Driver Only): id-generator-calc\id-generator-supir-saja.exe
echo.
pause