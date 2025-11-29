#include <iostream>
#include <ctime>
using namespace std;

/*
created by arezyhs
use the code as you want, but don't copy and paste it directly...
love u
*/

// recursive function to breach the wall
void breachWall(int cannons[], int N, int M, int index, int &totalPower, bool &breached) {
    if (index >= N || breached) {
        return;
    }
    totalPower = cannons[index] + cannons[index + 1];
    if (totalPower > M) {
        breached = true;
        cout << "You breached the wall with " << totalPower << " total power!" << endl;
        return;
    }
    breachWall(cannons, N, M, index + 1, totalPower, breached);
}

int main() {
    // random seed.
    srand(time(0));

    int N, totalPower = 0;
    int M = rand() % 501 + 750;  // Random value between 750 - 1250
    bool breached = false;

    // game instruction.
    system("cls");
    cout << "\t BREACH THE FORTRESS GAME" << endl;
    cout << "Instructions to play:" << endl;
    cout << "1. Input how many cannon(s) you want to bring." << endl;
    cout << "2. Input the explosion value of every cannon(s) you bring!" << endl;
    cout << "3. Enjoy!" << endl;
    system("pause");
    system("cls");

    cout << "We don't know the defense point of the Fortress because we are launching a surprise attack!" << endl;
    cout << "To breach the fortress, the sum of two cannons' explosion values must be greater than the defense point." << endl;
    cout << "Your strategy is to use 2 cannons together for every attack until the fortress is breached!" << endl;
    cout << "So... 1st and 2nd, then 2nd and 3rd cannon until you run out of cannon(s)" << endl;
    cout << "Let's get ready, general!" << endl;
    system("pause");
    system("cls");
    
    // input how many cannon(s) user bring.
    do {
        cout << "How many cannons do you want to bring to breach the Fortress (MAX is 10): ";
        cin >> N;
    } while (N <= 0 || N > 10);

    // input the value of explosion for every N cannon(s).
    int cannons[N];
    for (int i = 0; i < N; ++i) {
        cout << "Input the explosion of cannon #" << i + 1 << ": ";
        cin >> cannons[i];
    }

    // call the recursive function.
    breachWall(cannons, N, M, 0, totalPower, breached);

    // Output of the game.
    cout << "The fortress has " << M << " defense point!" << endl;
    if (breached) {
        cout << "You breached the mighty fortress!" << endl;
    } else {
        cout << "You failed to breach the mighty fortress!" << endl;
    }
    return 0;
}
