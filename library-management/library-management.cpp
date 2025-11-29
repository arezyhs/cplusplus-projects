#include <iostream>
#include <string>
#include <iomanip>

// standar Kerja (?)
// 1. Tree -> untuk pencarian buku ('TreeNode' <saling berhubungan> 'insertBuku karo 'cariBukuTree'
// 2. Rekursi -> pencarian buku di dalam pohon biner(?) 'cariBukuTree'
// 3. Graph -> struktur data graf 'Graph' + 'GraphNode' + ISBN buku saling terkoneksi
// 4. Searching -> fungsi pencarian BST 'cariBukuBinarySearch'
// 5. CH&HT -> masukin pengguna 'insertUser' 'searchUser'
// 6. Sorting -> urut sesuai abjad, 'urutkanBukuByAbjad' pake ubbleSort

// Landing Page
// 1. LOGIN // 2. REGISTER // 3. KELUAR

// Menu Admin
// 1. Tambah Buku, 2. Ubah Data Buku
// 3. Hapus Buku, 4. Lihat Daftar Buku
// 5. Lihat Daftar Transaksi, 6. Cari Buku
// 0. Logout

// Menu User
// 1. Cari buku, 2. Lihat Daftar Buku
// 3. Lihat Daftar Buku A - Z, 4. Pinjam Buku
// 5. Kembalikan Buku, 0. Logout

using namespace std;
string username;

// struktur buku
struct Buku { // masuk ke tree // masuk ke BukuAbjad
    string judul;
    string penulis;
    int tahun;
    string genre;
    string ISBN; // masuk ke GraphNode
    bool status; // true jika dipinjam, false jika tersedia
    int jumlah;
    Buku *next;
    Buku *prev;
};

struct BukuAbjad {
    Buku* head;
    BukuAbjad* next;
};

// struktur pengguna (admin dan user)
struct Pengguna {
    string username;
    string password;
    bool isAdmin; // yang membedakan privilegesnya.
    Pengguna *next;
};

struct Transaksi {
    string username;
    string ISBN;
    string tanggalPinjam;
    string tanggalKembali;
    Transaksi *next;
};

// struct node tree/pohon untuk pencarian buku
struct TreeNode {
    Buku *buku;
    TreeNode *left;
    TreeNode *right;
};

// struct graph....
struct GraphNode {
    string ISBN;
    GraphNode *next;
    Buku *buku;
};

struct Graph {
    GraphNode *head;
};

// hash Table untuk manajemen pengguna
const int TABLE_SIZE = 100;
Pengguna* hashTable[TABLE_SIZE];

Buku *headBuku = nullptr;
Pengguna *headPengguna = nullptr;
Transaksi *headTransaksi = nullptr;
TreeNode *rootBuku = nullptr;
Graph *bookGraph = nullptr;

// Di bawah ini adalah prototipe dari setiap fungsi yang ada di aplikasi perpus ini :)))))
// Fungsi-fungsi untuk manajemen pengguna
void insertUser(string username, string password, bool isAdmin);
Pengguna* searchUser(string username, string password);
void registerUser();

// Fungsi-fungsi untuk manajemen buku
void tambahBuku(string judul, string penulis, int tahun, string genre, string ISBN, bool status, int jumlah);
void tambahTransaksi(string username, string ISBN, string tanggalPinjam, string tanggalKembali);
void lihatDaftarBukuAdmin();
void lihatDaftarBukuUser();
void pinjamBuku(string username);
void kembalikanBuku();
Buku* cariBuku(string judul);
void hapusBuku(string judul);
void cariBukuBinarySearch();

// fungsi-fungsi untuk manajemen tree buku
void insertBuku(TreeNode *&root, Buku *buku);
TreeNode* cariBukuTree(TreeNode *root, string judul);

// fungsi-fungsi untuk manajemen transaksi
void lihatDaftarTransaksi();

// Fungsi-fungsi untuk struktur data lainnya
void tambahGraphNode(Graph *&graph, string ISBN, Buku *buku);
int hashFunction(string key);

// fungsi hash
int hashFunction(string key) {
    int hash = 0;
    for (char c : key) {
        hash = (hash + c) % TABLE_SIZE;
    }
    return hash;
}

// fungsi memasukkan user ke hash table.
void insertUser(string username, string password, bool isAdmin) {
    int index = hashFunction(username);
    Pengguna *newUser = new Pengguna{username, password, isAdmin, nullptr};
    if (!hashTable[index]) {
        hashTable[index] = newUser;
    } else {
        Pengguna *temp = hashTable[index];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newUser;
    }
}

Pengguna* searchUser(string username, string password) {
    int index = hashFunction(username);
    Pengguna *temp = hashTable[index];
    while (temp) {
        if (temp->username == username && temp->password == password) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void tambahGraphNode(Graph *&graph, string ISBN, Buku *buku);

// ini fungsi tambah buku, tpi lebih ke metodenya...
void tambahBuku(string judul, string penulis, int tahun, string genre, string ISBN, bool status, int jumlah) {
    Buku *bukuBaru = new Buku{judul, penulis, tahun, genre, ISBN, status, jumlah, nullptr, nullptr};

    // Menambahkan buku baru ke dalam daftar buku
    if (!headBuku) {
        headBuku = bukuBaru;
        headBuku->next = headBuku;
        headBuku->prev = headBuku;
    } else {
        Buku *temp = headBuku;
        while (temp->next != headBuku) {
            temp = temp->next;
        }
        temp->next = bukuBaru;
        bukuBaru->prev = temp;
        bukuBaru->next = headBuku;
        headBuku->prev = bukuBaru;
    }

    // Menambahkan buku baru ke dalam pohon judul buku
    insertBuku(rootBuku, bukuBaru);

    // Menambahkan buku baru ke dalam grafik buku
    tambahGraphNode(bookGraph, ISBN, bukuBaru);
}

void tambahTransaksi(string username, string ISBN, string tanggalPinjam, string tanggalKembali) {
    Transaksi *transaksiBaru = new Transaksi{username, ISBN, tanggalPinjam, tanggalKembali, headTransaksi};
    headTransaksi = transaksiBaru;
}

void insertBuku(TreeNode *&root, Buku *buku) {
    if (!root) {
        root = new TreeNode{buku, nullptr, nullptr};
    } else if (buku->judul < root->buku->judul) {
        insertBuku(root->left, buku);
    } else {
        insertBuku(root->right, buku);
    }
}

void tambahGraphNode(Graph *&graph, string ISBN, Buku *buku) {
    if (!graph) {
        graph = new Graph{nullptr};
    }
    GraphNode *newNode = new GraphNode{ISBN, nullptr, buku};
    newNode->next = graph->head;
    graph->head = newNode;
}

Buku* cariBuku(string judul) {
    Buku *temp = headBuku;
    do {
        if (temp->judul == judul) {
            return temp;
        }
        temp = temp->next;
    } while (temp != headBuku);
    return nullptr;
}

// fungsi tambah buku admin
void tambahBukuAdmin() {
    string judul, penulis, genre, ISBN;
    int tahun, jumlah;
    bool status = false; // Awalnya status buku selalu tersedia saat ditambahkan

    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, judul);
    cout << "Masukkan penulis buku: ";
    getline(cin, penulis);
    cout << "Masukkan tahun terbit buku: ";
    cin >> tahun;
    cout << "Masukkan genre buku: ";
    cin.ignore();
    getline(cin, genre);
    cout << "Masukkan ISBN buku: ";
    getline(cin, ISBN);
    cout << "Masukkan jumlah buku: ";
    cin >> jumlah;

    tambahBuku(judul, penulis, tahun, genre, ISBN, status, jumlah);
    cout << "Buku berhasil ditambahkan!" << endl;
}

void ubahDataBuku() {
    string judul;
    cout << "Masukkan judul buku yang ingin diubah: ";
    cin.ignore();
    getline(cin, judul);
    Buku *buku = cariBuku(judul);
    if (buku) {
        cout << "Masukkan data baru untuk buku '" << judul << "':" << endl;
        string newJudul, newPenulis, newGenre, newISBN;
        int newTahun, newJumlah;
        
        cout << "Judul: ";
        getline(cin, newJudul);
        cout << "Penulis: ";
        getline(cin, newPenulis);
        cout << "Tahun Terbit: ";
        cin >> newTahun;
        cout << "Genre: ";
        cin.ignore();
        getline(cin, newGenre);
        cout << "ISBN: ";
        getline(cin, newISBN);
        cout << "Jumlah: ";
        cin >> newJumlah;
        
        // Update data buku
        buku->judul = newJudul;
        buku->penulis = newPenulis;
        buku->tahun = newTahun;
        buku->genre = newGenre;
        buku->ISBN = newISBN;
        buku->jumlah = newJumlah;
        
        cout << "Data buku berhasil diubah!" << endl;
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }
}

// fungsi hapus buku oleh admin.
void hapusBukuAdmin() {
    string judul;
    cout << "Masukkan judul buku yang ingin dihapus: ";
    cin.ignore();
    getline(cin, judul);
    hapusBuku(judul);
}

void hapusBuku(string judul) {
    Buku *bukuDihapus = cariBuku(judul);
    if (bukuDihapus) {
        if (bukuDihapus == headBuku && headBuku->next == headBuku) {
            delete bukuDihapus;
            headBuku = nullptr;
        } else {
            bukuDihapus->prev->next = bukuDihapus->next;
            bukuDihapus->next->prev = bukuDihapus->prev;
            if (bukuDihapus == headBuku) {
                headBuku = bukuDihapus->next;
            }
            delete bukuDihapus;
        }
        cout << "Buku berhasil dihapus!" << endl;
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }
}

// fungsi lihat daftar buku (admin)
void lihatDaftarBukuAdmin() {
    // Tampilkan header tabel
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "| No |       Judul       |       Penulis       | Tahun |      Genre      |     ISBN     | Status | Jumlah |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    
    if (!headBuku) {
        cout << "Tidak ada buku dalam daftar." << endl;
        return;
    }
    
    Buku *temp = headBuku;
    int nomor = 1;

    do {
        // Tampilkan data buku dalam tabel
        cout << "| " << setw(3) << nomor++ << " | " << setw(17) << temp->judul << " | "
             << setw(19) << temp->penulis << " | " << setw(5) << temp->tahun << " | "
             << setw(15) << temp->genre << " | " << setw(12) << temp->ISBN << " | "
             << setw(7) << (temp->status ? "Dipinjam" : "Tersedia") << " | "
             << setw(6) << temp->jumlah << " |" << endl;
        temp = temp->next;
    } while (temp != headBuku);
}

// fungsi lihat daftar buku (user)
void lihatDaftarBukuUser() {
    // Tampilkan header tabel
    cout << "------------------------------------------------------------------------" << endl;
    cout << "| No |       Judul       |       Penulis       | Tahun |      Genre      | Status |" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    if (!headBuku) {
        cout << "Tidak ada buku dalam daftar." << endl;
        return;
    }
    Buku *temp = headBuku;
        int nomor = 1;

        do {
            // Tampilkan data buku dalam tabel
            cout << "| " << setw(3) << nomor++ << " | " << setw(17) << temp->judul << " | "
                 << setw(19) << temp->penulis << " | " << setw(5) << temp->tahun << " | "
                 << setw(15) << temp->genre << " | " << setw(7) << (temp->status ? "Dipinjam" : "Tersedia") << " |" << endl;

            temp = temp->next;
        } while (temp != headBuku);
        cout << "------------------------------------------------------------------------" << endl;

}

// fungsi pinjam buku, connected by ISBN buku
void pinjamBuku(string username) {
    string judul;
    cout << "Masukkan judul buku yang ingin dipinjam: ";
    cin.ignore();
    getline(cin, judul);
    Buku *buku = cariBuku(judul);
    if (buku && buku->jumlah > 0 && !buku->status) {
        buku->status = true;
        buku->jumlah--;
        string tanggalPinjam, tanggalKembali;
        cout << "Masukkan tanggal pinjam (DD/MM/YYYY): ";
        getline(cin, tanggalPinjam);
        cout << "Masukkan tanggal kembali (DD/MM/YYYY): ";
        getline(cin, tanggalKembali);
        tambahTransaksi(username, buku->ISBN, tanggalPinjam, tanggalKembali);
        cout << "Buku berhasil dipinjam!" << endl;
    } else {
        cout << "Buku tidak tersedia untuk dipinjam." << endl;
    }
}

// arezyh.s
// fungsi mengembalikan buku yang dipinjam.
void kembalikanBuku() {
    string judul;
    cout << "Masukkan judul buku yang ingin dikembalikan: ";
    cin.ignore();
    getline(cin, judul);
    Buku *buku = cariBuku(judul);
    if (buku && buku->status) {
        buku->status = false;
        buku->jumlah++;
        cout << "Buku berhasil dikembalikan!" << endl;
    } else {
        cout << "Buku tidak sedang dipinjam." << endl;
    }
}

TreeNode* cariBukuTree(TreeNode *root, string judul) {
    if (!root) return nullptr;
    if (root->buku->judul == judul) return root;
    if (root->buku->judul > judul) return cariBukuTree(root->left, judul);
    return cariBukuTree(root->right, judul);
}

void cariBukuBinarySearch() {
    string judul;
    cout << "Masukkan judul buku yang dicari: ";
    cin.ignore();
    getline(cin, judul);
    TreeNode *result = cariBukuTree(rootBuku, judul);
    if (result) {
        Buku *buku = result->buku;
        cout << "Buku ditemukan!" << endl;
        cout << "------------------------------------" << endl;
        cout << "Judul: " << buku->judul << endl;
        cout << "Penulis: " << buku->penulis << endl;
        cout << "Tahun: " << buku->tahun << endl;
        cout << "Genre: " << buku->genre << endl;
        cout << "ISBN: " << buku->ISBN << endl;
        cout << "Jumlah: " << buku->jumlah << endl;
        cout << "Status: " << (buku->status ? "Dipinjam" : "Tersedia") << endl;
        cout << "------------------------------------" << endl;
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }
}

// fungsi melihat daftar riwayat transaksi yang terjadi
void lihatDaftarTransaksi() {
    Transaksi *temp = headTransaksi;
    if (!temp) {
        cout << "Tidak ada transaksi." << endl;
        return;
    }
    
    // Tampilkan header tabel
    cout << "-------------------------------------------------" << endl;
    cout << "| No |  Username  |     ISBN     | Pinjam | Kembali |" << endl;
    cout << "-------------------------------------------------" << endl;

    int nomor = 1;
    while (temp) {
        // Tampilkan data transaksi dalam tabel
        cout << "| " << setw(2) << nomor++ << " | " << setw(10) << temp->username << " | "
             << setw(12) << temp->ISBN << " | " << setw(6) << temp->tanggalPinjam << " | "
             << setw(7) << temp->tanggalKembali << " |" << endl;
        temp = temp->next;
    }
    cout << "-------------------------------------------------" << endl;
}

// arezyhs
// sorting bubble sort mengurutkan buku by abjad a - z
void urutkanBukuByAbjad(Buku* bukuAbjad[]) {
    // Pengurutan menggunakan bubble sort
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26 - i - 1; ++j) {
            // Jika tidak ada buku untuk huruf ke-j, lewati iterasi ini
            if (!bukuAbjad[j]) continue;
            // Jika tidak ada buku untuk huruf ke-(j+1), lewati iterasi ini
            if (!bukuAbjad[j + 1]) continue;

            // Bandingkan judul buku untuk urutan abjad
            if (bukuAbjad[j]->judul > bukuAbjad[j + 1]->judul) {
                // Tukar posisi buku dalam array
                Buku* temp = bukuAbjad[j];
                bukuAbjad[j] = bukuAbjad[j + 1];
                bukuAbjad[j + 1] = temp;
            }
        }
    }
}

void lihatDaftarBukuByAbjad() {
    system("cls");
    // array untuk menyimpan daftar buku berdasarkan abjad
    BukuAbjad* bukuAbjad[26] = {nullptr};

    // Memisahkan buku berdasarkan huruf pertama judulnya
    Buku *temp = headBuku;
    do {
        char hurufPertama = temp->judul[0];
        hurufPertama = toupper(hurufPertama); // Mengubah huruf pertama menjadi huruf kapital

        // Menambahkan buku ke dalam linked list sesuai dengan huruf pertamanya
        if (hurufPertama >= 'A' && hurufPertama <= 'Z') {
            BukuAbjad* bukuNode = new BukuAbjad;
            bukuNode->head = temp;
            bukuNode->next = nullptr;

            // Menambahkan node ke dalam linked list bukuAbjad[hurufPertama - 'A']
            if (!bukuAbjad[hurufPertama - 'A']) {
                bukuAbjad[hurufPertama - 'A'] = bukuNode;
            } else {
                BukuAbjad* current = bukuAbjad[hurufPertama - 'A'];
                while (current->next) {
                    current = current->next;
                }
                current->next = bukuNode;
            }
        }
        temp = temp->next;
    } while (temp != headBuku);

    // Pengurutan dapat dilakukan di dalam setiap linked list di bukuAbjad
    // Menampilkan daftar buku berdasarkan abjad
    cout << "Daftar Buku Berdasarkan Abjad" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "| No |       Judul       |       Penulis       | Tahun |      Genre      | Status |" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    // Tampilkan data buku berdasarkan abjad
    for (int i = 0; i < 26; ++i) {
        BukuAbjad* current = bukuAbjad[i];
        while (current) {
            Buku* buku = current->head;
            cout << "| " << setw(3) << (i + 1) << " | " << setw(17) << buku->judul << " | "
                 << setw(19) << buku->penulis << " | " << setw(5) << buku->tahun << " | "
                 << setw(15) << buku->genre << " | " << setw(7) << (buku->status ? "Dipinjam" : "Tersedia") << " |" << endl;
            current = current->next;
        }
    }
    cout << "------------------------------------------------------------------------" << endl;
}

// fungsi tampilan menu adm00n
void adminMenu() {
    int choice;
    do {
        cout << "===    E - Pusnas    ===" << endl;
        cout << "===     (Admin)      ===" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Ubah Data Buku" << endl;
        cout << "3. Hapus Buku" << endl;
        cout << "4. Lihat Daftar Buku" << endl;
        cout << "5. Lihat Daftar Transaksi" << endl;
        cout << "6. Cari Buku" << endl;
        cout << "0. Logout" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tambahBukuAdmin();
                break;
            case 2:
                ubahDataBuku();
                break;
            case 3:
                hapusBukuAdmin();
                break;
            case 4:
                lihatDaftarBukuAdmin();
                break;
            case 5:
                lihatDaftarTransaksi();
                break;
            case 6:
                cariBukuBinarySearch();
                break;
            case 0:
                cout << "Logout berhasil." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 0);
}

// fungsi tampilan menu user
void userMenu() {
    int choice;
    do {
        cout << "===    E - Pusnas    ===" << endl;
        cout << "===      (User)      ===" << endl;
        cout << "1. Cari Buku" << endl;
        cout << "2. Lihat Daftar Buku" << endl;
        cout << "3. Lihat Daftar Buku A - Z" << endl;
        cout << "4. Pinjam Buku" << endl;
        cout << "5. Kembalikan Buku" << endl;
        cout << "0. Logout" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cariBukuBinarySearch();
                break;
            case 2:
                lihatDaftarBukuUser();
                break;
            case 3:
                lihatDaftarBukuByAbjad();
                break;
            case 4:
                pinjamBuku(username);
                break;
            case 5:
                kembalikanBuku();
                break;
            case 0:
                cout << "Logout berhasil." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 0);
}

void login() {
    string usernameInput, passwordInput;
    cout << "Username: ";
    cin >> usernameInput;
    cout << "Password: ";
    cin >> passwordInput;

    Pengguna *user = searchUser(usernameInput, passwordInput);
    if (user) {
        username = usernameInput;
        if (user->isAdmin) {
            adminMenu();
        } else {
            userMenu();
        }
    } else {
        cout << "Username atau password salah. Silakan coba lagi." << endl;
    }
}

void registerUser() {
    string newUsername, newPassword;
    char isAdminInput;
    bool isAdmin;

    cout << "=== Registrasi Pengguna Baru ===" << endl;
    cout << "Masukkan username: ";
    cin >> newUsername;

    // Periksa apakah username sudah digunakan
    if (searchUser(newUsername, "") != nullptr) {
        cout << "Username sudah digunakan. Silakan gunakan username lain." << endl;
        return;
    }

    cout << "Masukkan password: ";
    cin >> newPassword;
    cout << "Apakah pengguna merupakan admin? (y/n): ";
    cin >> isAdminInput;

    isAdmin = (isAdminInput == 'y' || isAdminInput == 'Y');

    // Tambahkan pengguna baru ke dalam hash table
    insertUser(newUsername, newPassword, isAdmin);

    cout << "Registrasi berhasil!" << endl;
}

int main() {
    system("cls");
    // username + pass default utk login
    insertUser("admin", "admin123", true);
    insertUser("user", "user123", false);

    // data buku untuk dimasukkan di awal jalannya program.
    tambahBuku("Faust", "Van Goethe", 2001, "Literatur", "ISBN001", false, 1);
    tambahBuku("Pemrograman C++", "Sugeng", 2012, "Non-Fiksi", "ISBN002", false, 4);
    tambahBuku("Crime&Punishment", "Fyodor Dovtoyetsky", 1984, "Fiksi", "ISBN003", false, 3);
    tambahBuku("Biografi Soeharto", "Ahmad", 2020, "Biografi", "ISBN004", false, 2);
    tambahBuku("The Divine Comedy", "Dante", 1900, "Literatur", "ISBN005", false, 2);
    tambahBuku("Komedi Putar", "Akbar", 2002, "Horror", "ISBN006", true, 1);
    tambahBuku("Lalaland 1984", "Agus", 2023, "Fiksi", "ISBN007", false, 1);
    tambahBuku("Zombie Saga 2000", "Bayu", 2023, "Fiksi", "ISBN008", false, 1);
    tambahBuku("Zoro Adventure", "Sitohang", 2023, "Fiksi", "ISBN009", false, 1);

    int choice;
    do {
        cout << "=== Sistem Manajemen Perpustakaan ===" << endl;
        cout << "===         E - Pusnas            ===" << endl;
        cout << endl;
        cout << "       1. Login" << endl;
        cout << "       2. Registrasi (Member Baru)" << endl;
        cout << "       0. Keluar" << endl;
        cout << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan E-Perpustakaan." << endl;;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;;
        }
    } while (choice != 0);

    return 0;
}

// done.