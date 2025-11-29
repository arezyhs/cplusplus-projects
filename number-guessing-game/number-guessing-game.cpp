#include <iostream>
#include <ctime>
using namespace std;

int main() { 
    srand(time(0));
    int nilaiBenar = rand() % 100 + 1;
    int nilaiTebakan;
    
    cout << "Tebak angka yang benar!" << endl;

    for (int i = 1; i <= 15; i++) {
        cin >> nilaiTebakan;
        if (nilaiTebakan < nilaiBenar) {
            cout << "terlalu kecil" << endl;
        } else if (nilaiTebakan > nilaiBenar) {
            cout << "terlalu besar" << endl;
        } else {
            cout << "Selamat! Tebakan anda benar!" << endl;
            break;
        }
    }
    
    if (nilaiTebakan != nilaiBenar) {
        cout << "Maaf, kesempatan kamu habis. Jawaban yang benar adalah: " << nilaiBenar << endl;
    }
    
    return 0;
}
