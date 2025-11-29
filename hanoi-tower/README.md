# Hanoi Tower

<h2>Introduction:</h2>
This repository contains an implementation of the Tower of Hanoi problem in C++. The Tower of Hanoi is a classic mathematical puzzle that involves moving a stack of disks from one peg (tower) to another, subject to the constraint that only one disk can be moved at a time and no disk can be placed on top of a smaller disk.

<h2>Code Overview!</h2>
The main implementation of the Tower of Hanoi problem is encapsulated in the menaraHanoi function. The function takes four parameters: n (the number of disks), menaraAwal (the source tower), menaraTengah (the auxiliary tower), and menaraAkhir (the destination tower).

<h2>Recursive Approach</h2>
The solution employs a recursive approach to solve the Tower of Hanoi problem. When the number of disks (n) is equal to 1, the function prints a message indicating the move of the disk from the source tower to the destination tower. Otherwise, it recursively moves n-1 disks from the source tower to the auxiliary tower, then moves the remaining disk to the destination tower, and finally, recursively moves the n-1 disks from the auxiliary tower to the destination tower.

<h2>User Interaction</h2>
The main function prompts the user to input the number of disks (n) they would like to solve the Tower of Hanoi problem for. It then calls the menaraHanoi function with the specified parameters and displays the sequence of moves required to solve the problem.

<h2>Usage</h2>
To use the program, compile the source code and run the executable. Enter the desired number of disks when prompted, and the program will output the step-by-step instructions to solve the Tower of Hanoi problem for the specified number of disks.

Feel free to explore, modify, and build upon this implementation as needed. Contributions and improvements are welcome. Happy coding!
