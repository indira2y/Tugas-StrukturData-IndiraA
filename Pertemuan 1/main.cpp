#include <iostream>

using namespace std;

int main()
{
    cout << "Masukkan jumlah Mahasiswa : 10" << endl;

  // Mendeklarasikan array string untuk menyimpan nama mahasiswa
  string namaMahasiswa[10];

  // Mendeklarasikan pointer 'y' yang menunjuk ke alamat nama mahasiswa [10]
  string *y;
  y = &namaMahasiswa[9];


  // Menggunakan looping for untuk meminta input nama mahasiswa sebanyak 10 kali
  for (int i = 0; i < 10; i++) {
    cout << "Masukkan nama mahasiswa ke-" << i+1 << " : ";
    cin >> namaMahasiswa[i];
  }

  // Menampilkan header yang berisi nama mahasiswa beserta alamatnya pada komputer
  cout << "\nNama Mahasiswa \t\tAlamat Pada Komputer" << endl;
  cout << "-----------------------------------------" << endl;

  // Menggunakan looping for untuk menampilkan nama mahasiswa dan alamatnya pada komputer
  for (int i = 0; i < 10; i++) {
    cout << namaMahasiswa[i] << "\t\t\t" << &namaMahasiswa[i] << endl;
  }
    cout << "----------------------------------------" << endl;
    cout << "\nProgram ini dibuat oleh:" << endl;
    cout << "Nama   : Indira Ayu Anggraeni" << endl;
    cout << "NPM    : 2310631170021" << endl;

    return 0;
}
