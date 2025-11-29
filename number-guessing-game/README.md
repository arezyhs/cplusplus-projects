# Number Guessing Game

<h2>Description</h2>
<p>This C++ program is a simple number guessing game. The program generates a random number between 1 and 100, and the player's task is to guess the correct number within a limited number of attempts.</p>

<h2>How to Play</h2>
<ol>
    <li>The program generates a random number between 1 and 100.</li>
    <li>The player is asked to guess the correct number.</li>
    <li>The player has a maximum of 15 attempts to guess the correct number.</li>
    <li>After each guess, the program provides feedback:
        <ul>
            <li>If the guess is lower than the correct number, it displays "terlalu kecil" (too small).</li>
            <li>If the guess is higher than the correct number, it displays "terlalu besar" (too big).</li>
            <li>If the guess is correct, it displays "Selamat! Tebakan anda benar!" (Congratulations! Your guess is correct!), and the game ends.</li>
        </ul>
    </li>
    <li>If the player runs out of attempts without guessing the correct number, the program displays the correct answer and a message: "Maaf, kesempatan kamu habis. Jawaban yang benar adalah: [correct number]."</li>
</ol>

<h2>How It Works</h2>
<ul>
    <li>The program uses the <code>srand</code> function to seed the random number generator based on the current time, ensuring a different random number each time you run the program.</li>
    <li>It generates a random number (<code>nilaiBenar</code>) between 1 and 100.</li>
    <li>The player's guesses (<code>nilaiTebakan</code>) are compared to the correct number.</li>
    <li>The player is given a maximum of 15 attempts to guess the correct number.</li>
    <li>The program provides feedback based on the player's guesses and eventually informs if the guess is correct or if the player has run out of attempts.</li>
</ul>

<h2>Note</h2>
<ul>
    <li>This program is a simple demonstration of a number guessing game and can serve as an educational and entertaining code example for beginners learning C++.</li>
    <li>You can modify the number range and the maximum number of attempts by changing the constants in the code to customize the game.</li>
</ul>

<p>Enjoy playing and learning with this number guessing game!</p>
