#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Untuk menyimpan informasi buku
struct Buku {
    string judul;
    string pengarang;
    int jumlah;
    double harga;
};

// Untuk menyimpan informasi alat tulis
struct AlatTulis {
    string nama;
    string jenis;
    int jumlah;
    double harga;
};

// Untuk menampilkan daftar buku
void tampilkanDaftarBuku(Buku *buku, int jumlahBuku) {
    cout << "===============================================================================" << endl;
    cout << "No.  Judul Buku                      Pengarang           Harga         Stok"     << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < jumlahBuku; ++i) {
        cout << left << setw(5) << i+1 << setw(32) << buku[i].judul << setw(20) << buku[i].pengarang << "Rp. " << fixed << setprecision(0) << setw(10) << buku[i].harga << setw(10) << buku[i].jumlah << endl;
    }
    cout << "===============================================================================" << endl << endl;
}

// Fungsi untuk menampilkan daftar alat tulis
void tampilkanDaftarAlatTulis(AlatTulis *alatTulis, int jumlahAlatTulis) {
    cout << "===============================================================================" << endl;
    cout << "No.  Nama Alat Tulis                 Jenis               Harga         Stok"     << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < jumlahAlatTulis; ++i) {
        cout << left << setw(5) << i+1 << setw(32) << alatTulis[i].nama << setw(20) << alatTulis[i].jenis << "Rp. " << fixed << setprecision(0) << setw(10) << alatTulis[i].harga << setw(10) << alatTulis[i].jumlah << endl;
    }
    cout << "===============================================================================" << endl << endl;
}

// Fungsi untuk melakukan pembelian buku
double beliBuku(Buku *buku, int jumlahBuku) {
    int pilihan, jumlah;
    double totalPembelian = 0.0; // Total pembelian
    // Menampilkan daftar buku
    tampilkanDaftarBuku(buku, jumlahBuku);
    cout << "Pilih buku yang ingin dibeli (0 untuk kembali): ";
    cin >> pilihan;
    // Memeriksa pilihan
    if (pilihan < 0 || pilihan > jumlahBuku) {
        cout << "Pilihan tidak valid!" << endl << endl;
        return totalPembelian;
    }
    if (pilihan == 0)
        return totalPembelian;
    cout << "Masukkan jumlah buku yang ingin dibeli: ";
    cin >> jumlah;
    // Memeriksa jumlah buku yang valid
    if (jumlah <= 0) {
        cout << "Jumlah buku tidak valid!" << endl << endl;
        return totalPembelian;
    }
    // Memeriksa stok buku
    if (buku[pilihan - 1].jumlah < jumlah) {
        cout << "Stok tidak mencukupi!" << endl << endl;
        return totalPembelian;
    }
    // Menghitung total harga
    double hargaTotal = jumlah * buku[pilihan - 1].harga;
    cout << "Total harga untuk buku " << buku[pilihan - 1].judul << ": Rp. " << fixed << setprecision(0) << hargaTotal << endl << endl;
    totalPembelian += hargaTotal; // Menambahkan total harga pembelian
    // Mengurangi stok buku
    buku[pilihan - 1].jumlah -= jumlah;

    return totalPembelian;
}

// Fungsi untuk melakukan pembelian alat tulis
double beliAlatTulis(AlatTulis *alatTulis, int jumlahAlatTulis) {
    int pilihan, jumlah;
    double totalPembelian = 0.0; // Total pembelian
    // Menampilkan daftar alat tulis
    tampilkanDaftarAlatTulis(alatTulis, jumlahAlatTulis);
    cout << "Pilih alat tulis yang ingin dibeli (0 untuk kembali): ";
    cin >> pilihan;
    // Memeriksa pilihan
    if (pilihan < 0 || pilihan > jumlahAlatTulis) {
        cout << "Pilihan tidak valid!" << endl << endl;
        return totalPembelian;
    }
    if (pilihan == 0)
        return totalPembelian;
    cout << "Masukkan jumlah alat tulis yang ingin dibeli: ";
    cin >> jumlah;
    // Memeriksa jumlah alat tulis yang valid
    if (jumlah <= 0) {
        cout << "Jumlah alat tulis tidak valid!" << endl << endl;
        return totalPembelian;
    }
    // Memeriksa stok alat tulis
    if (alatTulis[pilihan - 1].jumlah < jumlah) {
        cout << "Stok tidak mencukupi!" << endl << endl;
        return totalPembelian;
    }
    // Menghitung total harga
    double hargaTotal = jumlah * alatTulis[pilihan - 1].harga;
    cout << "Total harga untuk " << alatTulis[pilihan - 1].nama << ": Rp. " << fixed << setprecision(0) << hargaTotal << endl << endl;
    totalPembelian += hargaTotal; // Menambahkan total harga pembelian
    // Mengurangi stok alat tulis
    alatTulis[pilihan - 1].jumlah -= jumlah;

    return totalPembelian;
}

int main() {
    // Maksimum buku yang dapat disimpan
    const int MAKS_BUKU = 10;
    // Membuat array pointer buku
    Buku *buku = new Buku[MAKS_BUKU];

    // Inisialisasi beberapa buku
    buku[0] = {"Harry Potter", "J.K. Rowling", 10, 100000.0};
    buku[1] = {"Lord of the Rings", "J.R.R. Tolkien", 15, 150000.0};
    buku[2] = {"To Kill a Mockingbird", "Harper Lee", 8, 80000.0};
    buku[3] = {"1984", "George Orwell", 12, 90000.0};
    buku[4] = {"The Great Gatsby", "F. Scott Fitzgerald", 7, 95000.0};
    buku[5] = {"Pride and Prejudice", "Jane Austen", 20, 75000.0};
    buku[6] = {"The Catcher in the Rye", "J.D. Salinger", 9, 85000.0};
    buku[7] = {"Brave New World", "Aldous Huxley", 11, 110000.0};
    buku[8] = {"The Hobbit", "J.R.R. Tolkien", 18, 130000.0};
    buku[9] = {"Animal Farm", "George Orwell", 13, 70000.0};

    int jumlahBuku = 10;

    // Maksimum alat tulis yang dapat disimpan
    const int MAKS_ALAT_TULIS = 7;
    // Membuat array pointer alat tulis
    AlatTulis *alatTulis = new AlatTulis[MAKS_ALAT_TULIS];

    // Inisialisasi beberapa alat tulis
    alatTulis[0] = {"Pensil", "Alat Tulis", 30, 5000.0};
    alatTulis[1] = {"Penghapus", "Alat Tulis", 20, 3000.0};
    alatTulis[2] = {"Penggaris", "Alat Tulis", 25, 7000.0};
    alatTulis[3] = {"Buku Tulis", "Kertas", 40, 10000.0};
    alatTulis[4] = {"Pensil Warna", "Alat Tulis", 15, 10000.0};
    alatTulis[5] = {"Spidol", "Alat Tulis", 20, 8000.0};
    alatTulis[6] = {"Stabilo", "Alat Tulis", 10, 12000.0};

    int jumlahAlatTulis = 7;

    int pilihan;
    double totalPembelian = 0.0;
    // Loop utama program
    do {
        cout << "===============================================================================" << endl;
        cout << "                        Selamat datang di Toko Buku SahabatKita                " << endl;
        cout << "===============================================================================" << endl;
        cout << "Menu:" << endl;
        cout << "1. Tampilkan Daftar Buku" << endl;
        cout << "2. Beli Buku" << endl;
        cout << "3. Tampilkan Daftar Alat Tulis" << endl;
        cout << "4. Beli Alat Tulis" << endl;
        cout << "5. Beli Keduanya" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        // Memproses pilihan pengguna
        switch(pilihan) {
            case 1:
                // Menampilkan daftar buku
                tampilkanDaftarBuku(buku, jumlahBuku);
                break;
            case 2:
                // Memproses pembelian buku
                totalPembelian += beliBuku(buku, jumlahBuku);
                break;
            case 3:
                // Menampilkan daftar alat tulis
                tampilkanDaftarAlatTulis(alatTulis, jumlahAlatTulis);
                break;
            case 4:
                // Memproses pembelian alat tulis
                totalPembelian += beliAlatTulis(alatTulis, jumlahAlatTulis);
                break;
            case 5:
                // Memproses pembelian kedua-duanya
                totalPembelian += beliBuku(buku, jumlahBuku);
                totalPembelian += beliAlatTulis(alatTulis, jumlahAlatTulis);
                break;
            case 0:
                cout << endl << "Total pembelian: Rp. " << fixed << setprecision(0) << totalPembelian << endl;
                cout << "Terima kasih telah berkunjung! Have a nice day :)" << endl << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl << endl;
        }
    } while (pilihan != 0);

    cout << "Program ini dibuat oleh : ";
    cout << "\nNama  : Indira Ayu Anggraeni" << endl;
    cout << "NPM   : 2310631170021" << endl;
    cout << "kelas : 2C-Informatika" << endl;
    cout << endl;

    // Menghapus memori yang dialokasikan
    delete[] buku;
    delete[] alatTulis;

    return 0;
}

