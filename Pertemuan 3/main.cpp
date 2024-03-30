#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string NPM;
    string Nama;
};

struct Nilai {
    float Absen;
    float Tugas;
    float UTS;
    float UAS;
    float NilaiAkhir;
    char NilaiHuruf;
};

int main() {
    Mahasiswa mahasiswa[20];
    Nilai nilai[20];
    int n =0, pilih, index,semua;
    string cariNPM;

    do {
        cout << "Menu Program Nilai Mahasiswa" << endl;
        cout << "1. Input Data Mahasiswa" << endl;
        cout << "2. Tampil Data Mahasiswa" << endl;
        cout << "3. Edit Data Mahasiswa" << endl;
        cout << "4. Hapus Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan jumlah mahasiswa (maks 20): ";
                cin >> n;

                for (int i = 0; i < n; i++) {
                    cout << "Data Mahasiswa ke-" << i+1 << endl;
                    cout << "NPM   : ";
                    cin >> mahasiswa[i].NPM;
                    cout << "Nama  : ";
                    cin.ignore();
                    getline(cin, mahasiswa[i].Nama);
                    cout << "Nilai Absen : ";
                    cin >> nilai[i].Absen;
                    cout << "Nilai Tugas : ";
                    cin >> nilai[i].Tugas;
                    cout << "Nilai UTS   : ";
                    cin >> nilai[i].UTS;
                    cout << "Nilai UAS   : ";
                    cin >> nilai[i].UAS;

                    // Hitung nilai akhir
                    nilai[i].NilaiAkhir = 0.1 * nilai[i].Absen + 0.2 * nilai[i].Tugas + 0.3 * nilai[i].UTS + 0.4 * nilai[i].UAS;

                    // Hitung nilai huruf
                    if (nilai[i].NilaiAkhir > 80) {
                        nilai[i].NilaiHuruf = 'A';
                    } else if (nilai[i].NilaiAkhir > 70) {
                        nilai[i].NilaiHuruf = 'B';
                    } else if (nilai[i].NilaiAkhir > 60) {
                        nilai[i].NilaiHuruf = 'C';
                    } else {
                        nilai[i].NilaiHuruf = 'D';
                    }
                }
                break;

            case 2:
                if (n == 0) {
                    cout << "Belum ada data mahasiswa." << endl;
                break;}
                cout << "1. Menampilkan data yang di pilih" << endl;
                cout << "2. Menampilkan semua data  " << endl;
                cin >> semua;
                switch (semua) {
                    case 1 :
                        cout << "Masukan NPM Mahasiswa ";
                        cin >> cariNPM;
                        cout << "Daftar Mahasiswa" << endl;
                        for (int i = 0; i < n; i++) {
                           if ( cariNPM == mahasiswa[i].NPM ){
                            cout << "Data Mahasiswa ke-" << i+1 << endl;
                            cout << "NPM   : " << mahasiswa[i].NPM << endl;
                            cout << "Nama  : " << mahasiswa[i].Nama << endl;
                            cout << "Nilai Absen : " << nilai[i].Absen << endl;
                            cout << "Nilai Tugas : " << nilai[i].Tugas << endl;
                            cout << "Nilai UTS   : " << nilai[i].UTS << endl;
                        cout << "Nilai UAS   : " << nilai[i].UAS << endl;
                        cout << "Nilai Akhir : " << nilai[i].NilaiAkhir << endl;
                        cout << "Nilai Huruf : " << nilai[i].NilaiHuruf << endl;
                           }
                    } break;
                    case 2 :
                        cout << "Daftar Mahasiswa" << endl;
                            for (int i = 0; i < n; i++) {
                                cout << "Data Mahasiswa ke-" << i+1 << endl;
                                cout << "NPM   : " << mahasiswa[i].NPM << endl;
                                cout << "Nama  : " << mahasiswa[i].Nama << endl;
                                cout << "Nilai Absen : " << nilai[i].Absen << endl;
                                cout << "Nilai Tugas : " << nilai[i].Tugas << endl;
                                cout << "Nilai UTS   : " << nilai[i].UTS << endl;
                            cout << "Nilai UAS   : " << nilai[i].UAS << endl;
                            cout << "Nilai Akhir : " << nilai[i].NilaiAkhir << endl;
                            cout << "Nilai Huruf : " << nilai[i].NilaiHuruf << endl;
                               }
                    break;

                } break;
                case 3:
                    cout << "Masukkan NPM mahasiswa yang ingin diubah: ";
                    cin >> cariNPM;

                    index = -1;
                    for (int i = 0; i < n; i++) {
                        if (mahasiswa[i].NPM == cariNPM) {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1) {
                        cout << "Data mahasiswa dengan NPM " << cariNPM << " tidak ditemukan." << endl;
                    } else {
                        cout << "Data Mahasiswa ke-" << index+1 << endl;
                        cout << "NPM   : " << mahasiswa[index].NPM << endl;
                        cout << "Nama  : " << mahasiswa[index].Nama << endl;
                        cout << "Nilai Absen : " << nilai[index].Absen << endl;
                        cout << "Nilai Tugas : " << nilai[index].Tugas << endl;
                        cout << "Nilai UTS   : " << nilai[index].UTS << endl;
                        cout << "Nilai UAS   : " << nilai[index].UAS << endl;

                        cout << "Masukkan nilai baru: " << endl;
                        cout << "Nilai Absen : ";
                        cin >> nilai[index].Absen;
                        cout << "Nilai Tugas : ";
                        cin >> nilai[index].Tugas;
                        cout << "Nilai UTS   : ";
                        cin >> nilai[index].UTS;
                        cout << "Nilai UAS   : ";
                        cin >> nilai[index].UAS;

                        // Hitung nilai akhir
                        nilai[index].NilaiAkhir = 0.1 * nilai[index].Absen + 0.2 * nilai[index].Tugas + 0.3 * nilai[index].UTS + 0.4 * nilai[index].UAS;

                        // Hitung nilai huruf
                        if (nilai[index].NilaiAkhir > 80) {
                            nilai[index].NilaiHuruf = 'A';
                        } else if (nilai[index].NilaiAkhir > 70) {
                            nilai[index].NilaiHuruf = 'B';
                        } else if (nilai[index].NilaiAkhir > 60) {
                            nilai[index].NilaiHuruf = 'C';
                        } else {
                            nilai[index].NilaiHuruf = 'D';
                        }

                        cout << "Data berhasil diubah." << endl;
                    }
                    break;

                case 4:
                    cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
                    cin >> cariNPM;

                    index = -1;
                    for (int i = 0; i < n; i++) {
                        if (mahasiswa[i].NPM == cariNPM) {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1) {
                        cout << "Data mahasiswa dengan NPM " << cariNPM << " tidak ditemukan." << endl;
                    } else {
                        for (int i = index; i < n-1; i++) {
                            mahasiswa[i] = mahasiswa[i+1];
                            nilai[i] = nilai[i+1];
                        }

                        n--;

                        cout << "Data berhasil dihapus";
                    }
                    break;

                default:
                    cout << "Terima Kasih " << endl;
                    break;
            }

    cout << "\nNama  : Indira Ayu Anggraeni" << endl;
    cout << "NPM   : 2310631170021" << endl;
    cout << "kelas : 2C-Informatika" << endl;
    cout << endl;

        } while (pilih != 5);
return 0;
}
