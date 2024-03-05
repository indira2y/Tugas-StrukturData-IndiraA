#include <iostream>
#include <iomanip>

using namespace std;

const int MIN_TANGGAL = 5; // konstanta yang mendefinisikan jumlah minimal hari yaitu minimal 5 hari.
const int MAX_NAMA_BARANG = 50; // konstanta yang mendefinisikan panjang maksimal untuk nama barang.

struct DataBarang {
    string nama;
    int jumlah;
    int tanggal;
    int kode;
};

//membuat fungsi'garis()' untuk mencetak garis horizontal menggunakan karakter '=' sebanyak 70 kali.
void garis()
{
    for (int i = 0; i < 70; i++){
        cout << "=";
    }
}

int main(){
    int jumlahinput; // Menyimpan jumlah data barang yang akan dimasukkan oleh pengguna.
    cout << "Masukkan jumlah barang yang di inginkan : ";
    cin >> jumlahinput;

    int jumlahtanggal; // Menyimpan tanggal terakhir pengguna.
    cout << "Masukkan tanggal : ";
    cin >> jumlahtanggal;

    DataBarang dataBarang[MIN_TANGGAL * jumlahinput];

    // sebuah loop 'for' yang akan meminta pengguna untuk memasukkan nama barang sebanyak 'jumlahinput'.
    for (int i = 0; i < jumlahinput; ++i){
        cout << "Masukkan nama barang ke-" << i+1 <<  " : ";
        cin >> dataBarang[i].nama;
    }

    cout << endl;

    for(int i=0; i < jumlahtanggal; ++i){
        cout << "Tanggal ke-" << i+1 << endl;

        garis ();
        cout << endl;

    // loop ini mengumpulkan jumlah barang yang berbeda untuk setiap tanggal.
    for (int j = 0; j < jumlahinput; ++j){
        cout << "Masukkan jumlah " << dataBarang[j].nama << " tanggal " << i+1 << " : ";
        cin >> dataBarang[j * jumlahtanggal + i].jumlah;
        dataBarang[j * jumlahtanggal + i].tanggal = i + 1;

        cout << endl;
        }

    }
    garis(); // memanggil fungsi 'garis()' untuk mencetak garis pemisah.
    cout << endl;

    cout << "\t\t\tTabel data barang" << endl;
    garis();
    cout << endl;
    cout << setw(7) << "tanggal"; // Mencetak header 'tanggal' dengan lebar kolom 7 karakter menggunakan 'setw'.

    // loop untuk mencetak nama barang.
    for (int i = 0; i < jumlahinput; i++){
        cout << setw(15) << dataBarang[i].nama; // setiap nama barang dicetak dengan lebar kolom 15 karakter.
    }

    cout << endl;

    // loop untuk mencetak jumlah barang di setiap tanggal nya.
    for (int i = 0; i < jumlahtanggal; i++){
        cout << setw(4) << i+1;
        for(int j = 0; j < jumlahinput; j++){
            cout << setw(15) << dataBarang[j * jumlahtanggal + i].jumlah;
        }
        cout << endl;
    }

    garis();
    cout << endl;

    while (true){ // Digunakan untuk mencari detail barang berdasarkan tanggal dan kode barang yang dimasukkan oleh pengguna.

    int kodeBarangCari; // mendeklarasikan sebuah variabel yang akan digunakan untuk menyimpan kode barang.
    int caritanggalbarang;  // mendeklarasikan sebuah variabel yang akan digunakan untuk menyimpan tanggal barang.

    cout << "\nMasukkan tanggal dan kode barang untuk mencari detail barang" << endl;
    cout << "Masukkan tanggal     : ";
    cin >> caritanggalbarang;
    cout << "Masukkan kode barang : ";
    cin >> kodeBarangCari;

    garis();
    // Pengondisian untuk memeriksa apakah kode barang yang dimasukkan oleh pengguna valid.
    if (kodeBarangCari >= 0 && kodeBarangCari < jumlahinput * jumlahtanggal) {
        cout << "\nDetail Barang"; // mencetak 'detail barang'.
        cout << "\nData Tanggal  : " << caritanggalbarang;
        cout << "\nNama Barang   : " << dataBarang[kodeBarangCari].nama;
        cout << "\nAlamat Barang : " << &dataBarang[kodeBarangCari];
        cout << endl;

    garis();
    cout << endl;
    }
    else {
        cout << "Detail barang tidak ditemukan. Kode barang tidak valid." << endl;
    }
    char jawaban; //Mendeklarasikan sebuah variabel 'jawaban' sebagai karakter
        cout << "Apakah Anda ingin mencari detail barang lagi? (y/n): ";
        cin >> jawaban;

        if (jawaban != 'y' && jawaban != 'Y') {
            break;
        }

    }
    cout << "\nTerima kasih telah menggunakan program ini." << endl;

    cout << "\nNama  : Indira Ayu Anggraeni";
    cout << "\nNPM   : 2310631170021";
    cout << endl;

    return 0;
}
