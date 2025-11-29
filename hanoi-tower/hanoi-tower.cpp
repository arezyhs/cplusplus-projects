/*
menara hanoi
*/

#include <iostream>
using namespace std;

void menaraHanoi(int n, char menaraAwal, char menaraTengah, char menaraAkhir) {
    if (n == 1) {
        cout << "Pindahkan balok ke-" << n << " dari " << menaraAwal << " ke " << menaraAkhir << endl;
        return;
    } menaraHanoi(n-1, menaraAwal, menaraAkhir, menaraTengah);
    cout << "Pindahkan balok ke-" << n << " dari " << menaraAwal << " ke " << menaraAkhir << endl;
    menaraHanoi(n-1, menaraTengah, menaraAwal, menaraAkhir);
}

int main() {
    int n;
    cout << "Masukkan jumlah N balok: ";
    cin >> n;
    menaraHanoi(n, 'A', 'B', 'C');
    return 0;
}