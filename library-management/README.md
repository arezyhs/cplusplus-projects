# Praktikum Rekursif, Sorting, Searching, Collision Handling, Tree, Graph, dan Hash Table

1. **RECURSIVE**
   - Fungsi `cariBukuTree` menggunakan rekursi untuk mencari buku di dalam struktur Binary Tree. Perlu rekursi karena struktur Binary Tree yang bersifat hirarkis, di mana setiap node dapat memiliki child(?!) di sisi kiri dan kanan. Dengan menggunakan rekursi, fungsi dapat menelusuri setiap node pada Tree dengan efisien, mulai dari root, dan terus memeriksa node lain hingga buku yang dicari ditemukan atau semua kemungkinan telah diperiksa.

2. **SORTING**
   - Fungsi `urutkanBukuByAbjad` menggunakan algoritma BUBBLE SORT untuk mengurutkan daftar buku berdasarkan judul secara alfabetis (A - Z). Pengurutan diperlukan untuk menyajikan daftar buku dengan teratur dan memudahkan pencarian berdasarkan abjad. Algoritma Bubble Sort dipilih karena SEDERHANA, mudah diimplementasikan dan efisien untuk jumlah data yang tidak terlalu besar!!!!.

3. **SEARCHING**
   - Fungsi `cariBukuTree` dan `cariBukuBinarySearch` memanfaatkan struktur Binary Tree untuk mencari buku secara efisien. Struktur Binary Tree memungkinkan pencarian dengan kompleksitas waktu yang lebih baik (O(log n)) dibandingkan pencarian linear (O(n)). Dengan cara membandingkan judul buku yang dicari dengan judul pada setiap node, pencarian dapat dilakukan dengan memotong setengah ruang pencarian pada setiap iterasi.
   - Fungsi `cariBuku` mencari buku dalam Linked List secara linear. Pencarian linear diperlukan karena Linked List tidak terstruktur seperti Pohon Biner, sehingga harus memeriksa setiap node satu per satu.

4. **COLLISION HANDLING**
   - Dalam implementasi Hash Table untuk menyimpan data pengguna, digunakan teknik Separate Chaining (Linked List) untuk menangani benturan (dua atau lebih kunci hash yang sama). Ketika terjadi Collision, pengguna baru akan ditambahkan ke dalam Linked List pada indeks yang sama dalam Hash Table. Teknik ini dipilih karena mudah diimplementasikan dan efisien untuk jumlah data yang tidak terlalu besar.

5. **TREE (??????????????)**
   - Struktur `TreeNode` dan fungsi `insertBuku` digunakan untuk menyimpan dan memasukkan data buku ke dalam struktur Pohon Biner. Struktur Pohon Biner dipilih karena memungkinkan pencarian dan pengurutan data yang efisien berdasarkan judul buku.

6. **GRAF**
   - Struktur `GraphNode` dan `Graph`, serta fungsi `tambahGraphNode`, digunakan untuk menyimpan data buku beserta relasi antar buku berdasarkan ISBN. Struktur Graf dipilih karena dapat merepresentasikan hubungan antar buku secara fleksibel, di mana setiap buku dapat terhubung dengan buku-buku lain melalui ISBN.

7. **HASH TABLE**
   - Implementasi Tabel Hash menggunakan array `hashTable`, fungsi `hashFunction`, `insertUser`, dan `searchUser` digunakan untuk menyimpan dan mengakses data pengguna secara efisien. Tabel Hash dipilih karena memungkinkan pencarian, penyisipan, dan penghapusan data dengan kompleksitas waktu yang baik (rata-rata O(1)) jika fungsi hash yang digunakan cukup baik.

Setiap fungsi dan struktur data yang digunakan dalam kode dipilih dan diimplementasikan dengan tujuan memenuhi kebutuhan spesifik dari ~PRAKTIKUM~ aplikasi manajemen perpustakaan, seperti efisiensi pencarian buku, pengurutan daftar buku, manajemen data pengguna, dan representasi relasi antar buku. 
